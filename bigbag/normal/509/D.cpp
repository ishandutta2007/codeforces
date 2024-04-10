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

const int max_n = 111, inf = 1111111111;

int mx, n, m, k, a[max_n], b[max_n], w[max_n][max_n], o[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> w[i][j];
            mx = max(mx, w[i][j]);
            if (j) {
                o[i][j] = w[i][j] - w[i][0];
            }
        }
    }
    k = -1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (o[i][j] != o[0][j]) {
                int x = o[i][j] - o[0][j];
                if (x < 0) {
                    x *= -1;
                }
                if (k != -1) {
                    if (k != x) {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
                k = x;
            }
        }
    }
    if (k == -1) {
        k = 2000222000;
    }
    if (mx >= k) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i < m; ++i) {
        b[i] = (o[0][i]) % k;
        if (b[i] < 0) {
            b[i] += k;
        }
    }
    for (int i = 0; i < n; ++i) {
        a[i] = w[i][0];
    }
    cout << k << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < m; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << (a[i] + b[j]) % k << " ";
        }
        cout << endl;
    }*/
    return 0;
}