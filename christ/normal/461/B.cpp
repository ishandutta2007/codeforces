#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5+3, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
int dp[MN][2], color[MN]; vector<int> adj[MN];
void uadd (int &a, int b) {a += b; if (a >= MOD) a -= MOD;}
void umult (int &a, int b) {a = (ll)a*b%MOD;}
int inv (int base) {
	int exp = MOD-2, res = 1;
	while (exp) {
		if (exp&1) res = res*1LL*base%MOD;
		base = base*1LL*base%MOD;
		exp >>= 1;
	}
	return res;
}
void dfs (int cur, int p = -1) {
	dp[cur][1] = color[cur]; dp[cur][0] = !color[cur];
	for (int i : adj[cur]) if (i != p) {
		dfs(i,cur);
		if (color[cur]) {
			umult(dp[cur][1],dp[i][0]+dp[i][1]);
		} else {
			umult(dp[cur][0],dp[i][0]+dp[i][1]);
		}
	}
	if (!color[cur])
	for (int i : adj[cur]) {
		uadd(dp[cur][1],dp[cur][0]*1LL*inv(dp[i][0]+dp[i][1])%MOD*dp[i][1]%MOD);
	}
}
int main() {
	int n;
	scanf ("%d",&n);
	for (int i = 2; i <= n; i++) {
		int a; scanf ("%d",&a); adj[++a].push_back(i);
	}
	for (int i = 1; i <= n; i++) scanf ("%d",&color[i]);
	dfs(1);
	printf ("%d\n",dp[1][1]);
    return 0;
}