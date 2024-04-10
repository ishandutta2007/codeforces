#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
const int o=1e6;
int n,tot,height[o],h[o],cnt;long long sm[o],f[o],g[o],ans;multiset<int> S[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
inline void upd(int nw)
{f[nw]=sm[nw];if((g[nw]=*S[nw].rbegin())<height[nw]) f[nw]+=height[nw]-g[nw],g[nw]=height[nw];}
void Dfs(int nw,int fa){
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa) Dfs(e[i].v,nw),sm[nw]+=f[e[i].v],S[nw].insert(g[e[i].v]);
	upd(nw);
}
void dfs(int nw,int fa){
	S[fa].erase(S[fa].find(g[nw]));sm[fa]-=f[nw];upd(fa);
	S[nw].insert(g[fa]);sm[nw]+=f[fa];upd(nw); 
	ans=min(ans,f[nw]+g[nw]);
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa) dfs(e[i].v,nw);
	S[nw].erase(S[nw].find(g[fa]));sm[nw]-=f[fa];upd(nw);
	S[fa].insert(g[nw]);sm[fa]+=f[nw];upd(fa);
}
int main(){
	scanf("%d",&n);tot=n;
	for(int i=1;i<=n;++i) scanf("%d",&height[i]),S[i].insert(0);
	for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),ad(u,v),ad(v,u);
	Dfs(1,0);ans=f[1]+g[1];
	for(int i=h[1];i;i=e[i].p) dfs(e[i].v,1);
	printf("%lld",ans);
	return 0;
}