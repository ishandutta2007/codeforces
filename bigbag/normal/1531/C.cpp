/**
 *  created: 24/05/2021, 12:38:40
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n;
char ans[max_n][max_n];

int get_sz(int n) {
    int sz = 1;
    while (n > sz * sz) {
        ++sz;
    }
    if (n + 2 == sz * sz) {
        ++sz;
    }
    return sz;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n == 2) {
        cout << -1 << endl;
        return 0;
    }
    int sz = get_sz(n);
    for (int i = 0; i < sz; ++i) {
        fill(ans[i], ans[i] + sz, '.');
    }
    int SZ = sz;
    int pos = 0;
    while (n) {
        int sz = get_sz(n);
        n -= sz * 2 - 1;
        for (int i = 0; i < sz; ++i) {
            ans[SZ - 1 - pos][pos + i] = ans[SZ - 1 - i - pos][pos] = 'o';
        }
        ++pos;
    }
    cout << sz << endl;
    for (int i = 0; i < sz; ++i) {
        puts(ans[i]);
    }
    return 0;
}