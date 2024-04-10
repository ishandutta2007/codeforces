#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int inf = 111111111;

const int ldx[] = {1, -1, 0, 0};
const int ldy[] = {0, 0, 1, -1};

const int kdx[] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
const int kdy[] = {0, 0, 0, 1, -1, 1, -1, 1, -1};

struct xxx {
    int x, y;
    void read() {
        char c;
        cin >> c >> y;
        x = c - 'a' + 1;
    }
    void write() {
        cout << x << ' ' << y << endl;
    }
};

bool is_in(int x, int y) {
    return x > 0 && y > 0 && x <= 8 && y <= 8;
}

int a[11][11], b[11][11];
xxx l1, l2, k1, k2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    l1.read();
    l2.read();
    k1.read();
    k2.read();

    /*l1.write();
    l2.write();
    k1.write();
    k2.write();*/
    b[l1.x][l1.y] = 2;
    b[l2.x][l2.y] = 2;
    b[k1.x][k1.y] = 2;
    //b[k2.x][k2.y] = 2;
    for (int k = 0; k < 4; ++k) {
        for (int i = l1.x + ldx[k], j = l1.y + ldy[k]; is_in(i, j); i += ldx[k], j += ldy[k]) {
            a[i][j] = 1;
            if (b[i][j] == 2) {
                break;
            }
        }
        for (int i = l2.x + ldx[k], j = l2.y + ldy[k]; is_in(i, j); i += ldx[k], j += ldy[k]) {
            a[i][j] = 1;
            if (b[i][j] == 2) {
                break;
            }
        }
    }
    for (int k = 1; k < 9; ++k) {
        int x = k1.x + kdx[k], y = k1.y + kdy[k];
        if (is_in(x, y)) {
            a[x][y] = 1;
        }
    }
    /*for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            if (b[i][j] != 2)
            cout << a[i][j];
            else cout << 2;
        }
        cout << endl;
    }*/
    for (int k = 0; k < 9; ++k) {
        int x = k2.x + kdx[k], y = k2.y + kdy[k];
        if (is_in(x, y) && a[x][y] != 1) {
            cout << "OTHER" << endl;
            return 0;
        }
    }
    cout << "CHECKMATE" << endl;
    return 0;
}