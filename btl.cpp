#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

struct khachhang {
    int makh;
    string tenkh, ngaysinh, sdt, ngaydk;
    float phigoitap, tongtien;

    void nhap() {
        cout << "Nhap ma khach hang: ";
        cin >> makh;
        while (makh < 0) {
            cout << " \nVui long nhap ma khach hang >0: ";
            cin >> makh;
        }
        cin.ignore();  // Ðe tranh loi khi nhap chuoi
        cout << "Nhap ten khach hang: ";
        getline(cin, tenkh);
        cout << "Nhap ngay sinh: ";
        getline(cin, ngaysinh);
        cout << "Nhap so dien thoai: ";
        getline(cin, sdt);
        cout << "Nhap ngay dang ky: ";
        getline(cin, ngaydk);
        cout << "Nhap phi goi tap(1 month = 350, 6 month = 2100 or 1 year = 3000): ";
        cin >> phigoitap;
        while ((phigoitap != 350) && (phigoitap != 2100) && (phigoitap != 3000)) {
            cout << " Vui long nhap lai phi goi tap: ";
            cin >> phigoitap;
        }
        tongtien = phigoitap;
    }

    void xuat() {
        cout << makh << setw(20) << tenkh << setw(21) << ngaysinh << setw(15) << sdt
             << setw(18) << ngaydk << setw(15) << phigoitap << setw(15) << tongtien << endl;
    }

    int get_makh() { 
	return makh; 
	}
    string get_tenkh() { 
	return tenkh; 
	}
	void set_tenkh(string ten) {
        tenkh = ten;
    }
    void set_ngaysinh(string ns) {
        ngaysinh = ns;
    }
    void set_sdt(string so) {
        sdt = so;
    }
    int get_tongtien() {
        return tongtien;
    }
    void set_ngaydky(string ngay) {
        ngaydk = ngay;
    }
    void set_phigoitap(int phi) {
        phigoitap = phi;
    }
};
struct qlythietbi {
    int masp, soluong;
    string tenthietbi, tinhtrang;

    void Input() {
    cout << "\nNhap ma san pham: ";
    cin >> masp;
    cin.ignore(); // Xoa bo dem
    cout << "\nNhap so luong ton kho: ";
    cin >> soluong;
    cin.ignore(); // Xoa bo dem
    cout << "\nNhap ten thiet bi: ";
    getline(cin, tenthietbi);
    cout << "\nNhap tinh trang thiet bi (new or old): ";
    getline(cin, tinhtrang);
}

    void Output(bool o) {
    	if (o){
        cout << "\nMaspham" << setw(20) << "Soluong" << setw(20) << "Tenthietbi" << setw(20) << "Tinhtrang" << endl;
    }
		cout << setw(7) << masp << setw(20) << soluong;
        cout << setw(20) << tenthietbi << setw(20) << tinhtrang;
    }

    int get_masp() {
        return masp;
    }

    void themthietbi() {
        Input();
    }

