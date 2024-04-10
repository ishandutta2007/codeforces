#include <bits/stdc++.h>

using namespace std;

const int max_n = 22, max_x = 1011, inf = 1000111222;

int n, cnt[max_x], a[max_n][max_n];

void write() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n * n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    if (n % 2) {
        int odd = 0, odd_x;
        for (int i = 0; i < max_x; ++i) {
            if (cnt[i] % 2) {
                ++odd;
                odd_x = i;
            }
        }
        if (odd != 1) {
            cout << "NO" << endl;
            return 0;
        }
        a[n / 2][n / 2] = odd_x;
        --cnt[odd_x];
        int two = 0;
        for (int i = 0; i < max_x; ++i) {
            if (cnt[i] % 4 == 2) {
                ++two;
            }
        }
        if (two >= n) {
            cout << "NO" << endl;
            return 0;
        }
        vector<int> v;
        for (int i = 0; i < max_x; ++i) {
            if (cnt[i] % 4 == 2) {
                v.push_back(i);
                cnt[i] -= 2;
            }
        }
        for (int i = 0; i < max_x; ++i) {
            if (cnt[i] % 4 == 0) {
                while (cnt[i] && v.size() * 2 < 2 * (n - 1)) {
                    v.push_back(i);
                    v.push_back(i);
                    cnt[i] -= 4;
                }
            }
        }
        for (int i = 0; i < v.size() / 2; ++i) {
            a[n / 2][i] = v[i];
            a[n / 2][n - 1 - i] = v[i];
            a[i][n / 2] = v[i + v.size() / 2];
            a[n - 1 - i][n / 2] = v[i + v.size() / 2];
        }
    }
    for (int i = 0; i < max_x; ++i) {
        if (cnt[i] % 4) {
            cout << "NO" << endl;
            return 0;
        }
    }
    int row = 0, col = 0;
    for (int i = 0; i < max_x; ++i) {
        while (cnt[i]) {
            cnt[i] -= 4;
            a[row][col] = i;
            a[row][n - col - 1] = i;
            a[n - row - 1][col] = i;
            a[n - row - 1][n - col - 1] = i;
            ++col;
            if (col == n / 2) {
                col = 0;
                ++row;
            }
        }
    }
    cout << "YES" << endl;
    write();
    return 0;
}