#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
ll G, B;
int T, n, siz[N];
vector<pair<int,int>> e[N];
void dfs(int u, int fa=0){
	siz[u]=1;
	for(auto &v:e[u]) if(v.first!=fa)
		dfs(v.first, u), G+=v.second*(siz[v.first]&1), siz[u]+=siz[v.first],
		B+=(ll)min(siz[v.first], n*2-siz[v.first])*v.second;
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1; i<=n*2; ++i) e[i].clear();
		G=B=0;
		for(int i=1, x, y, z; i<n*2; ++i)
			scanf("%d%d%d", &x, &y, &z),
			e[x].emplace_back(y, z), e[y].emplace_back(x, z);
		dfs(1);
		printf("%lld %lld\n", G, B);
	}
	return 0;
}