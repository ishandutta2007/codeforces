#include <iostream>
using namespace std;

bool matr[8][8];
bool palr[8][8];

int main() {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            char c; cin >> c;
            if(c == 'B') matr[i][j] = 1;
        }
    }
    int tot = 0;
    for(int i=0; i<8; i++) {
        int c1 = 0, c2 = 0;
        for(int j=0; j<8; j++) {
            c1 += (int)(matr[i][j]);
            c2 += (int)(palr[i][j]);
        }
        if(c1 == 8 && c2 != 8) {
            tot++;
            for(int j=0; j<8; j++) palr[i][j] = 1;
        }
    }
    for(int i=0; i<8; i++) {
        int c1 = 0, c2 = 0;
        for(int j=0; j<8; j++) {
            c1 += (int)(matr[j][i]);
            c2 += (int)(palr[j][i]);
        }
        if(c1 == 8 && c2 != 8) {
            tot++;
            for(int j=0; j<8; j++) palr[j][i] = 1;
        }
    }
    cout << tot << endl;
}