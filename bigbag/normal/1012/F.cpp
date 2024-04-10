#include <bits/stdc++.h>

using namespace std;

const int max_n = 22, inf = 2000111222;

struct trip {
    int start, len, t, num;

    void read() {
        cin >> start >> len >> t;
    }
};

bool cmp_by_start(const trip &a, const trip &b) {
    return a.start < b.start;
}

bool cmp_by_t(const trip &a, const trip &b) {
    return a.t < b.t;
}

int n, p, dp[(1 << max_n) + 100];
char last[(1 << max_n) + 100];
trip a[max_n], b[max_n];

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int num[max_n], t[max_n];

void restore_answer(int p, int mask) {
    while (mask) {
        num[a[last[mask]].num] = p;
        t[a[last[mask]].num] = dp[mask] - a[last[mask]].t;
        mask ^= (1 << last[mask]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        a[i].read();
        a[i].num = i;
    }
    sort(a, a + n, cmp_by_start);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
        b[i].num = i;
    }
    sort(b, b + n, cmp_by_t);
    for (int i = 0; i < (1 << n); ++i) {
        dp[i] = inf;
    }
    dp[0] = 1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (dp[mask] == inf) {
            continue;
        }
        //cout << mask << " " << dp[mask] << " " << last[mask] << endl;
        for (int id = 0; id < n; ++id) {
            int nxt = b[id].num;
            int i = 0;
            if (!get_bit(mask, nxt)) {
                int to = mask | (1 << nxt);
                int mn = inf, pos = 0;
                while (i < n) {
                    int l = 0, r = a[i].start - 1;
                    if (i) {
                        l = a[i - 1].start + a[i - 1].len;
                    }
                    if (dp[mask] > r || l > r) {
                        ++i;
                        continue;
                    }
                    int res = max(dp[mask], l);
                    while (pos < n && (!get_bit(to, pos) || pos < i)) {
                        ++pos;
                    }
                    if (pos == n || res + a[nxt].t < a[pos].start) {
                        mn = res;
                        break;
                    }
                    ++i;
                }
                //cout << " -> " << nxt << ", mn = " << mn << endl;
                if (mn + a[nxt].t < a[nxt].start) {
                    if (dp[to] > mn + a[nxt].t) {
                        dp[to] = mn + a[nxt].t;
                        last[to] = nxt;
                    }
                }
            }
        }
    }
    int full = (1 << n) - 1;
    vector<int> all;
    if (p == 1) {
        all.push_back(full);
    } else {
        for (int i = 0; i <= full; ++i) {
            all.push_back(i);
        }
    }
    for (int mask : all) {
        if (dp[mask] < inf && dp[full ^ mask] < inf) {
            restore_answer(1, mask);
            restore_answer(2, mask ^ full);
            puts("YES");
            for (int i = 0; i < n; ++i) {
                cout << num[i] << " " << t[i] << endl;
            }
            return 0;
        }
    }
    puts("NO");
    return 0;
}