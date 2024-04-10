#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, mod = 1000000007;

int n, m, a[max_n], sum[max_n][max_n], sum2[max_n][max_n];
int tp[max_n], d[max_n];
set<pair<int, int>> q;

int get_sum(int tp, int l, int r) {
    if (!l) {
        return sum[r][tp];
    }
    return sum[r][tp] - sum[l - 1][tp];
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int get_less(int tp, int r) {
    return sum2[tp][r];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        if (i) {
            copy(sum[i - 1], sum[i - 1] + n, sum[i]);
        }
        ++sum[i][a[i]];
        /*for (int j = 0; j < n; ++j) {
            cout << sum[i][j] << " ";
        }
        cout << endl;*/
    }
    for (int i = 0; i < m; ++i) {
        cin >> tp[i] >> d[i];
        --tp[i];
        ++sum2[tp[i]][d[i]];
        q.insert({tp[i], d[i]});
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum2[i][j] += sum2[i][j - 1];
        }
    }
    int mx = -1, ways = 0;
    for (int i = 0; i < n; ++i) {
        //cout << "#" << i << ": " << a[i] << " " << get_sum(a[i], 0, i) << endl;
        if (!q.count({a[i], get_sum(a[i], 0, i)})) {
            continue;
        }
        int cnt = 1, w = 1;
        for (int tp = 0; tp < n; ++tp) {
            const int r1 = get_sum(tp, 0, i);
            const int r2 = get_sum(tp, i + 1, n - 1);
            if (tp == a[i]) {
                int c = get_less(tp, r2);
                c -= get_sum(a[i], 0, i) <= r2;
                if (c) {
                    w = mul(w, c);
                    ++cnt;
                }
            } else {
                int c1 = get_less(tp, r1);
                int c2 = get_less(tp, r2);
                int ways = c1 * c2 - min(c1, c2);
                if (ways) {
                    cnt += 2;
                    w = mul(w, ways);
                } else if (c1 && c2) {
                    ++cnt;
                    w = mul(w, c1 + c2);
                } else if (c1) {
                    ++cnt;
                    w = mul(w, c1);
                } else if (c2) {
                    ++cnt;
                    w = mul(w, c2);
                }
            }
        }
        //cout << i << ": " << cnt << " " << w << endl;
        if (mx < cnt) {
            mx = cnt;
            ways = 0;
        }
        if (mx == cnt) {
            ways += w;
            ways %= mod;
        }
    }
    int cnt = 0, w = 1;
    for (int tp = 0; tp < n; ++tp) {
        const int r = get_sum(tp, 0, n - 1);
        int c = get_less(tp, r);
        if (c) {
            ++cnt;
            w = mul(w, c);
        }
    }
    if (mx < cnt) {
        mx = cnt;
        ways = 0;
    }
    if (mx == cnt) {
        ways += w;
        ways %= mod;
    }
    cout << mx << " " << ways << "\n";
    return 0;
}