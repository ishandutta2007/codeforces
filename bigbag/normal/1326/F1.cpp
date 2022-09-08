#include <bits/stdc++.h>

using namespace std;

const int max_n = 14, inf = 1000111222;
const int max_mask = 1 << max_n;
const int max_mask2 = 1 << (max_n / 2 - 1);

int n;
int f[max_n + 3][max_n + 3];
string s[max_n + 3];
long long dp[max_mask][max_n][max_mask2];
long long ans[max_mask];

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        n = 14;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = f[j][i] = rand() % 2;
            }
        }
    } else {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            for (int j = 0; j < n; ++j) {
                f[i][j] = (s[i][j] == '1');
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i][0] = 1;
    }
    int cnt = (n + 1) / 2;
    for (int mask = 0; mask < max_mask; ++mask) {
        int b = __builtin_popcount(mask);
        if (b >= cnt) {
            continue;
        }
        --b;
        for (int last = 0; last < n; ++last) {
            for (int res = 0; res < max_mask2; ++res) {
                if (!dp[mask][last][res]) {
                    continue;
                }
                for (int nxt = 0; nxt < n; ++nxt) {
                    if (!get_bit(mask, nxt)) {
                        dp[mask | (1 << nxt)][nxt][res | (f[last][nxt] << b)] += dp[mask][last][res];
                    }
                }
            }
        }
    }
    const int need_l = n / 2;
    const int need_r = n - need_l;
    const int max_mask_l = (1 << (need_l - 1));
    const int max_mask_r = (1 << (need_r - 1));
    //long long OP = 0;
    for (int mask_l = 0; mask_l < max_mask; ++mask_l) {
        int b = __builtin_popcount(mask_l);
        if (b != need_l) {
            continue;
        }
        const int mask_r = ((1 << n) - 1) ^ mask_l;
        for (int i = 0; i < n; ++i) {
            if (!get_bit(mask_l, i)) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (!get_bit(mask_r, j)) {
                    continue;
                }
                const int add = f[i][j] << (need_l - 1);
                for (int res_l = 0; res_l < max_mask_l; ++res_l) {
                    if (!dp[mask_l][i][res_l]) {
                        continue;
                    }
                    for (int res_r = 0; res_r < max_mask_r; ++res_r) {
                        //++OP;
                        //cout << dp[mask_l][res_l][i] << " " << dp[mask_r][res_r][j] << "    " << res_l + add + (res_r << (need_l + 1)) << endl;
                        ans[res_l + add + (res_r << need_l)] += dp[mask_l][i][res_l] * dp[mask_r][j][res_r];
                    }
                }
            }
        }
    }
    //cout << OP << endl;
    //return 0;
    for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
        int m = mask & ((1 << need_l) - 1);
        for (int i = need_l; i + 1 < n; ++i) {
            if (get_bit(mask, n - 2 - (i - need_l))) {
                m += 1 << i;
            }
        }
        //cout << mask << " -> " << m << endl;
        printf("%I64d ", ans[m]);
    }
    puts("");
    return 0;
}