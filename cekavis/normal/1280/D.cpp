#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 3005;
int T, n, m, a[N], siz[N];
pair<int,ll> f[N][N];
vector<int> e[N];
pair<int,ll> operator+(const pair<int,ll> &x, const pair<int,ll> &y){
	return make_pair(x.first+y.first, x.second+y.second);
}
void dfs(int u, int fa=0){
	siz[u]=1, f[u][0]=make_pair(0, a[u]);
	for(int v:e[u]) if(v!=fa){
		dfs(v, u);
		for(int i=siz[u]; i--;){
			for(int j=siz[v]; j; --j)
				f[u][i+j]=max(f[u][i+j], f[u][i]+f[v][j]);
			f[u][i]=f[u][i]+f[v][0];
		}
		siz[u]+=siz[v];
	}
	if(u>1) for(int i=siz[u]; i--;)
		f[u][i+1]=max(f[u][i+1], make_pair(f[u][i].first+(f[u][i].second>0), 0ll));
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; ++i){
			e[i].clear();
			fill(f[i], f[i]+n+1, make_pair(0, (ll)-1e18));
		}
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		for(int i=1, x; i<=n; ++i) scanf("%d", &x), a[i]=x-a[i];
		for(int i=1, x, y; i<n; ++i)
			scanf("%d%d", &x, &y), e[x].push_back(y), e[y].push_back(x);
		dfs(1);
		printf("%d\n", f[1][m-1].first+(f[1][m-1].second>0));
	}
	return 0;
}