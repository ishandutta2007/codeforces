#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, MOD = 1e9 + 7;
int v[MN], cntDown[MN], cntUp[MN];
long long down[MN],up[MN];
vector<int> adj[MN];
void madd (long long &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
void dfs (int cur, int p = -1) {
	down[cur] = v[cur]; cntDown[cur] = 1;
	for (int i : adj[cur]) if (i != p) {
		dfs(i,cur);
		cntDown[cur] += cntDown[i];
		down[cur] = ((long long)v[cur] * cntDown[i] % MOD + down[cur] - down[i] + MOD) % MOD;
	}
}
void dfs2 (int cur, int p = -1) {
	if (~p) {
		cntUp[cur] = cntUp[p] + cntDown[p] - cntDown[cur];
		up[cur] = ((long long)v[cur] * cntUp[p] % MOD - up[p] + MOD) % MOD;
		long long sumDown = (down[p] - ((long long)v[p] * cntDown[cur] % MOD - down[cur] + MOD)% MOD + MOD) % MOD;
		madd(up[cur],((long long)v[cur] * (cntDown[p] - cntDown[cur]) % MOD - sumDown + MOD)% MOD); 
		up[cur] = (up[cur] - (v[cur] - v[p] + MOD) % MOD + MOD) % MOD;
		up[cur] = (up[cur] + v[cur]) % MOD;
	} else up[cur] = v[cur], cntUp[cur] = 1;
	for (int i : adj[cur]) if (i != p) dfs2(i,cur);
}
int main() {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&v[i]);
		v[i] += MOD;
		if (v[i] >= MOD) v[i] -= MOD;
	}
	for (int i = 1; i < n; i++) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dfs(1);
	dfs2(1);
	long long ret = 0;
	for (int i = 1; i <= n; i++) {
		ret = (ret + up[i] + down[i] - v[i] + MOD) % MOD;
	}
	printf ("%lld\n",ret);
    return 0;
}