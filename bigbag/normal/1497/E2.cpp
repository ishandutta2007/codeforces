/**
 *  created: 17/03/2021, 17:19:03
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_x = 10001111;
const int max_k = 22;

int t, n, k, a[max_n], dp[max_n][max_k];
int mnd[max_x];

void calc_mnd() {
    mnd[1] = 1;
    for (int i = 2; i < max_x; ++i) {
        if (!mnd[i]) {
            mnd[i] = i;
            for (int j = 2 * i; j < max_x; j += i) {
                if (!mnd[j]) {
                    mnd[j] = i;
                }
            }
        }
    }
}

int upd(int x) {
    int res = 1;
    while (x > 1) {
        int d = mnd[x], cnt = 0;
        while (x % d == 0) {
            ++cnt;
            x /= d;
        }
        if (cnt % 2) {
            res *= d;
        }
    }
    return res;
}

int last[max_x];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(last, -1, sizeof(last));
    calc_mnd();
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            a[i] = upd(a[i]);
            //cout << a[i] << " ";
        }
        //cout << endl;
        set<int> q{-1};
        for (int i = 0; i < n; ++i) {
            q.insert(last[a[i]]);
            last[a[i]] = i;
            vector<int> v;
            auto it = q.rbegin();
            while (v.size() <= k) {
                v.push_back(*it);
                if (v.back() == -1) {
                    break;
                }
                ++it;
            }
            while (v.size() <= k) {
                v.push_back(-1);
            }
            if (0) {
                cout << i << ": ";
                for (int x : v) {
                    cout << x << " ";
                }
                cout << endl;
            }
            for (int cnt = 0; cnt <= k; ++cnt) {
                dp[i][cnt] = inf;
                for (int last = 0; last <= cnt; ++last) {
                    int add = 0;
                    if (v[last] > -1) {
                        add = dp[v[last]][cnt - last];
                    }
                    dp[i][cnt] = min(dp[i][cnt], 1 + add);
                }
            }
        }
        int ans = inf;
        for (int i = 0; i <= k; ++i) {
            ans = min(ans, dp[n - 1][i]);
        }
        printf("%d\n", ans);

        for (int i = 0; i < n; ++i) {
            last[a[i]] = -1;
        }
    }
    return 0;
}