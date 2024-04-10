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

int n, a[max_n][max_n];
char ans[max_n][max_n];
string s[max_n];

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y &&  x < n && y < n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = 0; j < 2 * n - 1; ++j) {
            ans[i][j] = '.';
        }
    }
    int mx = n - 1;
    for (int dx = -mx; dx <= mx; ++dx) {
        for (int dy = -mx; dy <= mx; ++dy) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            int f = 1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (s[i][j] == 'o') {
                        int x = i + dx;
                        int y = j + dy;
                        if (is_in(x, y)) {
                            if (s[x][y] == '.') {
                                f = 0;
                                break;
                            }
                        }
                    }
                }
            }
            if (f == 1) {
                ans[dx + n - 1][dy + n - 1] = 'x';
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (s[i][j] == 'o') {
                            int x = i + dx;
                            int y = j + dy;
                            if (is_in(x, y)) {
                                a[x][y] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    ans[n - 1][n - 1] = 'o';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'x' && a[i][j] == 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    printf("YES\n");
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = 0; j < 2 * n - 1; ++j) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}