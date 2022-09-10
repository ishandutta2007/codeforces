#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, max_b = 17, inf = 1000111222;

int n, p, a[max_b][max_b], nxt[max_n][max_b], cnt[max_b];
bool bad[max_b][max_b][1 << max_b], ok[1 << max_b], very_bad[1 << max_b];
char s[max_n];

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%s", &n, &p, s);
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < p; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < p; ++i) {
        nxt[n][i] = n;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < p; ++j) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][s[i] - 'a'] = i;
        ++cnt[s[i] - 'a'];
    }
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < p; ++c) {
            int pos = nxt[i + 1][c];
            if (pos == n || nxt[i + 1][s[i] - 'a'] < pos || a[s[i] - 'a'][c]) {
                continue;
            }
            int mask = 0;
            for (int c2 = 0; c2 < p; ++c2) {
                if (nxt[i + 1][c2] < pos) {
                    mask |= (1 << c2);
                }
            }
            // cout << "#" << s[i] << " " << (char) (c + 'a') << " " << mask << endl;
            bad[s[i] - 'a'][c][mask] = 1;
        }
    }
    for (int c1 = 0; c1 < p; ++c1) {
        for (int c2 = 0; c2 < p; ++c2) {
            for (int mask = 0; mask < (1 << p); ++mask) {
                if (bad[c1][c2][mask]) {
                    very_bad[mask] = 1;
                    for (int i = 0; i < p; ++i) {
                        if (i != c1 && i != c2) {
                            bad[c1][c2][mask | (1 << i)] = 1;
                        }
                    }
                }
            }
        }
    }
    ok[0] = 1;
    int ans = inf;
    /*for (int mask = 0; mask < (1 << p); ++mask) {
        cout << mask << ": " << very_bad[mask] << endl;
    }*/
    for (int mask = 0; mask < (1 << p); ++mask) {
        if (ok[mask]) {
            int len = 0;
            for (int i = 0; i < p; ++i) {
                len += (1 - get_bit(mask, i)) * cnt[i];
            }
            ans = min(ans, len);
            for (int i = 0; i < p; ++i) {
                if (!get_bit(mask, i)) {
                    int to = mask | (1 << i);
                    if (!very_bad[to]) {
                        // cout << mask << " -> " << to << endl;
                        ok[to] = 1;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}