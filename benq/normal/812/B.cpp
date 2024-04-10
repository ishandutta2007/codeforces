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

int n,m, dp[16][2];
string build[16];

bool emp (string s) {
    for (char c: s) if (c != '0') return 0;
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	dp[0][1] = MOD;
	cin >> n >> m;
	FORd(i,1,n+1) cin >> build[i];
	while (n > 0 && emp(build[n])) n--;
	
	FOR(i,1,n+1) {
    	int lo = m+1, hi = 0;
    	F0R(j,m+2) if (build[i][j] == '1') hi = j;
    	F0Rd(j,m+2) if (build[i][j] == '1') lo = j;
	    if (i != n) {
    	    dp[i][0] = dp[i-1][1]+m+2;
    	    dp[i][1] = dp[i-1][0]+m+2;
    	    dp[i][0] = min(dp[i][0],dp[i-1][0]+2*hi+1);
    	    dp[i][1] = min(dp[i][1],dp[i-1][1]+2*(m+1-lo)+1);
	    } else {
	        dp[i][0] = dp[i-1][0]+hi;
	        dp[i][1] = dp[i-1][1]+(m+1-lo);
	    }
	}
	cout << min(dp[n][0],dp[n][1]);
}

// read!
// ll vs. int!