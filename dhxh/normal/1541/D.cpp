#include <bits/stdc++.h>

using namespace std;

const int maxn = 200 + 5;
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;

int w[maxn];

vector <int> e[maxn];

int n;

long long f[maxn][maxn];

int fa[maxn][10];
int dep[maxn];

long long ans = 0;
long long invn;

long long qpow(long long b, long long x){
	long long ret = 1;
	while(x){
		if(x & 1){
			ret = ret * b % mod;
		}
		x >>= 1;
		b = b * b % mod;
	}
	return ret;
}

void dfs(int x){
	for(int i=0;fa[x][i];i++) fa[x][i + 1] = fa[fa[x][i]][i];
	
	for(auto y : e[x]){
		if(y == fa[x][0]) continue;
		fa[y][0] = x;
		dep[y] = dep[x] + 1;
		dfs(y);
	}
}

int lca(int x, int y){
	if(dep[y] > dep[x]) swap(x, y);
	for(int i=8;i>=0;i--){
		if((dep[x] - dep[y]) & (1 << i)){
			x = fa[x][i];
		}
	}
	
	if(x == y) return x;
	
	for(int i=8;i>=0;i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i], y = fa[y][i];
		}
	}
	
	return fa[x][0];
}

void solve(int x){
	int i, j;
	dep[x] = 1;
	dfs(x);
	for(i=1;i<=n;i++){
		for(j=1;j<i;j++){
			int l = lca(i, j);
			if(l == i){
				ans = (ans + invn) % mod;
			}else if(l != j){
				ans = (ans + f[dep[i] - dep[l]][dep[j] - dep[l]] * invn) % mod;
			}
		}
	}
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &n);
	
	for(i=0;i<=n;i++) f[0][i] = 1;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			f[i][j] = (f[i - 1][j] + f[i][j - 1]) * inv2 % mod;
		}
	}
	
	invn = qpow(n, mod - 2);
	
	for(i=1;i<n;i++){
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	for(i=1;i<=n;i++){
		memset(fa, 0, sizeof(fa));
		memset(dep, 0, sizeof(dep));
		solve(i);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}