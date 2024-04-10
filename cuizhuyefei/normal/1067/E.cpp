#include<bits/stdc++.h>
using namespace std;
const int mo = 998244353;
int n,f[666666],res,sz[666666],mi[666666];vector<int>e[666666];
void dfs(int u, int fa){
	sz[u]=1;f[u]=1;
	for(int i=0;i<e[u].size();i++)if(e[u][i]!=fa){
		int v=e[u][i];dfs(v,u);sz[u]+=sz[v];
		f[u]=1LL*f[u]*(mi[sz[v]]-f[v]+mo)%mo;
	}
	res=(res+(1LL*mi[sz[u]-1]-f[u])*mi[n-sz[u]])%mo;
}
int main(){
	scanf("%d",&n);for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		e[u].push_back(v);e[v].push_back(u);
	}
	mi[0]=1;for(int i=1;i<=n;i++)mi[i]=mi[i-1]*2%mo;
	dfs(1,0);res=(res*2%mo+mo)%mo;cout<<res;
	return 0;
}