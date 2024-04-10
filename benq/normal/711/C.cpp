#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m,k; cin >> n >> m >> k;
	ll p[100][101], dp[101][101][101];
	F0R(i,101) F0R(j,101) F0R(k,101) dp[i][j][k] = 1000000000000000;
	vi c(n); F0R(i,n) cin >> c[i];
	F0R(i,n) FOR(j,1,m+1) cin >> p[i][j];
	// dp on current pos, number of colors, current color
	if (c[0] == 0) FOR(i,1,m+1) dp[1][1][i] = p[0][i];
	else dp[1][1][c[0]] = 0;
	FOR(i,1,n) {
		if (c[i]) {
			// look at this
			FOR(j,1,i+1) FOR(k,1,m+1) {
				if (k == c[i]) dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
			    else dp[i+1][j+1][c[i]] = min(dp[i+1][j+1][c[i]],dp[i][j][k]);
			}
		} else {
			FOR(j,1,i+1) FOR(k,1,m+1) FOR(z,1,m+1) {
			    if (k == z) dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]+p[i][k]);
			    else dp[i+1][j+1][z] = min(dp[i+1][j+1][z], dp[i][j][k]+p[i][z]);
			}
		}
	}
	// FOR(i,1,n+1) FOR(j,1,i+1) FOR(k,1,m+1) cout << i << " " << j << " " << k << " " << dp[i][j][k] << "\n";
	ll ans = LLONG_MAX;
	FOR(i,1,m+1) ans = min(ans,dp[n][k][i]);
	if (ans >= 1000000000000000) cout << -1;
	else cout << ans;
}