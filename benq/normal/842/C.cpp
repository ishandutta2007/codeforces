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

int n, a[200001], ans[200001];
vi adj[200001];

void dfs(int pre, int no, int tot, set<int> cur) {
    ans[no] = tot;
    if (no == 1) ans[no] = a[no];
    
    set<int> cur1;
    for (int i: cur) {
        int t = __gcd(i,a[no]);
        ans[no] = max(ans[no],t);
        cur1.insert(t);
    }
    
    cur1.insert(tot);
    tot = __gcd(tot,a[no]);
    for (int i: adj[no]) if (i != pre) dfs(no,i,tot,cur1);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) cin >> a[i];
	F0R(i,n-1) {
	    int x,y; cin >> x >> y;
	    adj[x].pb(y);
	    adj[y].pb(x);
	}
	dfs(0,1,0,{});
	FOR(i,1,n+1) cout << ans[i] << " ";
}

// read!
// ll vs. int!