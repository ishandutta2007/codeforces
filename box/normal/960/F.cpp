// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

set<pii> ans[100005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int gb = 0;
    int n, m; cin >> n >> m;
    rep1(i, n) ans[i].insert({-1, 0});
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        int cn = prev(ans[u].lower_bound({w,-1}))->se+1;
        gb = max(gb, cn);
        auto [it, _] = ans[v].insert({w,cn});
        if(next(it) != ans[v].end() && next(it)->fi == w) {
            ans[v].erase(it);
            continue;
        }
        if(it != ans[v].begin() && prev(it)->se >= cn) {
            ans[v].erase(it);
            continue;
        }
        if(it != ans[v].begin() && prev(it)->fi == w) ans[v].erase(prev(it));
        it = next(it);
        while(it != ans[v].end() && cn >= it->se) it = ans[v].erase(it);
    }
    cout << gb << endl;
}