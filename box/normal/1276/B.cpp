// writer: piggydan
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using ordered_set=tree<int, null_type, std::less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ll=long long;
using pii=pair<int, int>;
const ll MOD = 998244353;
//#define int ll

vector<int> elist[200005];

int a, b;
bool vist[200005];

int reachable(int node, int donot) {
    if(node == donot || vist[node]) return 0;
    vist[node] = 1; int ans = 1;
    for(int i:elist[node]) {
        ans += reachable(i, donot);
    }
    return ans;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) {
	    int n, m; cin >> n >> m >> a >> b;
	    iter(i, 1, n+1) {
	        elist[i].clear();
	    }
	    rep(i, m) {
	        int u, v; cin >> u >> v;
	        elist[u].pb(v);
	        elist[v].pb(u);
	    }
	    memset(vist, 0, sizeof vist);
	    ll ans = n-reachable(a, b)-1;
	    memset(vist, 0, sizeof vist);
	    ans *= n-reachable(b, a)-1;
	    cout << ans << endl;
	}
}