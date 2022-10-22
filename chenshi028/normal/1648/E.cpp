#include<cstdio>
#include<algorithm>
#include<utility>
#include<set>
#include<map>
using namespace std;
const int o=2e5+10;
int T,n,m,fa[o],Fa[o],sz[o],anc[o][20],ans[o][20],h[o],cnt,U,V,tot,L[o],R[o],bl[o],br[o],d[o];
set<int> s[o];pair<pair<int,int>,pair<int,int> > E[o];map<pair<int,int>,bool> mp;
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
int Fr(int x){return Fa[x]==x?x:Fa[x]=Fr(Fa[x]);}
struct Edge{int v,p,w;}e[o*2];
inline void ad(int U,int V,int W){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].w=W;}
inline void add(int U,int V,int W){if((U=Fr(U))^(V=Fr(V))) Fa[U]=V,ad(U,V,W),ad(V,U,W);}
void dfs(int nw,int fa,int u){
	if(U) return;
	if(!mp[make_pair(nw,u)]){U=nw;V=u;return;}
	for(int i=h[nw];i&&!U;i=e[i].p) if(e[i].v^fa) dfs(e[i].v,nw,u);
}
void Dfs(int nw,int fa,int u){
	if(U) return;
	dfs(u,0,nw);
	for(int i=h[nw];i&&!U;i=e[i].p) if(e[i].v^fa) Dfs(e[i].v,nw,u);
}
void ddfs(int nw){
	d[nw]=d[anc[nw][0]]+1;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^anc[nw][0])
		anc[e[i].v][0]=nw,ans[e[i].v][0]=e[i].w,ddfs(e[i].v);
}
inline bool cmp(pair<pair<int,int>,pair<int,int> > A,pair<pair<int,int>,pair<int,int> > B)
{return A.first.second<B.first.second;}
inline int query(int x,int y){
	int res=0;
	for(int i=19;i+1;--i) if(d[anc[x][i]]>=d[y]) res=max(res,ans[x][i]),x=anc[x][i];
	for(int i=19;i+1;--i) if(d[anc[y][i]]>=d[x]) res=max(res,ans[y][i]),y=anc[y][i];
	if(x==y) return res;
	for(int i=19;i+1;--i) if(anc[x][i]^anc[y][i])
		res=max(res,max(ans[x][i],ans[y][i])),x=anc[x][i],y=anc[y][i];
	return max(res,max(ans[x][0],ans[y][0]));
}
int main(){
	for(scanf("%d",&T);T--;cnt=0,mp.clear(),putchar('\n')){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;sz[i++]=1) h[fa[i]=Fa[i]=i]=0,s[i].clear(),s[i].insert(i);
		for(int i=1;i<=m;++i)
			scanf("%d%d%d",&E[i].second.first,&E[i].second.second,&E[i].first.first),E[i].first.second=i,
			mp[make_pair(E[i].second.first,E[i].second.second)]=mp[make_pair(E[i].second.second,E[i].second.first)]=1;
		sort(E+1,E+m+1);
		for(int i=1,u,v,w;i<=m;++i) if((u=fr(E[i].second.first))^(v=fr(E[i].second.second))){
			w=E[i].first.first;tot=0;
			if(sz[u]<sz[v]) swap(u,v);
			for(set<int>::iterator iter=s[v].begin();iter!=s[v].end();++iter){
				int t=tot;
				for(set<int>::iterator Iter=s[u].begin();Iter!=s[u].end();++Iter){
					Dfs(*Iter,U=V=0,*iter);
					if(U) L[++tot]=U,R[tot]=V,bl[tot]=*iter,br[tot]=*Iter;
				}
				for(int i=tot;i>t+1;--i) s[u].erase(br[i]),add(br[i],br[t+1],w);
			}
			for(int i=1;i<=tot;++i) if(Fr(L[i])^Fr(R[i])) s[v].erase(bl[i]),add(L[i],R[i],w);
			for(set<int>::iterator iter=s[v].begin();iter!=s[v].end();++iter) s[u].insert(*iter);
			sz[fa[v]=u]+=sz[v];
		}
		ddfs(1);
		for(int i=1;i<20;++i) for(int j=1;j<=n;++j)
			anc[j][i]=anc[anc[j][i-1]][i-1],ans[j][i]=max(ans[j][i-1],ans[anc[j][i-1]][i-1]);
		sort(E+1,E+m+1,cmp);
		for(int i=1;i<=m;++i) printf("%d ",query(E[i].second.first,E[i].second.second));
	}
	return 0;
}