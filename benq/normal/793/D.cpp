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

int n,k,m, ans = MOD, dp[80][80][80][2], don[80][80][80][2], dist[80][80];

int get(int done, int l, int r, int cur) {
	if (done == k) return 0;
	if (l>r) return MOD;
	if (don[done][l][r][cur]) return dp[done][l][r][cur];
	if (cur == 1) {
		FOR(i,l,r+1) {
			dp[done][l][r][cur] = min(dp[done][l][r][cur],get(done+1,l,i-1,1)+dist[r+1][i]);
			dp[done][l][r][cur] = min(dp[done][l][r][cur],get(done+1,i+1,r,0)+dist[r+1][i]);
		}
	} else {
		FOR(i,l,r+1) {
			dp[done][l][r][cur] = min(dp[done][l][r][cur],get(done+1,l,i-1,1)+dist[l-1][i]);
			dp[done][l][r][cur] = min(dp[done][l][r][cur],get(done+1,i+1,r,0)+dist[l-1][i]);
		}
	}
	don[done][l][r][cur] = 1;
	return dp[done][l][r][cur];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k >> m;
	F0R(i,80) F0R(j,80) dist[i][j] = MOD;
	F0R(a,80) F0R(b,80) F0R(c,80) F0R(d,2) dp[a][b][c][d] = MOD;
	F0R(i,m) {
		int u,v,c; cin >> u >> v >> c;
		u--,v--;
		dist[u][v] = min(dist[u][v],c);
	}
	F0R(i,n) {
		ans = min(ans,get(1,0,i-1,1));
		ans = min(ans,get(1,i+1,n-1,0));
	}
	if (ans == MOD) {
		cout << -1;
		return 0;
	}
	cout << ans;
}