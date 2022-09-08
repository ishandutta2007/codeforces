#include <map>
#include <set>
#include <stack>
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

int n, a[55][55];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; n; ++i) {
        int f = 3;
        if (i == 0) ++f;
        for (int j = 0; j < f && n; ++j) {
            a[i][j] = 1;
            --n;
        }
        if (i) {
            if (a[i][2]) {
                a[i][2] = 0;
                a[i][3] = 1;
            }
        }
    }
    cout << "+------------------------+" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "|";
        for (int j = 0; j < 11; ++j) {
            if (a[j][i]) {
                cout << "O.";
            } else {
                if (i == 2 && j) cout << "..";
                else cout << "#.";
            }
        }
        if (i == 2) cout << "..";
        else if (i == 0) cout << "|D";
        else cout << "|.";
        cout << "|";
        if (i == 0 || i == 3) cout << ")";
        cout << endl;
    }
    cout << "+------------------------+" << endl;
    return 0;
}