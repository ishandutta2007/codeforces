/**
 *  created: 23/02/2022, 13:26:15
**/

#include <bits/stdc++.h>

using namespace std;

double start = clock();

bool is_tl() {
    return ((clock() - start) / CLOCKS_PER_SEC) >= 2.74;
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 gen(seed);

const int max_n = 100111, inf = 1000111222;
const int max_m = 5;
const int max_x = 17;
const int max_mask = 1 << max_x;

int n, m, a[max_n][max_m], w[max_n], masks[max_n];
int val[max_n * max_m];
int dp[max_mask];
vector<int> v;

int compress(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    /*for (int it = 0; it < 200; ++it) {
        for (int mask = 0; mask < max_mask; ++mask) {
            if (mask < 200) {
                dp[mask] = gen() % inf;
            } else {
                dp[mask] = 0;
                for (int i = 0; i < max_x; ++i) {
                    if (get_bit(mask, i)) {
                        dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
                    }
                }
            }
        }
        cout << dp[max_mask - 1] << endl;
    }*/
    if (0) {
        n = 100000;
        m = 5;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                while (1) {
                    a[i][j] = gen() % inf;
                    bool ok = 1;
                    for (int k = 0; k < j; ++k) {
                        ok &= a[i][j] != a[i][k];
                    }
                    if (ok) {
                        break;
                    }
                }
            }
            w[i] = gen() % inf;
        }
    } else {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
            cin >> w[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            v.push_back(a[i][j]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = compress(a[i][j]);
        }
    }
    int ans = 2 * inf;
    for (int it = 0; it < 20 * 1; ++it) {
        for (int i = 0; i < v.size(); ++i) {
            val[i] = gen() % max_x;
        }
        memset(dp, 127, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            masks[i] = 0;
            for (int j = 0; j < m; ++j) {
                masks[i] |= (1 << val[a[i][j]]);
            }
            dp[masks[i]] = min(dp[masks[i]], w[i]);
        }
        for (int mask = 0; mask < max_mask; ++mask) {
            for (int i = 0; i < max_x; ++i) {
                if (get_bit(mask, i)) {
                    dp[mask] = min(dp[mask], dp[mask ^ (1 << i)]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            int x = dp[((1 << max_x) - 1) ^ masks[i]];
            if (x != dp[0]) {
                ans = min(ans, w[i] + x);
            }
        }
        if (0) {
            //cout << it << ": " << ans << endl;
        }
    }
    if (ans == 2 * inf) {
        ans = -1;
    }
    cout << ans << "\n";
    return 0;
}