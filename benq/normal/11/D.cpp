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

int n,m;
bool adj[19][19];
ll dp[1<<18][18], ans;

void solve(int mx) {
	F0R(i,1<<mx) F0R(j,mx) dp[i][j] = 0;
	F0Rd(i,mx) if (adj[mx][i]) dp[1<<i][i] = 1;
	
	F0R(i,1<<mx) F0R(j,mx) if (i&(1<<j)) {
		if (__builtin_popcount(i) > 1 && adj[j][mx]) ans += dp[i][j];
		F0R(k,mx) if (!(i&(1<<k)) && adj[j][k]) 
			dp[i^(1<<k)][k] += dp[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,m) {
		int a,b; cin >> a >> b; a--, b--;
		adj[a][b] = adj[b][a] = 1;
	}
	F0Rd(i,n) solve(i);
	cout << ans/2;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!