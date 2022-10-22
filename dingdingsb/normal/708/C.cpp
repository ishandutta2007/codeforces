#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5;
int n,sz[N],maxson[N],f[N][2],g[N],h[N],ans[N];
vector<int>e[N];
void dfs1(int u,int p){
	sz[u]=1;
	for(auto v:e[u]){
		if(v==p)continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[maxson[u]])
			maxson[u]=v;
		int cur=(sz[v]<=n/2)?sz[v]:f[v][0];
		if(cur>f[u][0]){
			f[u][1]=f[u][0];
			f[u][0]=cur;
			g[u]=v;
		}
		else if(cur>f[u][1])
			f[u][1]=cur;
	}
}
void dfs2(int u,int p){
	ans[u]=1;
	if(sz[maxson[u]]>n/2)
		ans[u]=(sz[maxson[u]]-f[maxson[u]][0]<=n/2);
	else if(n-sz[u]>n/2)
		ans[u]=(n-sz[u]-h[u]<=n/2);
	for(auto v:e[u]){
		if(v==p)continue;
		int cur=(n-sz[u]<=n/2)?(n-sz[u]):h[u];
		h[v]=max(h[v],cur);
		h[v]=max(h[v],f[u][g[u]==v]);
		dfs2(v,u);
	}
}
signed main(){
	scanf("%d",&n);
	for(int i=2,u,v;i<=n;i++)
		scanf("%d%d",&u,&v),
		e[u].push_back(v),e[v].push_back(u);
	dfs1(1, 0), dfs2(1, 0);
    for(int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
}