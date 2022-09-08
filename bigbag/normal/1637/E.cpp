/**
 *  created: 12/02/2022, 17:08:58
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 303333, inf = 1000111222;

int t, n, m, a[max_n];
int lastt, bad[max_n];
vector<int> v, g[max_n];

void clr() {
    v.clear();
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
}

int compress(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
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
        sort(v.begin(), v.end());
        vector<pair<int, int>> all;
        for (int i = 0; i < v.size(); ) {
            int pos = i;
            while (i < v.size() && v[pos] == v[i]) {
                ++i;
            }
            all.push_back({i - pos, all.size()});
        }
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < n; ++i) {
            a[i] = compress(a[i]);
        }
        while (m--) {
            int u, v;
            cin >> u >> v;
            u = compress(u);
            v = compress(v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        sort(all.begin(), all.end());
        reverse(all.begin(), all.end());
        vector<int> ids;
        for (int i = 0; i < all.size(); ++i) {
            if (!i || (all[i].first != all[i - 1].first)) {
                ids.push_back(i);
            }
        }
        ids.push_back(all.size());
        long long ans = 0;
        for (auto [cnt, x] : all) {
            ++lastt;
            for (int y : g[x]) {
                bad[y] = lastt;
            }
            bad[x] = lastt;
            for (int i = 0; i + 1 < ids.size(); ++i) {
                for (int j = ids[i]; j < ids[i + 1]; ++j) {
                    if (bad[all[j].second] != lastt) {
                        //cout << x << " " << all[j].second << ": " << v[x] << " " << v[all[j].second] << "   " << cnt << " " << all[j].first << ", val = " << 1LL * (v[x] + v[all[j].second]) * (cnt + all[j].first) << endl;
                        ans = max(ans, 1LL * (v[x] + v[all[j].second]) * (cnt + all[j].first));
                        break;
                    }
                }
            }
        }
        cout << ans << "\n";
        clr();
    }
    return 0;
}