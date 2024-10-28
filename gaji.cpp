#include <iostream>
#include <iomanip>  // Untuk pengaturan tampilan tabel
#include <string>
using namespace std;

struct Karyawan {
    int nomor;
    string nama;
    char golongan;
    float gaji;
    float ppn;
    float gaber;
};

float HitungGaji(char golongan) {
    switch (golongan) {
        case 'A': return 5000000;
        case 'B': return 4500000;
        case 'C': return 4000000;
        case 'D': return 3500000;
        default: return 0;  // Pastikan ada nilai yang dikembalikan
    }
}

int main() {
    Karyawan karyawan;
    
    // Input data karyawan
    cout << "Masukkan Nomor: ";
    cin >> karyawan.nomor;
    cin.ignore();  // Mengabaikan newline setelah input nomor
    cout << "Masukkan Nama: ";
    getline(cin, karyawan.nama);
    cout << "Masukkan Golongan Gaji (A-D): ";
    cin >> karyawan.golongan;
    
    // Perhitungan gaji
    karyawan.gaji = HitungGaji(karyawan.golongan);
    if (karyawan.gaji == 0) {
        cout << "Golongan tidak valid." << endl;
        return 1;  // Keluar jika golongan tidak valid
    }
    
    karyawan.ppn = 0.1f * karyawan.gaji;  // PPN 10%
    karyawan.gaber = karyawan.gaji - karyawan.ppn;  // Gaji bersih
    
    // Menampilkan data karyawan dalam bentuk tabel
    cout << "\n--- Data Karyawan ---" << endl;
    cout << "========================================================================================\n";
    cout << left << setw(15) << "Nomor" 
         << setw(20) << "Nama" 
         << setw(10) << "Golongan" 
         << setw(15) << "Gaji" 
         << setw(15) << "PPN"
         << setw(15) << "Gaji Bersih" << endl;
         cout << "========================================================================================\n";
    
    cout << left << setw(15) << karyawan.nomor
         << setw(20) << karyawan.nama
         << setw(10) << karyawan.golongan
         << setw(15) << fixed << setprecision(2) << karyawan.gaji
         << setw(15) << fixed << setprecision(2) << karyawan.ppn
         << setw(15) << fixed << setprecision(2) << karyawan.gaber << endl;
            cout << "========================================================================================\n";
            
    	
    return 0;
}

