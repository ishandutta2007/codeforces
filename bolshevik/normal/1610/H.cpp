#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
const int o=3e5+10;
int n,m,anc[o][20],d[o],dfn[o],ed[o],h[o],cnt,tot,b[o],ans,a[o];pair<int,int> pr[o],pr2[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
inline int lowbit(int x){return x&-x;}
inline void modify(int pos,int val){for(;pos<=n;pos+=lowbit(pos)) b[pos]+=val;}
inline int query(int pos){int res=0;for(;pos;pos-=lowbit(pos)) res+=b[pos];return res;}
void dfs(int nw){
	d[nw]=d[anc[nw][0]]+1;dfn[nw]=++cnt;
	for(int i=h[nw];i;i=e[i].p) anc[e[i].v][0]=nw,dfs(e[i].v);
	ed[nw]=cnt;
}
inline bool cmp(pair<int,int> A,pair<int,int> B){return d[A.first]>d[B.first];}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;++i) scanf("%d",&anc[i][0]),ad(anc[i][0],i);
	for(int i=1;i<20;++i) for(int j=1;j<=n;++j) anc[j][i]=anc[anc[j][i-1]][i-1];
	cnt=0;dfs(1);cnt=0;
	for(int u,v,p;m--;){
		scanf("%d%d",&u,&v);
		if(d[u]>d[v]) swap(u,v);
		if(dfn[u]>dfn[p=v]||ed[u]<ed[v]){pr2[++tot]=make_pair(u,v);continue;}
		for(int i=19;i+1;--i) if(d[anc[p][i]]>d[u]) p=anc[p][i];
		if(p==v){printf("-1");return 0;}
		pr[++cnt]=make_pair(p,v);
	}
	sort(pr+1,pr+cnt+1,cmp);
	for(int i=1,u,v;i<=cnt;++i) if(query(dfn[v=pr[i].second]-1)==query(dfn[u=pr[i].first]-1))
		if(query(ed[u])==query(ed[v])) ++ans,modify(dfn[pr[i].first],1),++a[pr[i].first];
	for(int i=n;i>1;--i) a[anc[i][0]]+=a[i];
	for(int i=1,u,v;i<=tot;++i){
		u=pr2[i].first;v=pr2[i].second;
		if(ans==a[u]+a[v]){++ans;break;}
	}
	printf("%d",ans);
	return 0;
}