#include <bits/stdc++.h>

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    }
    return res;
}

const int N = 1e6 + 5;

int n, m, p, q, lens0, lent0, res, pwr[N], invpwr[N], f[N][27];
char s0[N], s[N], t0[N], t[N];

void dfs(int d, std::string t) {
    int m = t.size();
    if (m > 1) {
        char x = t[0], y = t[1];
        std::string gox, goy;
        for (int i = 0; i < m; i += 2) {
            if (t[i] != x) { x = '?'; }
            gox += t[i];
        }
        for (int i = 1; i < m; i += 2) {
            if (t[i] != y) { y = '?'; }
            goy += t[i];
        }
        if (x == s[d - 1]) {
            dfs(d + 1, goy);
        }
        if (y == s[d - 1]) {
            dfs(d + 1, gox);
        }
    } else {
        int x = t[0] - 'a';
        res = add(res, 1ll * sub(f[d - 1][x], f[p][x]) * pwr[p] % mod);
        return;
    }
}

int query() {
    if (m == 0) { return pwr[p]; }
    if (p <= 22 && m > pwr[p] - 1) { return 0; }
    std::string _t;
    for (int i = 0; i < m; i++) { _t += t[i]; }
    res = 0;
    dfs(1, _t);
    return res;
}

int main() {
    scanf("%d%d", &n, &q);
    scanf("%s%s", s0, s);
    lens0 = strlen(s0);
    pwr[0] = 1; invpwr[0] = 1;
    for (int i = 1; i <= n; i++) {
        pwr[i] = add(pwr[i - 1], pwr[i - 1]);
        invpwr[i] = power(pwr[i], mod - 2);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int x = 0; x < 26; x++) {
            f[i][x] = f[i + 1][x];
            if (s[i] - 'a' == x) {
                f[i][x] = add(f[i][x], invpwr[i + 1]);
            }
        }
    }
    for (; q; q--) {
        scanf("%d%s", &p, &t0);
        lent0 = strlen(t0);
        int ans = 0;
        for (int d = 0; d <= lens0; d++) {
            m = 0;
            bool ok = true;
            for (int i = 0, j = (lens0 - d) % lens0; i < lent0; i++) {
                if (i % (lens0 + 1) == d) {
                    t[m++] = t0[i];
                } else {
                    if (t0[i] != s0[j]) { ok = false; break; }
                    j = (j + 1) % lens0;
                }
            }
            if (!ok) { continue; }
            ans = add(ans, query());
        }
        printf("%d\n", ans);
    }
    return 0;
}