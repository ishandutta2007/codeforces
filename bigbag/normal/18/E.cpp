#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 555, inf = 111111111;

int n, m, ans[max_n][33][33];
pair <int, int> poz[max_n][33][33];
char s[max_n][max_n], ans2[max_n][max_n];

int get_d(int lev, char a, char b) {
    int ret = 0;
    for (int i = 0; i < m; ++i) {
        if (i % 2 == 0) {
            if (s[lev][i] != a) {
                ++ret;
            }
        } else {
            if (s[lev][i] != b) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; ++i) {
        gets(s[i]);
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        for (int j = 'a'; j <= 'z'; ++j) {
            if (i != j) {
                ans[0][i - 'a'][j - 'a'] = get_d(0, i, j);
                poz[0][i - 'a'][j - 'a'] = make_pair(-1, -1);
            }
        }
    }
    for (int lev = 1; lev < n; ++lev) {
        for (int i = 'a'; i <= 'z'; ++i) {
            for (int j = 'a'; j <= 'z'; ++j) {
                if (i != j) {
                    int min1 = inf, poz1, poz2;
                    for (int i1 = 'a'; i1 <= 'z'; ++i1) {
                        for (int j1 = 'a'; j1 <= 'z'; ++j1) {
                            if (i1 != j1 && i1 != i && j1 != j) {
                                if (min1 > ans[lev - 1][i1 - 'a'][j1 - 'a']) {
                                    min1 = ans[lev - 1][i1 - 'a'][j1 - 'a'];
                                    poz1 = i1 - 'a';
                                    poz2 = j1 - 'a';
                                }
                            }
                        }
                    }
                    ans[lev][i - 'a'][j - 'a'] = get_d(lev, i, j) + min1;
                    poz[lev][i - 'a'][j - 'a'] = make_pair(poz1, poz2);
                }
            }
        }
    }
    int ans1 = inf, poz1, poz2, lev = n - 1;
    for (int i = 'a'; i <= 'z'; ++i) {
        for (int j = 'a'; j <= 'z'; ++j) {
            if (i != j) {
                if (ans1 > ans[n - 1][i - 'a'][j - 'a']) {
                    ans1 = ans[n - 1][i - 'a'][j - 'a'];
                    poz1 = i - 'a';
                    poz2 = j - 'a';
                }
            }
        }
    }
    cout << ans1 << endl;
    while (poz1 != -1) {
        for (int i = 0; i < m; ++i) {
            if (i % 2 == 0) {
                ans2[lev][i] = poz1 + 'a';
            } else {
                ans2[lev][i] = poz2 + 'a';
            }
        }
        int x = poz[lev][poz1][poz2].first, y = poz[lev][poz1][poz2].second;
        --lev;
        poz1 = x;
        poz2 = y;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans2[i][j];
        }
        cout << endl;
    }
    return 0;
}