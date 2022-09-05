#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 400004;
int n,m,q,f[N];
int bel[N];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void merge(int x, int y) {
	int fx=find(x),fy=find(y); f[fx]=fy;
}
int head[N],to[N],nxt[N],edgenum;
void ADD(int u, int v) {
	merge(u,v); to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
//	printf("edge %d %d\n",u,v);
}
bool vis[N];
int fa[N][18],dep[N],dy[N],v1[N],v2[N];
void dfs(int u, int Fa, int Dep) {
	dep[u]=Dep; fa[u][0]=Fa; vis[u]=1; 
//	printf("%d : %d %d\n",u,dep[u],fa[u][0]);
	L(i,u) if (to[i]!=Fa) dfs(to[i],u,Dep+1);
}
void init_lca() {
	rep(i,1,17) dy[1<<i]=i;
	rep(j,1,17) rep(i,1,n) 
		fa[i][j]=(dep[i]>=(1<<j)) ? fa[fa[i][j-1]][j-1] : 0;
}
int LCA(int u, int v) {
	if (dep[u]<dep[v]) swap(u,v); int del=dep[u]-dep[v];
	while (del) {int bit=del&-del; del-=bit; u=fa[u][dy[bit]];}
	if (u==v) return u;
	per(i,17,0) if (fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i]; //WA4
	return fa[u][0];
}
struct Tarjan {
	int head[N],to[N],nxt[N],edgenum,is_cut[N];
	Tarjan() {edgenum=1;}
	void add(int u, int v) {
		to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
	}
	int dfn[N],low[N],num,cnt;
	void tarjan(int u, int fa) {
		dfn[u]=low[u]=++num;
		L(i,u) if (!dfn[to[i]]) {
			tarjan(to[i],u); low[u]=min(low[u],low[to[i]]);
			if (low[to[i]]>dfn[u]) {
				is_cut[i>>1]=1;
			}
		} else if (to[i]!=fa&&dfn[to[i]]<dfn[u]) {
			low[u]=min(low[u],dfn[to[i]]);
		}
	}
	void dfs(int u) {
		bel[u]=cnt;
		L(i,u) if (!is_cut[i>>1]&&bel[to[i]]!=cnt) dfs(to[i]);
	}
	void solve() {
		rep(i,1,n) if (!dfn[i]) tarjan(i,0);
		rep(i,1,n) if (!bel[i]) {cnt++;dfs(i);} //WA2
		rep(u,1,n) L(i,u) if (bel[u]!=bel[to[i]]) ADD(bel[u],bel[to[i]]);
	}
} supy;
void GG() {puts("No"); exit(0);}
void DFS(int u, int fa) {
//	vis[u]=1; //WA1
	L(i,u) if (to[i]!=fa) {DFS(to[i],u); v1[u]+=v1[to[i]]; v2[u]+=v2[to[i]];}
	if (v1[u]>0&&v2[u]>0) GG();
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(m); read(q); rep(i,1,n) f[i]=i; int x,y;
	rep(i,1,m) {read(x);read(y);supy.add(x,y);supy.add(y,x);}
	supy.solve(); n=supy.cnt; rep(i,1,n) if (!vis[i]) dfs(i,0,0); init_lca();
	while (q--) {
		int x,y; read(x); read(y); x=bel[x]; y=bel[y];
		int fx=find(x),fy=find(y);
		if (fx!=fy) GG();
		int lca=LCA(x,y);
		v1[x]++; v1[lca]--; v2[y]++; v2[lca]--;
	//	printf("Q %d %d %d\n",x,y,lca);
	}
	rep(i,1,n) if (dep[i]==0) DFS(i,0); //WA3: root!
	puts("Yes");
	return 0;
}