    void timkiemsp(qlythietbi tb[], int n) {
        int ma;
        int count = 0;
        cout << "\nNhap ma san pham can tim: "; cin >> ma;
      
        cout << "\nMaspham" << setw(20) << "Soluong" << setw(20) << "Tenthietbi" << setw(20) << "Tinhtrang" << endl;
        for (int i = 0; i < n; i++) {
            if (tb[i].get_masp() == ma) {
                tb[i].Output(false);
                count++;
            }
        }
        if (count == 0) {
            cout << "\nKhong tim thay ma san pham can tim";
        }
    }
    //sap xep theo masp
	int partition(qlythietbi tb[], int l, int r) {
    int mid = l + (r - l) / 2;
	int pivot = tb[r].masp; 
    int i = l - 1;
    int j = r + 1;
    // lap vo han cho den khi 1 dieu kien ben trong sai
    while (1) {
        do { i++; } while (tb[i].masp < pivot);
        do { j--; } while (tb[j].masp > pivot);
        //khi vi tri cua i < j thi swap
		if (i < j) {
            swap(tb[i].masp, tb[j].masp);
        } else {
            return j;// vi tri cua chot sau phan hoach
        }
    }
}
	void quicksort (qlythietbi tb[], int l, int r){
		if (l >= r)
		return; // ket thuc ham neu l >=r
		int new_pivot = partition (tb, l ,r);
		// de quy
		quicksort (tb, l, new_pivot-1);
		quicksort (tb, new_pivot+1, r);
	}
	// kiem tra ma sp co trung lap hay khong 
    bool isDuplicateProductCode(qlythietbi tb[], int n, int masp) {
        for (int i = 0; i < n; i++) {
            if (tb[i].get_masp() == masp) {
                return true; //ma sp da ton tai 
            }
        }
        return false; // ma san pham chua ton tai 
    }
    // them thiet bi vao danh sach va kiem tra ma trung lap 
    void themthietbi(qlythietbi tb[], int &n) {
        qlythietbi newDevice;
        int masp;

        // lap lai cho den khi nhap ma san pham hop le 
        do {
            cout << "\nNhap ma san pham: ";
            cin >> masp;

            if (isDuplicateProductCode(tb, n, masp)) {
                cout << "Ma san pham da ton tai! Vui long nhap ma san pham khac.\n";
            } else {
                break; //neu ma sp hop le, thoat vòng lap 
            }
        } while (true);

        //sau khi ma sp hop le, nhap cac thong tin con lai 
        newDevice.masp = masp;
        cin.ignore(); 
        cout << "\nNhap so luong ton kho: ";
        cin >> newDevice.soluong;
        cin.ignore(); 
        cout << "\nNhap ten thiet bi: ";
        getline(cin, newDevice.tenthietbi);
        cout << "\nNhap tinh trang thiet bi (new or old): ";
        getline(cin, newDevice.tinhtrang);

        // them tb vao danh sach 
        tb[n] = newDevice;
        n++; 
        cout << "\nThiet bi da duoc them thanh cong.\n";
    }
void qlthietbi() {
        int luachon;
        bool exit = true; 
        qlythietbi tb[100];
        int n = 0; 
        bool o = true;

        do {
            system("cls");
            cout << " \tQuan Ly Thiet Bi Phong Gym\t" << endl;
            cout << " ******   1.Nhap thiet bi                     ******" << endl;
            cout << " ******   2.Xuat thiet bi                     ******" << endl;
            cout << " ******   3.Tim kiem theo ma san pham         ******" << endl;
            cout << " ******   4.Them thiet bi moi                 ******" << endl;
            cout << " ******   5.Sap xep thiet bi theo ma san pham ******" << endl;
            cout << " ******   6.Exit                              ******" << endl; 
            cout << "\tNhap lua chon cua ban: "; cin >> luachon;
            switch (luachon) {
                case 1:
                    tb[n].Input();
                    n++;
                    cout << endl;
                    system("pause");
                    break;
                case 2:
                    o = true;
                    for (int i = 0; i < n; i++) {
                        tb[i].Output(o);
                        if (o) {
                            o = false;
                        }
                        cout << endl;
                    }
                    system("pause");
                    break;
                case 3:
                    timkiemsp(tb, n);
                    cout << endl;
                    system("pause");
                    break;
                case 4:
                    themthietbi(tb, n); 
                    system("pause");
                    break;
                case 5:
                    quicksort(tb, 0, n - 1);
                    cout << "\nSap xep thiet bi thanh cong!" << endl;
                    system("pause");
                    break;
                case 6:
                    exit = false; 
                    break;
                default:
                    cout << "Khong co du lieu ban nhap!" << endl;
                    break;
            }
        } while (exit);
    }
};

