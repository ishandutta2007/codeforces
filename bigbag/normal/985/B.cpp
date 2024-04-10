#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111222;

int n, m;
bitset<max_n> b[max_n], all, pr[max_n], suf, res;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        for (int j = 0; j < m; ++j) {
            b[i][j] = s[j] - '0';
        }
        pr[i] = b[i];
        if (i) {
            pr[i] |= pr[i - 1];
        }
    }
    for (int i = 0; i < m; ++i) {
        all[i] = 1;
    }
    for (int i = n - 1; i >= 0; --i) {
        res = suf;
        if (i) {
            res |= pr[i - 1];
        }
        if (res == all) {
            puts("YES");
            return 0;
        }
        suf |= b[i];
    }
    puts("NO");
    return 0;
}