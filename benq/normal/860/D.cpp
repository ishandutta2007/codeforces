#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

int n,m, visit[200001], par[200001];
vi adj[200001];
vector<vi> ans;

bool dfs(int x, int pre) {
    visit[x] = 1;
    vi cur;
    for (int i: adj[x]) if (i != pre) {
        if (visit[i]) {
            if (x < i) cur.pb(i);
        } else if (dfs(i,x)) cur.pb(i);
    }
    F0R(i,cur.size()/2) ans.pb({cur[2*i],x,cur[2*i+1]});
    if (cur.size() % 2 == 0) return 1;
    if (pre != -1) ans.pb({cur[cur.size()-1],x,pre});
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,m) {
	    int a,b; cin >> a >> b;
	    adj[a].pb(b), adj[b].pb(a);
	}
	FOR(i,1,n+1) if (!visit[i]) dfs(i,-1);
	cout << ans.size() << "\n";
	for (auto a: ans) cout << a[0] << " " << a[1] << " " << a[2] << "\n";
}

// read!
// ll vs. int!