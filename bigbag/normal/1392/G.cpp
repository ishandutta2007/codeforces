#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;
const int max_k = 21;
const int max_mask = 1 << max_k;

int n, m, k, a[max_n], b[max_n];
int p[max_n][max_k], mask[max_n][2], mn[max_mask], mx[max_mask];
string s[2];

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k >> s[0] >> s[1];
    for (int i = 0; i < k; ++i) {
        p[0][i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        --a[i];
        --b[i];
        for (int j = 0; j < k; ++j) {
            p[i][j] = j;
        }
        swap(p[i][a[i]], p[i][b[i]]);
        for (int j = 0; j < k; ++j) {
            p[n + 1][j] = p[i][p[i - 1][j]];
        }
        copy(p[n + 1], p[n + 1] + k, p[i]);
    }
    for (int mask = 0; mask < (1 << k); ++mask) {
        mn[mask] = inf;
        mx[mask] = -inf;
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int q = 0; q < k; ++q) {
                mask[i][j] += (s[j][p[i][q]] - '0') << q;
            }
        }
        mn[mask[i][0]] = min(mn[mask[i][0]], i);
        mx[mask[i][1]] = max(mx[mask[i][1]], i);

    }
    for (int mask = (1 << k) - 1; mask >= 0; --mask) {
        for (int i = 0; i < k; ++i) {
            if (get_bit(mask, i)) {
                mn[mask ^ (1 << i)] = min(mn[mask ^ (1 << i)], mn[mask]);
                mx[mask ^ (1 << i)] = max(mx[mask ^ (1 << i)], mx[mask]);
            }
        }
    }
    int ans = -1, l, r;
    for (int mask = 0; mask < (1 << k); ++mask) {
        if (mx[mask] - mn[mask] >= m && ans < __builtin_popcount(mask)) {
            ans = __builtin_popcount(mask);
            l = mn[mask] + 1;
            r = mx[mask];
        }
    }
    assert(ans != -1);
    ans = 0;
    for (int i = l; i <= r; ++i) {
        swap(s[0][a[i]], s[0][b[i]]);
    }
    for (int i = 0; i < k; ++i) {
        ans += s[0][i] == s[1][i];
    }
    printf("%d\n%d %d\n", ans, l, r);
    return 0;
}