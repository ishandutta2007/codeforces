/**
 *  created: 19/05/2022, 19:12:02
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, m, a[max_n], mx[max_n];
pair<int, int> p[max_n];
vector<int> v, all[max_n];

int compress(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

void clr() {
    for (int i = 0; i < v.size(); ++i) {
        all[i].clear();
    }
    v.clear();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            v.push_back(a[i]);
        }
        fill(mx, mx + n, -1);
        for (int i = 0; i < m; ++i) {
            cin >> p[i].first >> p[i].second;
            --p[i].first;
            --p[i].second;
            mx[p[i].first] = max(mx[p[i].first], p[i].second);
        }
        for (int i = 1; i < n; ++i) {
            mx[i] = max(mx[i], mx[i - 1]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < n; ++i) {
            a[i] = compress(a[i]);
            all[a[i]].push_back(i);
        }
        int l = inf, r = -inf;
        vector<pair<int, int>> segms;
        for (int x = 0; x < v.size(); ++x) {
            int s = -1, f = -1;
            for (int i = 0; i + 1 < all[x].size(); ++i) {
                if (mx[all[x][i]] >= all[x][i + 1]) {
                    if (s == -1) {
                        s = i;
                    }
                    f = i;
                }
            }
            if (s != -1) {
                if (s != f) {
                    l = min(l, all[x][s + 1]);
                    r = max(r, all[x][f]);
                }
                //cout << x << " " << s << " " << f << endl;
            }
        }
        for (int x = 0; x < v.size(); ++x) {
            for (int i = 0; i + 1 < all[x].size(); ++i) {
                if (all[x][i] < l && mx[all[x][i]] >= all[x][i + 1]) {
                    segms.push_back({all[x][i], *prev(upper_bound(all[x].begin(), all[x].end(), mx[all[x][i]]))});
                    segms.push_back({all[x][i], all[x][i + 1]});
                }
                if (all[x][i] > r && mx[all[x][i]] >= all[x][i + 1]) {
                    segms.push_back({all[x][i], all[x][i + 1]});
                }
            }
        }
        //cout << "!" << l << " " << r << endl;
        int ans = inf;
        if (segms.empty()) {
            ans = max(0, r - l + 1);
        } else {
            sort(segms.begin(), segms.end());
            int mx = -inf, mn = inf;
            for (auto [l2, r2] : segms) {
                mx = max(mx, segms.back().first);
                ans = min(ans, max(r, mx) - min({l, l2, mn}) + 1);
                //cout << "# " << l2 << ": " <<max(r, mx) << " " << min(l, l2) << endl;
                mx = max(mx, r2);
                mn = min(mn, r2);
            }
            int L = l;
            for (auto [l2, r2] : segms) {
                L = min(L, r2);
            }
            ans = min(ans, max(r, mx) - L + 1);
        }
        cout << ans << "\n";
        clr();
    }
    return 0;
}