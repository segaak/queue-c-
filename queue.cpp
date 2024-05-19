#include <iostream>
#include <cctype>
using namespace std;

struct queue {
    char isi;
    queue *next;
};

int penuh;
queue *head = NULL, *tail = NULL, *cur, *del, *newnode;

int count() {
    if (head == NULL) {
        return 0;
    } else {
        int banyak = 1;
        cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
            banyak++;
        }
        return banyak;
    }
}

bool full() {
    return count() == penuh;
}

bool kosong() {
    return count() == 0;
}

void enqueue(char data) {
    if (full()) {
        cout << "Antrian penuh" << endl;
    } else {
        for (int i = 0; i < penuh; i++) {
        cout << "Masukkan data: ";
        cin >> data;
        data = toupper(data);  
        if (kosong()) {
            head = new queue();
            head->isi = data;
            head->next = NULL;
            tail = head;
        } else {
            newnode = new queue();
            newnode->isi = data;
            newnode->next = NULL;
            tail->next = newnode;
            tail = newnode;
        }
        }
    }
}

void dequeue() {
    if (kosong()) {
        cout << "Antrian kosong" << endl;
    } else {
        del = head;
        head = head->next;
        delete del;
        if (head == NULL) {
            tail = NULL;
        }
    }
}

void cetak() {
    if (kosong()) {
        cout << "Antrian kosong" << endl;
    } else {
        cur = head;
        while (cur != NULL) {
            cout << cur->isi << " ";
            cur = cur->next;
        }
        cout << endl;
    }
}

int main() {
    int pilih;
    char ulang;
    char data;


    do {
        system("cls");
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Cetak" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";

        cin >> pilih;

        switch (pilih) {
            case 1: {
            	cout << "Masukkan jumlah data : ";
       			cin >> penuh;
                enqueue(data);
                break;
            }
            case 2: {
                int num;
                cout << "Masukkan jumlah node yang ingin dihapus: ";
                cin >> num;
                for (int i = 0; i < num; ++i) {
                    if (!kosong()) {
                        dequeue();
                    } else {
                        cout << "Antrian sudah kosong, tidak bisa menghapus lebih banyak." << endl;
                        break;
                    }
                }
                break;
            }
            case 3:
                cetak();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
                break;
        }
        cout << "Apakah anda ingin mengulang program? (y/n) : ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}