struct Node {
    khachhang gym;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void addCustomer(khachhang newGym) {
    // Kiem tra xem ma khach hang da ton tai hay chua
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->gym.get_makh() == newGym.get_makh()) {
            cout << "Khach hang co ma " << newGym.get_makh() << " da ton tai!" << endl;
            return;
        }
        temp = temp->next;
    }

    // Them khach hang moi neu ma khach hang khong ton tai
    Node* newNode = new Node;
    newNode->gym = newGym;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

    void deleteCustomer(int makh) {
        if (head == nullptr) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        if (head->gym.get_makh() == makh) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Da xoa khach hang co ma: " << makh << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->gym.get_makh() != makh) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Khach hang khong ton tai!" << endl;
        } else {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Da xoa khach hang co ma: " << makh << endl;
        }
    }

    void searchCustomerByID(int makh) {
        Node* temp = head;
        cout << "MaKH" << setw(20) << "TenKH" << setw(21) << "NgaySinh" << setw(15) << "SDT" << setw(18)
             << "Ngaydky" << setw(15) << "Phigoitap" << setw(15) << "Tongtien" << endl;
        bool found = false;
        while (temp != nullptr) {
            if (temp->gym.get_makh() == makh) {
                temp->gym.xuat();
                found = true;
                break;
            }
            temp = temp->next;
        }
        
        if (!found) {
            cout << "Khach hang khong ton tai!" << endl;
        }
    }
    
    void searchCustomerByName(const string& tenkh) {
    Node* temp = head;
    cout << "MaKH" << setw(20) << "TenKH" << setw(21) << "NgaySinh" << setw(15) << "SDT" << setw(18)
         << "Ngaydky" << setw(15) << "Phigoitap" << setw(15) << "Tongtien" << endl;
    bool found = false;

    // Duyet qua danh sach va kiem tra ten khach hang
    while (temp != nullptr) {
        if (temp->gym.get_tenkh() == tenkh) { // Gia su get_tenKH la ham de lay ten khach hang
            temp->gym.xuat();
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Khach hang khong ton tai!" << endl;
    }
}


    void displayAllCustomers() {
        if (head == nullptr) {
            cout << "Danh sach khach hang rong!" << endl;
            return;
        }
        Node* temp = head;
        cout << "\nDanh sach khach hang:\n";
        cout << "MaKH" << setw(20) << "TenKH" << setw(21) << "NgaySinh" << setw(15) << "SDT" << setw(18)
             << "Ngaydky" << setw(15) << "Phigoitap" << setw(15) << "Tongtien" << endl;

        while (temp != nullptr) {
            temp->gym.xuat();
            temp = temp->next;
        }
    }
    void addCustomerAtHead(khachhang newGym) {
    // Kiem tra xem ma khach hang da ton tai hay chua
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->gym.get_makh() == newGym.get_makh()) {
            std::cout << "Khach hang co ma " << newGym.get_makh() << " da ton tai!" << std::endl;
            return;
        }
        temp = temp->next;
    }

    // Them khach hang moi neu ma khach hang khong ton tai
    Node* newNode = new Node;
    newNode->gym = newGym;
    newNode->next = head;
    head = newNode;
}

void addCustomerAtPosition(khachhang newGym, int position) {
    if (position <= 0) {
        std::cout << "Vi tri khong hop le!" << std::endl;
        return;
    }

    // Kiem tra xem ma khach hang da ton tai hay chua
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->gym.get_makh() == newGym.get_makh()) {
            std::cout << "Khach hang co ma " << newGym.get_makh() << " da ton tai!" << std::endl;
            return;
        }
        temp = temp->next;
    }

    // Them khach hang moi neu ma khach hang khong ton tai
    Node* newNode = new Node;
    newNode->gym = newGym;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        temp = head;
        int currentPosition = 1;

        while (temp != nullptr && currentPosition < position - 1) {
            temp = temp->next;
            currentPosition++;
        }

        if (temp == nullptr) {
            std::cout << "Vi tri vuot qua so luong khach hang hien tai!" << std::endl;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

    // Ham sap xep theo ma khach hang (bubble sort)
    void sortByID() {
        if (head == nullptr) return;
        for (Node* i = head; i != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (i->gym.get_makh() > j->gym.get_makh()) {
                    swap(i->gym, j->gym);
                }
            }
        }
        cout << "Danh sach da duoc sap xep theo ma khach hang.\n";
    }
    // Ham sap xep theo tong chi phi (bubble sort)
    void sortByTotalCost() {
        if (head == nullptr) return;
        for (Node* i = head; i != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (i->gym.tongtien > j->gym.tongtien) {
                    swap(i->gym, j->gym);
                }
            }
        }
        cout << "Danh sach da duoc sap xep theo tong chi phi.\n";
    }
    // Ham sua thong tin khach hang
 void editCustomer(int makh) {
    Node* temp = head;
    bool found = false;
    
    while (temp != nullptr) {
        if (temp->gym.get_makh() == makh) {
            cout << "\nSua thong tin cua khach hang co ma: " << makh << endl;
            // Sua thong tin khach hang
            cout << "Nhap ten moi: ";
            string tenkh;
            cin.ignore();
            getline(cin, tenkh);
            temp->gym.set_tenkh(tenkh);
            
            cout << "Nhap ngay sinh moi: ";
            string ngaysinh;
            getline(cin, ngaysinh);
            temp->gym.set_ngaysinh(ngaysinh);
            
            cout << "Nhap so dien thoai moi: ";
            string sdt;
            getline(cin, sdt);
            temp->gym.set_sdt(sdt);
            
            cout << "Nhap ngay dang ky moi: ";
            string ngaydk;
            getline(cin, ngaydk);
            temp->gym.set_ngaydky(ngaydk);
            
            cout << "Nhap phi goi tap moi: ";
            float phigoitap;
            cin >> phigoitap;
            temp->gym.set_phigoitap(phigoitap);
            
            // Sau khi sua, in lai thong tin khach hang
            cout << "Thong tin khach hang sau khi sua:\n";
            temp->gym.xuat();
            
            found = true;
            break;
        }
        temp = temp->next;
    }
    
    if (!found) {
        cout << "Khong tim thay khach hang voi ma: " << makh << endl;
    }
}

};


