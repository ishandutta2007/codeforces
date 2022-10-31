#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,vector<int>>> a(n);
    vector<int> c;
    for(int i = 0; i < n; ++i) {
        vector<int> b(m);
        for(int j = 0; j < m; ++j) {
            cin >> b[j];
            c.push_back(b[j]);
        }
        int w;
        cin >> w;
        a[i] = {w, b};
    }
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    vector<int> cnt(c.size());
    for(int i = 0; i < n; ++i) {
        for(auto &x : a[i].second) {
            x = lower_bound(c.begin(), c.end(), x) - c.begin();
            cnt[x] += 1;
        }
    }
    sort(a.begin(), a.end());
    const int B = 1000;
    vector<int> id(c.size(), -1); int tot = 0;
    vector<bitset<100000>> bs(B);
    for(int i = 0; i < n; ++i) {
        for(auto x : a[i].second) {
            if(cnt[x] >= B) {
                if(id[x] == -1) {
                    id[x] = ++tot;
                    bs[tot].set();
                }
                bs[id[x]][i] = 0;
            }
        }
    }
    int ans = 2e9 + 5;
    bitset<100000> cur;
    cur.set();
    vector<int> vis(c.size());
    for(int i = 0; i < n; ++i) {
        if(a[i].first >= ans) break;
        for(auto x : a[i].second) {
            vis[x] = 1;
            if(cnt[x] >= B) {
                cur &= bs[id[x]];
            }
        }
        for(int j = cur._Find_first(); j < n; j = cur._Find_next(j)) {
            if(a[i].first + a[j].first >= ans) break;
            int ok = 1;
            for(auto x : a[j].second) {
                if(vis[x]) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                ans = a[i].first + a[j].first;
                break;
            }
        }
        for(auto x : a[i].second) {
            vis[x] = 0;
        }
        cur.set();
    }
    if(ans == 2e9 + 5) cout << -1 << '\n';
    else cout << ans << '\n';
}