#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int max_g = 455;

int k, n, a[max_n], nxt[max_n];
int p[max_g][max_n], mx[max_g][max_n], res[max_g];

void calc_nxt() {
    int pos = 0;
    for (int i = 0; i < max_n; ++i) {
        while (pos < n && a[pos] < i) {
            ++pos;
        }
        nxt[i] = pos;
    }
}

int find_p(int g, int v) {
    if (v == p[g][v]) {
        return v;
    }
    return p[g][v] = find_p(g, p[g][v]);
}

int solve() {
    calc_nxt();
    for (int g = 0; g < max_g; ++g) {
        for (int i = 0; i <= n; ++i) {
            p[g][i] = i;
            mx[g][i] = -1;
        }
    }
    for (int r = n - 1; r >= 0; --r) {
        int last = 0;
        for (int g = 0; ; ++g) {
            int pos = mx[g][r];
            int nlast = r;
            if (pos != -1) {
                int l = 0;
                if (2 * a[r] - a[pos] + 1 >= 0) {
                    l = nxt[2 * a[r] - a[pos] + 1];
                }
                nlast = min(l, r);
            }
            if (last < nlast) {
                const int from = last, to = nlast - 1;
                while (true) {
                    int pos = find_p(g, from);
                    if (pos > to) {
                        break;
                    }
                    mx[g][pos] = r;
                    p[g][pos] = pos + 1;
                }
                last = nlast;
            }
            if (nlast == r) {
                break;
            }
        }
    }
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; ++i) {
        for (int g = 0; ; ++g) {
            if (mx[g][i] == -1) {
                res[g] = 1;
                break;
            }
        }
    }
    for (int g = 0; ; ++g) {
        if (!res[g]) {
            return g;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &k);
    int ans = 0;
    while (k--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        ans ^= solve();
        //cout << ans << endl;
    }
    if (ans) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}