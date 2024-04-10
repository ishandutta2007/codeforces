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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

int adj[22];
pair<int,pii> dp[1<<22];
int n, m;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	if (m == n*(n-1)/2) {
	    cout << 0;
	    return 0;
	}
	F0R(i,m) {
	    int a,b; cin >> a >> b; a--, b--;
	    adj[a] ^= 1<<b, adj[b] ^= 1<<a;
	}
	F0R(i,1<<n) dp[i].f = MOD;
	F0R(i,n) dp[1<<i].f = 0;
	F0R(i,1<<n) if (dp[i].f != MOD) 
	    F0R(j,n) if (i&(1<<j)) 
	        dp[i|adj[j]] = min(dp[i|adj[j]],{dp[i].f+1,{i,j}});
	
	int cur = (1<<n)-1;
	vi ans;
	while (dp[cur].f) {
	    ans.pb(dp[cur].s.s+1);
	    cur = dp[cur].s.f;
	}
	reverse(all(ans));
	cout << sz(ans) << "\n";
	for (int i: ans) cout << i << " ";
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!