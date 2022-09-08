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

const int max_n = 111, inf = 111111111;

int a, b, c, d, n, cnt[max_n];
char ans[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c >> d >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cnt[i];
    }
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            ans[i][j] = '.';
        }
    }
    int x = a + c, y = 1, poz = 0, napr;
    if (c % 2 == 0) {
        napr = 1;
    } else {
        y = d;
        napr = 2;
    }
    char part = 'a';
    while (true) {
        if (cnt[poz] == 0) {
            ++poz;
            ++part;
        }
        if (poz == n) {
            break;
        }
        --cnt[poz];
        ans[y][x] = part;
        int nx, ny;
        if (napr == 1) {
            if (x > a) {
                if (y == d) {
                    nx = x - 1;
                    ny = y;
                    napr = 2;
                } else {
                    nx = x;
                    ny = y + 1;
                }
            } else {
                if (y == b) {
                    nx = x - 1;
                    ny = y;
                    napr = 2;
                } else {
                    nx = x;
                    ny = y + 1;
                }
            }
        } else {
            if (y == 1) {
                nx = x - 1;
                ny = y;
                napr = 1;
            } else {
                nx = x;
                ny = y - 1;
            }
        }
        x = nx;
        y = ny;
    }
    printf("YES\n");
    for (int i = 1; i <= max(b, d); ++i) {
        for (int j = 1; j <= a + c; ++j) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}