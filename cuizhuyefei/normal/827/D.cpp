#include<bits/stdc++.h>
#define fi first
#define se second
#define lc(k) (k<<1)
#define rc(k) (k<<1|1)
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 404444;
int head[N],to[N],nxt[N],val[N],bel[N],edgenum,ans[N];
void add(int u, int v, int d, int b){
	to[++edgenum]=v;val[edgenum]=d;bel[edgenum]=b;
	nxt[edgenum]=head[u];head[u]=edgenum;
}
int n,m,f[N];bool mrk[N],vis[N];
struct edge{int u,v,d,ind;}e[N];
bool cmp(edge a,edge b){return a.d<b.d;}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int fa[N][18],mx[N][18],mn[N][18],dy[N],dep[N],dfn[N],R[N],num;
void DFS(int u, int Fa, int Dep){
	fa[u][0]=Fa;dep[u]=Dep;dfn[u]=++num;
	L(i,u)if(to[i]!=Fa)mx[to[i]][0]=val[i],DFS(to[i],u,Dep+1);
	R[u]=num;
}
void init(){
	rep(j,1,17)dy[1<<j]=j;
	rep(j,1,17)rep(i,1,n)if(dep[i]>=(1<<j))
		fa[i][j]=fa[fa[i][j-1]][j-1],mx[i][j]=max(mx[i][j-1],mx[fa[i][j-1]][j-1]);
}
int LCA(int u, int v){
	if(dep[u]<dep[v])swap(u,v);int del=dep[u]-dep[v];
	while(del){int bit=del&-del;del-=bit;u=fa[u][dy[bit]];}
	if(u==v)return u;
	per(i,17,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void umin(int &x, int y){x=x<y?x:y;}
int main() {
	read(n);read(m);
	rep(i,1,m)read(e[i].u),read(e[i].v),read(e[i].d),e[i].ind=i;
	sort(e+1,e+m+1,cmp);rep(i,1,n)f[i]=i;
	rep(i,1,m){
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y)mrk[i]=1,f[x]=y,add(e[i].u,e[i].v,e[i].d,e[i].ind),add(e[i].v,e[i].u,e[i].d,e[i].ind);
	}
	DFS(1,0,0);init();rep(i,1,n)rep(j,0,17)mn[i][j]=2e9;
	rep(i,1,m)if(!mrk[i]){
		int u=e[i].u,v=e[i].v,lca=LCA(u,v),res=0;
		int del=dep[u]-dep[lca];while(del){
			int bit=del&-del;del-=bit;res=max(res,mx[u][dy[bit]]);
			mn[u][dy[bit]]=min(mn[u][dy[bit]],e[i].d);u=fa[u][dy[bit]];
		}
		del=dep[v]-dep[lca];while(del){
			int bit=del&-del;del-=bit;res=max(res,mx[v][dy[bit]]);
			mn[v][dy[bit]]=min(mn[v][dy[bit]],e[i].d);v=fa[v][dy[bit]];
		}
		ans[e[i].ind]=res-1;
	}
	per(j,17,1)rep(i,1,n)if(dep[i]>=(1<<j))
		umin(mn[i][j-1],mn[i][j]),umin(mn[fa[i][j-1]][j-1],mn[i][j]);
	rep(i,1,m)if(mrk[i])
		if(dep[e[i].u]>dep[e[i].v])ans[e[i].ind]=mn[e[i].u][0]-1;
		else ans[e[i].ind]=mn[e[i].v][0]-1;
	rep(i,1,m)printf("%d ",ans[i]<=1e9?ans[i]:-1);
	return 0;
}