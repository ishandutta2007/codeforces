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

int n,m,k,x;
vi adj[100001];
ll dp[100001][3][11], ans = 0;
ll tmp[11];

void dfs(int pre, int num) {
    // < k, = k, > k
    dp[num][0][0] = k-1;
    dp[num][1][1] = 1;
    dp[num][2][0] = m-k;
    for (int i: adj[num]) if (i != pre) {
        dfs(num,i);
        
        // update dp[num][0]
        memset(tmp,0,sizeof tmp);
        F0R(k,11) F0R(k1,11-k) tmp[k+k1] = (tmp[k+k1]+dp[num][0][k]*(dp[i][0][k1]+dp[i][1][k1]+dp[i][2][k1])) % MOD;
        F0R(k,11) dp[num][0][k] = tmp[k];
        
        // update dp[num][1]
        memset(tmp,0,sizeof tmp);
        F0R(k,11) F0R(k1,11-k) tmp[k+k1] = (tmp[k+k1]+dp[num][1][k]*dp[i][0][k1]) % MOD;
        F0R(k,11) dp[num][1][k] = tmp[k];
        
        // update dp[num][2]
        memset(tmp,0,sizeof tmp);
        F0R(k,11) F0R(k1,11-k) tmp[k+k1] = (tmp[k+k1]+dp[num][2][k]*(dp[i][0][k1]+dp[i][2][k1])) % MOD;
        F0R(k,11) dp[num][2][k] = tmp[k];
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	F0R(i,n-1) {
	    int u,v; cin >> u >> v;
	    adj[u].pb(v), adj[v].pb(u);
	}
	cin >> k >> x;
	dfs(0,1);
	F0R(i,x+1) F0R(j,3) ans = (ans+dp[1][j][i]) % MOD;
	cout << ans;
}

// read!
// ll vs. int!