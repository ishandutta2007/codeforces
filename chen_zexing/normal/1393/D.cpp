#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
char s[2005][2005];
int l[2005][2005],r[2005][2005],up[2005][2005],down[2005][2005];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++) {
            if (i == 0 || s[i][j] != s[i - 1][j]) up[i][j] = 1;
            else up[i][j] = up[i - 1][j] + 1;
        }
    for (int j = 0; j < m; j++)
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1 || s[i][j] != s[i + 1][j]) down[i][j] = 1;
            else down[i][j] = down[i + 1][j] + 1;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            up[i][j] = min(up[i][j], down[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (j == 0) l[i][j] = 1;
            else if (s[i][j] != s[i][j - 1]) l[i][j] = 1;
            else if (up[i][j] > l[i][j - 1]) l[i][j] = l[i][j - 1] + 1;
            else l[i][j] = up[i][j];
        }
    for (int i = 0; i < n; i++)
        for (int j = m - 1; j >= 0; j--) {
            if (j == m - 1) r[i][j] = 1;
            else if (s[i][j] != s[i][j + 1]) r[i][j] = 1;
            else if (up[i][j] > r[i][j + 1]) r[i][j] = r[i][j + 1] + 1;
            else r[i][j] = up[i][j];
        }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans += min(l[i][j], r[i][j]);
    printf("%lld\n", ans);
}