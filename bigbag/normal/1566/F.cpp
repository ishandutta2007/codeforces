/**
 *  created: 12/09/2021, 18:54:20
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222;
const long long inf = 1000111222000111222LL;

int t, n, m, a[max_n];
pair<int, int> p[max_n];
vector<pair<int, int>> v;
long long dp_point[max_n], dp_segm[max_n];
long long dp_point2[max_n];

long long get_dp_point(int i) {
    if (i < 0) {
        return 0;
    }
    return dp_point[i];
}

long long get_dp_point2(int i) {
    if (i < 0) {
        return 0;
    }
    return dp_point2[i];
}

long long get_dp_segm(int i) {
    if (i < 0) {
        return 0;
    }
    return dp_segm[i];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        for (int i = 0; i < m; ++i) {
            cin >> p[i].first >> p[i].second;
            int pos = lower_bound(a, a + n, p[i].first) - a;
            if (pos < n && a[pos] <= p[i].second) {
                --m;
                --i;
            }
        }
        sort(p, p + m);
        v.clear();
        for (int i = 0; i < m; ++i) {
            while (!v.empty() && v.back().second >= p[i].second) {
                v.pop_back();
            }
            v.push_back(p[i]);
        }
        if (v.empty()) {
            cout << "0\n";
            continue;
        }
        vector<vector<pair<int, int>>> all;
        int pos = 0;
        a[n] = 1000111222;
        for (int i = 0; i <= n; ++i) {
            vector<pair<int, int>> cur;
            while (pos < v.size() && v[pos].second < a[i]) {
                cur.push_back(v[pos]);
                ++pos;
            }
            all.push_back(cur);
        }
        fill(dp_point, dp_point + n + 5, inf);
        fill(dp_point2, dp_point2 + n + 5, inf);
        fill(dp_segm, dp_segm + v.size() + 5, inf);
        int cur = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < all[i].size(); ++j) {
                if (i == 0) {
                    dp_segm[cur + j] = inf;
                } else {
                    long long cost = all[i][j].first - a[i - 1];
                    dp_segm[cur + j] = min(cost + dp_point2[i - 1], 2 * cost + dp_point[i - 1]);
                }
                //cout << "## " << "[" << all[i][j].first << " " << all[i][j].second << "]" << ": " << dp_segm[cur + j] << endl;
            }

            if (all[i].empty()) {
                dp_point[i] = get_dp_point(i - 1);
                dp_point2[i] = get_dp_point(i - 1);
            } else {
                dp_point[i] = get_dp_segm(cur + all[i].size() - 1);
                dp_point2[i] = get_dp_segm(cur + all[i].size() - 1);
                for (int j = 0; j < all[i].size(); ++j) {
                    long long cost = a[i] - all[i][j].second;
                    long long add = 0;
                    if (j == 0) {
                        add = get_dp_point(i - 1);
                    } else {
                        add = get_dp_segm(cur + j - 1);
                    }
                    dp_point[i] = min(dp_point[i], cost + add);
                    dp_point2[i] = min(dp_point2[i], 2 * cost + add);
                }
            }
            cur += all[i].size();
            //cout << i << ", x[i] = " << a[i] << ": " << dp_point[i] << endl;
        }
        long long ans = get_dp_segm(v.size() - 1);
        if (a[n - 1] >= v.back().second) {
            ans = min(ans, get_dp_point(n - 1));
        }
        cout << ans << "\n";
    }
    return 0;
}