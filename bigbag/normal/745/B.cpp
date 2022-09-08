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

const int max_n = 555, inf = 1011111111;

int n, m, cnt;
char s[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int lx = inf, ly = inf, rx = -inf, ry = -inf;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'X') {
                ++cnt;
                lx = min(lx, i);
                ly = min(ly, j);
                rx = max(rx, i);
                ry = max(ry, j);
            }
        }
    }
    if ((rx - lx + 1) * (ry - ly + 1) == cnt) {
        for (int i = lx; i <= rx; ++i) {
            for (int j = ly; j <= ry; ++j) {
                if (s[i][j] != 'X') {
                    printf("NO\n");
                    return 0;
                }
            }
        }
        printf("YES\n");
    } else {
        printf("NO");
    }
    return 0;
}