#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define forall(x,i) for (int i=0;i<x.size();i++)
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n,m;
struct Edge{
	int to,nxt;
}edge[200010];
int cnt=1,last[100010];
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int fat[100010],son[100010],siz[100010],dep[100010];
int top[100010],id[100010],od[100010];
void dfs1(int x,int f,int d){
	fat[x]=f; dep[x]=d; siz[x]=1;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^f){
			dfs1(v,x,d+1);
			siz[x]+=siz[v];
			if (siz[v]>siz[son[x]]) son[x]=v;
		}
}
void dfs2(int x,int t){
	top[x]=t; id[x]=++*id; od[*id]=x;
	if (siz[x]==1) return;
	dfs2(son[x],t);
	for (int i=last[x],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)!=fat[x]&&v!=son[x])
			dfs2(v,v);
}
#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)
vector<int> e[262144];
int rev(int x){return x>m?x-m:x+m;}
void update(int x,int l,int r,int ql,int qr,int k){
	if (ql<=l&&r<=qr) return e[x].push_back(k),void();
	if (ql<=mid) update(ls,l,mid,ql,qr,k);
	if (mid<qr) update(rs,mid+1,r,ql,qr,k);
}
void work(int u,int v,int k){
	while (top[u]^top[v]){
		if (dep[top[u]]<dep[top[v]]) swap(u,v);
		update(1,1,n,id[top[u]],id[u],k);
		u=fat[top[u]];
	}
	if (u==v) return;
	if (dep[u]>dep[v]) swap(u,v);
	update(1,1,n,id[u]+1,id[v],k);
}
int idtot;
namespace T
{
struct Edge{
	int to,nxt;
}edge[10000010];
int cnt,last[10000010];
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int dfn[10000010],low[10000010],stk[10000010];
bool vis[10000010]; int col[10000010];
void tarjan(int x){
	dfn[x]=low[x]=++*dfn; stk[++*stk]=x; vis[x]=1;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if (!dfn[v=edge[i].to]){
			tarjan(v); low[x]=min(low[x],low[v]);
		}
		else if (vis[v]) low[x]=min(low[x],dfn[v]);
	if (low[x]^dfn[x]) return;
	++*col;
	do{
		int u=stk[*stk]; vis[u]=0; col[u]=*col;
	}while (stk[(*stk)--]^x);
}
void solve(){
	for (int i=1;i<=idtot;i++) if (!dfn[i]) tarjan(i);
	for (int i=1;i<=m;i++) if (col[i]==col[i+m]) return puts("NO"),void();
	puts("YES");
	for (int i=1;i<=m;i++) if (col[i]<col[i+m]) puts("1"); else puts("2");
}
}  //namespace T
void dfs3(int x,int l,int r,int u,int v){  //up down
	forall(e[x],i){
		int uu=++idtot,vv=++idtot,t=e[x][i];
		T::addedge(uu,u); T::addedge(v,vv);
		T::addedge(uu,rev(t)); T::addedge(vv,rev(t));
		T::addedge(t,u); T::addedge(t,vv+2);
		u=uu,v=vv;
	}
	int uu=++idtot,vv=++idtot;
	T::addedge(uu,u); T::addedge(v,vv);
	if (l==r) return;
	dfs3(ls,l,mid,uu,vv); dfs3(rs,mid+1,r,uu,vv);
}
#undef mid
#undef ls
#undef rs
int main()
{
	n=read();
	for (int i=1;i<n;i++) addedge(read(),read());
	dfs1(1,0,1); dfs2(1,1);
	m=read(); idtot=m<<1;
	for (int i=1;i<=m;i++){
		int a=read(),b=read(),c=read(),d=read();
		work(a,b,i); work(c,d,i+m);
	}
	idtot+=2;
	dfs3(1,1,n,idtot-1,idtot);
	T::solve();
	return 0;
}