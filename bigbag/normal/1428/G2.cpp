#include <bits/stdc++.h>

using namespace std;

const int max_sum = 1000111, inf = 1000111222;
const int max_q = 100111;

struct window {
    int first, last;
    pair<long long, int> v[max_sum];

    void clr() {
        first = 0;
        last = -1;
    }

    void add(long long x, int i) {
        while (first <= last && v[last].first <= x) {
            --last;
        }
        v[++last] = {x, i};
    }

    void del(int i) {
        if (v[first].second == i) {
            ++first;
        }
    }

    long long get_max() {
        return v[first].first;
    }
};

window w;

int k, q, x[max_q];
int f[7];
long long dp[2][max_sum], base[max_sum], ans[max_q];

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void calc_dp() {
    memset(dp, 254, sizeof(dp));
    int q1 = 0, q2 = 1, val = 9;
    dp[q1][0] = 0;
    for (int i = 0; i < 6; ++i) {
        int cnt = k - 1 - 1;
        /*cout << "$" << cnt << endl;
        for (int j = 0; j < 66; ++j) {
            cout << dp[q1][j] << " ";
        }
        cout << endl;*/
        if (cnt >= 0) {
            const long long COST = 3LL * f[i];
            for (int rem = 0; rem < val; ++rem) {
                w.clr();
                for (int pos = 0, s = rem; s < max_sum; ++pos, s += val) {
                    w.add(dp[q1][s] - pos * COST, pos);
                    w.del(pos - cnt - 1);
                    dp[q2][s] = w.get_max() + pos * COST;
                }
            }
        } else {
            memset(dp[q2], 254, sizeof(dp[q2]));
        }
        const int pw = val / 9;
        for (int rem = 0; rem < pw; ++rem) {
            w.clr();
            for (int pos = 0, s = rem; s < max_sum; ++pos, s += pw) {
                w.add(dp[q2][s], pos);
                w.del(pos - 9);
                dp[q2][s] = max(dp[q2][s], w.get_max());
            }
        }
        if (cnt >= 0) {
            long long all = 1LL * (cnt + 1) * val;
            const long long COST = 3LL * f[i] * (cnt + 1);
            if (all < max_sum) {
                for (int s = all; s < max_sum; ++s) {
                    dp[q2][s] = max(dp[q2][s], dp[q1][s - all] + COST);
                }
            }
        }
        swap(q1, q2);
        val *= 10;
    }
    copy(dp[q1], dp[q1] + max_sum, base);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &k);
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &f[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &x[i]);
        if (k == 1) {
            long long ans = 0;
            for (int j = 0; j < 6; ++j) {
                int y = x[i] % 10;
                if (y % 3 == 0) {
                    y /= 3;
                    ans += 1LL * f[j] * y;
                }
                x[i] /= 10;
            }
            printf("%I64d\n", ans);
        }
    }
    if (k == 1) {
        return 0;
    }
    calc_dp();
    for (int mask = 0; mask < (1 << 6); ++mask) {
        int val = 9;
        int q1 = 0, q2 = 1;
        copy(base, base + max_sum, dp[q1]);
        for (int i = 0; i < 6; ++i) {
            if (!get_bit(mask, i)) {
                copy(dp[q1], dp[q1] + max_sum, dp[q2]);
                for (int s = val; s < max_sum; ++s) {
                    dp[q2][s] = max(dp[q2][s], dp[q1][s - val] + 3LL * f[i]);
                }
                swap(q1, q2);
            }
            val *= 10;
        }
        for (int submask = mask; ; submask = mask & (submask - 1)) {
            long long cursum = 0, cost = 0;
            for (int i = 0, pw = 1; i < 6; ++i, pw *= 10) {
                if (get_bit(mask, i)) {
                    if (get_bit(submask, i)) {
                        cursum += 6 * pw;
                        cost += 2 * f[i];
                    } else {
                        cursum += 3 * pw;
                        cost += 1 * f[i];
                    }
                }
            }
            for (int i = 0; i < q; ++i) {
                if (cursum > x[i]) {
                    continue;
                }
                const int add = x[i] - cursum;
                ans[i] = max(ans[i], dp[q1][add] + cost);
            }
            if (!submask) {
                break;
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        printf("%I64d\n", ans[i]);
        //printf("%d %I64d\n", x[i], ans[i]);
    }
    return 0;
}