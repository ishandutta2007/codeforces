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

const int max_n = 111, inf = 111111111;

int n, m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    if (n == 1 && m == 2) {
        cout << "0\n1 1\n1 2\n1 1";
        return 0;
    }
    if (n == 2 && m == 1) {
        cout << "0\n1 1\n2 1\n1 1";
        return 0;
    }
    if (n == 1) {
        cout << 1 << endl << 1 << ' ' << m << ' ' << 1 << ' ' << 1 << endl;
        for (int i = 1; i <= m; ++i) {
            cout << 1 << ' ' << i << endl;
        }
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }
    if (m == 1) {
        cout << 1 << endl << n << ' ' << 1 << ' ' << 1 << ' ' << 1 << endl;
        for (int i = 1; i <= n; ++i) {
            cout << i << ' ' << 1 << endl;
        }
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }
    if (n % 2 == 1 && m % 2 == 1) {
        cout << 1 << endl;
        cout << n << ' ' << m << ' ' << 1 << ' ' << 1 << endl;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) {
                for (int j = 1; j <= m; ++j) {
                    cout << i << ' ' << j << endl;
                }
            } else {
                for (int j = m; j > 0; --j) {
                    cout << i << ' ' << j << endl;
                }
            }
        }
        cout << "1 1\n";
        return 0;
    }
    if (n % 2 == 0) {
        cout << 0 << endl;
        for (int i = 1; i <= n; ++i) {
            cout << i << ' ' << 1 << endl;
        }
        for (int i = n; i > 0; --i) {
            if (i % 2 == 0) {
                for (int j = 2; j <= m; ++j) {
                    cout << i << ' ' << j << endl;
                }
            } else {
                for (int j = m; j > 1; --j) {
                    cout << i << ' ' << j << endl;
                }
            }
        }
        cout << 1 << ' ' << 1 << endl;
    } else {
        cout << 0 << endl;
        for (int i = 1; i <= m; ++i) {
            cout << 1 << ' ' << i << endl;
        }
        for (int i = m; i > 0; --i) {
            if (i % 2 == 0) {
                for (int j = 2; j <= n; ++j) {
                    cout << j << ' ' << i << endl;
                }
            } else {
                for (int j = n; j > 1; --j) {
                    cout << j << ' ' << i << endl;
                }
            }
        }
        cout << 1 << ' ' << 1 << endl;
    }
    return 0;
}