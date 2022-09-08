#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int n, m, used[max_n], f[max_n], y[max_n];
string s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            memset(f, 0, sizeof(f));
            memset(y, 0, sizeof(y));
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '#') {
                    y[j] = 1;
                    for (int k = 0; k < n; ++k) {
                        if (s[k][j] == '#') {
                            f[k] = 1;
                        }
                    }
                }
            }
            for (int k = 0; k < n; ++k) {
                if (f[k] && used[k] == 0) {
                    used[k] = 1;
                    for (int j = 0; j < m; ++j) {
                        if (y[j]) {
                            if (s[k][j] == '#') {
                                s[k][j] = '.';
                            } else {
                                puts("No");
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '#') {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}