#include<bits/stdc++.h>
const int N=2e5+3;
int n,f[N],fl,fa[N],deg[N],q[N],l,r;
std::vector<int>g[N],g1[N];
void Dfs(int u){
	int v;
	std::vector<int>b[2];
	for(int i=0;i<g[u].size();i++)if((v=g[u][i])!=fa[u]){
		fa[v]=u;
		Dfs(v);
		b[f[v]].push_back(v);
	}
	if(fa[u]){
		f[u]=b[1].size()<=b[0].size();
		b[f[u]].push_back(u);
	}
	if(b[0].size()>b[1].size()||b[0].size()<b[1].size()-1)fl=0;
	else for(int w,l=1;b[0].size()||b[1].size();){
		int o=b[1].size()>b[0].size();
		w=b[o].back();
		g1[l].push_back(w),++deg[w];
		b[o].pop_back(),l=w;
	}
}
int main(){
	int u,v;
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	for(u=1;u<=n;u++)g[u].clear(),g1[u].clear(),deg[u]=0;
	fl=1,l=0,r=-1;
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	fa[1]=0,Dfs(1);
	if(!fl){puts("NO");continue;}
	puts("YES");
	for(u=1;u<=n;u++)if(!deg[u])q[++r]=u;
	for(;l<=r;){
		u=q[l++];
		if(fa[u])printf("%d %d\n",u,fa[u]);
		for(int i=0;i<g1[u].size();i++){
			v=g1[u][i];
			--deg[v];
			if(!deg[v])q[++r]=v;
		}
	}
	}return 0;
}