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

const int max_n = 100011, max_c = 27, inf = 1111111111;

int n, k;
string s;
int tail, a[max_n][max_c];

void add() {
    int poz = 0;
    for (int i = 0; i < s.length(); ++i) {
        int c = s[i] - 'a';
        if (a[poz][c] == 0) {
            ++tail;
            a[poz][c] = tail;
        }
        poz = a[poz][c];
    }
}

int fun(int poz) {
    int u[4];
    u[0] = u[1] = u[2] = u[3] = 0;
    for (int i = 0; i < max_c; ++i) {
        if (a[poz][i] != 0) {
            u[fun(a[poz][i])] = 1;
        }
    }
    int res = 3;
    if (u[0] == 0 && u[1] == 0 && u[2] == 0 && u[3] == 1){
        res = 0;
    }
    if (u[0] == 0 && u[1] == 1 && u[2] == 0) {
        res = 2;
    }
    if (u[0] == 0 && u[1] == 0 && u[2] == 1) {
        res = 1;
    }
    if (u[0] == 0 && u[1] == 0 && u[2] == 0 && u[3] == 0){
        res = 2;
    }
    //cout << poz << " " << res << endl;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    tail = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        add();
    }
    int x = fun(0);
    //cout << x << endl;
    if (x == 3) {
        cout << "First" << endl;
    }
    if (x == 0) {
        cout << "Second" << endl;
    }
    if (x == 2) {
        cout << "Second" << endl;
    }
    if (x == 1) {
        if (k % 2 == 1) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }
    return 0;
}