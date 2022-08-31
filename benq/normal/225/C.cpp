/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n,m,x,y;
int dp[1001][1001][2]; // column, num consecutive, color
int sum[2][1001];
char grid[1001][1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> x >> y;
	FOR(i,1,n+1) FOR(j,1,m+1) {
		char c; cin >> c;
		if (c == '#') sum[0][j] ++;
	}
	FOR(j,1,m+1) sum[1][j] = n-sum[0][j];
	
	F0R(i,1001) F0R(j,1001) F0R(k,2) dp[i][j][k] = MOD;
	dp[0][0][1] = dp[0][0][0] = 0;
	
	F0R(i,m) F0R(j,y+1) F0R(k,2) {
		if (j < y) dp[i+1][j+1][k] = min(dp[i+1][j+1][k],dp[i][j][k]+sum[k][i+1]);
		if (j >= x) 
			dp[i+1][1][k^1] = min(dp[i+1][1][k^1],dp[i][j][k]+sum[k^1][i+1]);
	}
	
	int ans = MOD;
	FOR(i,x,y+1) ans = min(ans,min(dp[m][i][0],dp[m][i][1]));
	cout << ans;
}