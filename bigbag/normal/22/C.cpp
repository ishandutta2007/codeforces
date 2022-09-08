#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 33, inf = 111111111;

long long n, m, v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> v;
    if (m + 1 < n) {
        cout << "-1";
        return 0;
    }
    if (m > 1 + (n - 1) * (n - 2) / 2) {
        cout << "-1";
        return 0;
    }
    if (v == n) {
        cout << v << ' ' << 1 << endl;
        for (int i = 2; i < n; ++i) {
            if (i != v) {
                cout << i << ' ' << v << endl;
            }
        }
        int cnt = n - 1;
        for (int i = 2; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (i != v && j != v) {
                    if (cnt == m) {
                        return 0;
                    }
                    cout << i << ' ' << j << endl;
                    cnt++;
                }
            }
        }
        return 0;
    }
    cout << v << ' ' << n << endl;
    for (int i = 1; i < n; ++i) {
        if (i != v) {
            cout << i << ' ' << v << endl;
        }
    }
    int cnt = n - 1;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (i != v && j != v) {
                if (cnt == m) {
                    return 0;
                }
                cout << i << ' ' << j << endl;
                cnt++;
            }
        }
    }
    return 0;
}