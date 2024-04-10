#include<bits/stdc++.h>
typedef long long ll;
const int N=2e5+3;
int n,m,h[N],son[N],top[N],l[N],k,s;
ll ans;
std::vector<int>g[N];
void Dfs0(int u,int fa){
	for(int v:g[u])if(v!=fa)
		Dfs0(v,u),son[u]=h[son[u]]>h[v]?son[u]:v;
	h[u]=h[son[u]]+1;
}
void Dfs1(int u,int fa){
	if(!top[u])top[u]=u,l[++k]=h[u];
	if(son[u])top[son[u]]=top[u],Dfs1(son[u],u);
	for(int v:g[u])if(v!=son[u]&&v!=fa)
		Dfs1(v,u);
}
int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	Dfs0(1,0);
	Dfs1(1,0);
	std::sort(l+1,l+1+k,[=](const int&a,const int&b){return a>b;});
	ans=-(ll)n*n;
	for(int i=1;i<=m;i++){
		if(i<=k)s+=l[i];
		ans=std::max(ans,(ll)i*(n-i)-(s*2<=n?(ll)(n/2)*(n-n/2):(ll)s*(n-s)));
	}
	printf("%lld\n",ans);
	return 0;
}