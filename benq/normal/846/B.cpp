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
const ll INF = 1e18;

int n,k,M, t[50];
ll dp[3000], dp1[3000];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k >> M;
	FOR(i,1,k+1) cin >> t[i];
	sort(t+1,t+k+1);
	FOR(i,1,k+1) t[i] += t[i-1];
	
	dp[0] = 0;
	FOR(i,1,3000) dp[i] = 1e18;
	F0R(i,n) {
	    F0R(x,3000) dp1[x] = INF;
	    F0R(j,k) F0R(x,3000) if (x+j<3000) dp1[x+j] = min(dp1[x+j],dp[x]+t[j]);
	    F0R(x,3000) if(x+k+1<3000) dp1[x+k+1] = min(dp1[x+k+1],dp[x]+t[k]);
	    F0R(x,3000) dp[x] = dp1[x];
	}
	
	int ans = 0;
	F0R(i,3000) if (dp[i] <= M) ans = i;
	cout << ans;
}

// read!
// ll vs. int!