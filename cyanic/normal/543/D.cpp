/*
N(p2p3p4pnipi
i
(mod 1e9+7)
n<=200000
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 200009;
const int MOD = 1000000007;
int f[maxn], ans[maxn], fa[maxn];
vector<int> e[maxn];
int n;

int power(int x, int p){
	int res = 1;
	while (p){
		if (p&1) res = 1LL * res * x % MOD;
		x = 1LL * x * x % MOD; p >>= 1;
	}
	return res;
}

void dfs1(int u){
	f[u] = 1;
	for (int i=0; i<e[u].size(); i++)
		if (e[u][i] != fa[u]){
			dfs1(e[u][i]);
			f[u] = 1LL * f[u] * (f[e[u][i]] + 1) % MOD;
		}
}

void dfs2(int u, int g){
	ans[u] = 1LL * f[u] * g % MOD;
	for (int i=0; i<e[u].size(); i++)
		if (e[u][i] != fa[u] && f[e[u][i]] != MOD-1)
			dfs2(e[u][i], (1LL * g * f[u] % MOD * power(f[e[u][i]]+1, MOD-2) % MOD + 1) % MOD);
		else if (e[u][i] != fa[u]){
			int res = 1;
			for (int j=0; j<e[u].size(); j++)
				if (e[u][j] != fa[u] && i != j)
					res = 1LL * res * (f[e[u][j]] + 1) % MOD;
			dfs2(e[u][i], (1LL * g * res % MOD + 1) % MOD);
		}
}

int main(){
	scanf("%d", &n);
	for (int i=2; i<=n; i++){
		scanf("%d", &fa[i]);
		e[fa[i]].push_back(i);
	}
	dfs1(1); dfs2(1, 1);
	for (int i=1; i<=n; i++) printf("%d ", ans[i]);
	return 0;
}