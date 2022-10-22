//
// Created by Junjie Wu on 2021/4/18.
//

#include <bits/stdc++.h>

const int N = 1e5 + 10;

int n;
char a[N << 1], b[N << 1], c[N << 1];
char ans[N * 3];

int count(const char *s, char ch) {
    int ret = 0;
    for (int i = 0; s[i]; ++i) {
        ret += s[i] == ch;
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s%s%s", &n, a, b, c);
        int a0 = count(a, '0');
        int b0 = count(b, '0');
        int c0 = count(c, '0');

        char *x, *y, ch;
        if (a0 >= n && b0 >= n) x = a, y = b, ch = '0';
        else if (a0 >= n && c0 >= n) x = a, y = c, ch = '0';
        else if (a0 >= n) x = b, y = c, ch = '1';
        else if (b0 >= n && c0 >= n) x = b, y = c, ch = '0';
        else if (b0 < n) x = a, y = b, ch = '1';
        else if (c0 < n) x = a, y = c, ch = '1';

        int m = 0, i = 0, j = 0;
        for (int cnt = 0; cnt < n; ++cnt) {
            while (x[i] != ch) {
                ans[m++] = x[i++];
            }
            while (y[j] != ch) {
                ans[m++] = y[j++];
            }
            ans[m++] = ch;
            ++i;
            ++j;
        }
        for (; x[i]; ++i) ans[m++] = x[i];
        for (; y[j]; ++j) ans[m++] = y[j];
        ans[m] = 0;

        printf("%s\n", ans);
    }
    return 0;
}