// Ham them khach hang
void themkh(LinkedList &list) {
    khachhang newGym;
    cout << "\nNhap thong tin khach hang can them: \n";
    newGym.nhap();
    list.addCustomer(newGym);
}

// Ham xoa khach hang
void xoakh(LinkedList &list) {
    int makh;
    cout << "\nNhap ma khach hang can xoa: ";
    cin >> makh;
    list.deleteCustomer(makh);
}

// Ham tim kiem khach hang theo ma
void timkiemtheoma(LinkedList &list) {
    int makh;
    cout << "\nNhap ma khach hang can tim: ";
    cin >> makh;
    list.searchCustomerByID(makh);
}
void timkiemtheoten(LinkedList &list) {
    string tenkh;
    cout << "\nNhap ten khach hang can tim: ";
    cin.ignore();           
    getline(cin, tenkh);   
    list.searchCustomerByName(tenkh);
}
// Ham hien thi tat ca khach hang
void xuatds(LinkedList &list) {
    list.displayAllCustomers();
}

// Ham sap xep theo ma khach hang
void sapxepMaKH(LinkedList &list) {
    list.sortByID();
}
void sapxepTongChiPhi(LinkedList &list) {
    list.sortByTotalCost();
}
void themkhVaoDau(LinkedList &list) {
    khachhang newGym;
    cout << "\nNhap thong tin khach hang can them vao dau danh sach: \n";
    newGym.nhap();
    list.addCustomerAtHead(newGym);
}

void themkhVaoViTri(LinkedList &list) {
    khachhang newGym;
    int position;
    cout << "\nNhap thong tin khach hang can them vao vi tri: \n";
    newGym.nhap();
    cout << "Nhap vi tri can them: ";
    cin >> position;
    list.addCustomerAtPosition(newGym, position);
}
void menu() {
    LinkedList list;
    qlythietbi tb;
    int choice;

    do {
        system("cls");
        cout << "\tCHUONG TRINH QUAN LY PHONG GYM.\t" << endl;
        cout << "========================MENU============================\n";
        cout << "==   01. Quan ly khach hang phong gym.                  ==\n";
        cout << "==   02. Xuat danh sach khach hang.                     ==\n";
        cout << "==   03. Tim kiem theo ma khach hang.                   ==\n";
        cout << "==   04. Tim kiem ten khach hang.                       ==\n";
        cout << "==   05. Xoa thong tin khach hang.                      ==\n";
        cout << "==   06. Them thong tin khach hang.                     ==\n";
        cout << "==   07. Them thong tin khach hang vao dau danh sach.   ==\n";
        cout << "==   08. Them thong tin khach hang vao tuy vi tri.      ==\n";
        cout << "==   09. Sap xep theo ma khach hang.                    ==\n";
        cout << "==   10. Sap xep theo tong chi phi.                     ==\n";
        cout << "==   11. Quan ly thiet bi phong Gym.                    ==\n";
        cout << "==   12. Sua thong tin khach hang.                      ==\n";
        cout << "==   13. Exit.                                          ==\n";
        cout << "=========================================================\n";
        cout << " \t Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                themkh(list);
                system("pause");
                break;
            case 2:
                xuatds(list);
                system("pause");
                break;
            case 3:
                timkiemtheoma(list);
                system("pause");
                break;
           case 4:
                timkiemtheoten(list);
                system("pause");
                break;
            case 5:
                xoakh(list);
                system("pause");
                break;
            case 6:
                themkh(list);
                system("pause");
                break;
            case 7:
                themkhVaoDau(list);
                system("pause");
                break;
            case 8:
                themkhVaoViTri(list);
                system("pause");
                break;
            case 9:
                sapxepMaKH(list);
                system("pause");
                break;
            case 10:
                sapxepTongChiPhi(list);
                system("pause");
                break; 
			case 11:
                tb.qlthietbi();
                system("pause");
                break;
		    case 12:
                int makh;
                cout << "\nNhap ma khach hang can sua thong tin: ";
                cin >> makh;
                list.editCustomer(makh);
                system("pause");
                break;
            case 13:
                exit(0);
                break;
            default:
                cout << "Khong co du lieu ban nhap!" << endl;
                break;
        }
    } while (choice != 13);
}

int main() {
	system("color 9");
    menu();
    return 0;
}

