#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define pb push_back
 
const int MOD = 1000000007, sz = 44;

vi adj[101];
int depth[101],n,k;
ll rec[101][21][sz];

ll query(int node, int a1, int a2, int b1, int b2) {
	if (a2<0 || b2<0) return 0;
	ll ans = rec[node][a2][b2];
	if (a1) ans -= rec[node][a1-1][b2];
	if (b1) ans -= rec[node][a2][b1-1];
	if (a1>0 && b1>0) ans += rec[node][a1-1][b1-1];
	ans %= MOD;
	while (ans<0) ans += MOD;
	return ans;
}

void filldepth(int node, int par) {
	depth[node] = 1;
	for (int i: adj[node]) if (i != par) {
		filldepth(i,node);
		depth[node] = max(depth[node],depth[i]+1);
	}
}

ll f(int node, int par, int mxnot, int mnfil) {
	ll t1 = 1, t2 = 1, t3 = 1, t4 = 1;
	for (int i: adj[node]) if (i != par) {
		t1 = t1*query(i,0,mxnot,mnfil,sz-1) % MOD;
		t2 = t2*query(i,0,mxnot-1,mnfil,sz-1) % MOD;
		t3 = t3*query(i,0,mxnot,mnfil+1,sz-1) % MOD;
		t4 = t4*query(i,0,mxnot-1,mnfil+1,sz-1) % MOD;
	}
	ll ans = (t1-t2-t3+t4) % MOD;
	while (ans<0) ans += MOD;
	return ans;
}

void dp(int node, int par) {
	for (int i: adj[node]) if (i != par) dp(i,node);

	rec[node][0][1] = 1;
	for (int i: adj[node]) if (i != par) {
		ll temp = query(i,0,k,1,sz-1);
		rec[node][0][1] = (rec[node][0][1]*temp) % MOD;
	}
	
	FOR(i,1,k+1) FOR(j,2,2*k+2) 
		if (i+j <= k+2) rec[node][0][j] = (rec[node][0][j]+f(node,par,i-1,j-1)) % MOD;
		else rec[node][i][j] = f(node,par,i-1,j-1);
	
	if (depth[node] <= k) rec[node][depth[node]][sz-1] = 1;
	F0R(i,k+1) F0R(j,sz) {
		if (i) rec[node][i][j] += rec[node][i-1][j];
		if (j) rec[node][i][j] += rec[node][i][j-1];
		if (i>0 &&j>0) rec[node][i][j] -= rec[node][i-1][j-1];
		rec[node][i][j] %= MOD;
		while (rec[node][i][j]<0) rec[node][i][j] += MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	F0R(i,n-1) {
		int u,v; cin >> u >> v;
		adj[u].pb(v), adj[v].pb(u);
	}
	filldepth(1,1);
	dp(1,1);
	cout << rec[1][0][sz-1];
}