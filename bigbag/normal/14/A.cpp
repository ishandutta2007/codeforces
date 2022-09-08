#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int n, m, l, r, l1, r1;
char s[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d\n", &n, &m);
    l = inf;
    l1 = inf;
    for (int i = 0; i < n; ++i) {
        gets(s[i]);
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '*') {
                l = min(l, j);
                r = max(r, j);
                l1 = min(l1, i);
                r1 = max(r1, i);
            }
        }
    }
    for (int i = l1; i <= r1; ++i) {
        for (int j = l; j <= r; ++j) {
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}