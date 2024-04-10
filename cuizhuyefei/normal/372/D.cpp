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
const int N = 204000;
int n,k,head[N],nxt[N],to[N],edgenum;
void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
int fa[N][18],dep[N],dy[N],dfn[N],num;
void Dfs(int u, int Fa, int Dep) {
	fa[u][0]=Fa; dep[u]=Dep; dfn[u]=++num;
	L(i,u) if (to[i]!=Fa) Dfs(to[i],u,Dep+1);
}
void init() {
	rep(j,1,17) dy[1<<j]=j;
	rep(j,1,17) rep(i,1,n)
		fa[i][j]=dep[i]>=(1<<j) ? fa[fa[i][j-1]][j-1] : 0;
}
int LCA(int u, int v) {
	if (dep[u]<dep[v]) swap(u,v); int del=dep[u]-dep[v];
	while (del){int bit=del&-del; del-=bit; u=fa[u][dy[bit]];}
	if (u==v) return u;
	per(j,17,0) if (fa[u][j]!=fa[v][j]) u=fa[u][j],v=fa[v][j];
	return fa[u][0];
}
struct node {
	int u;
	bool operator < (const node &x) const {
		return dfn[u]<dfn[x.u];
	}
}; set<node> Set;

void add(int u, int &res, int xs) {
//	printf("add %d %d\n",u,xs);
	node x; x.u=u; 
	if (Set.empty()) {Set.insert(x); res=1; return;}
	if (Set.size()==1&&xs==-1) {Set.clear(); res=0; return;}
	set<node>::iterator pre,nxt=Set.upper_bound(x),pre1=Set.lower_bound(x);pre=pre1;pre--;
//	pre=nxt; pre--; if ((*pre).u==u) pre--; pre1=pre; pre1++;
//	printf("QAQ %d %d %d\n",u,(*pre).u,(*nxt).u);
	/*if (nxt==Set.end()) {
		if (xs==1) Set.insert(x); else Set.erase(x);
		int lca=LCA(u,(*pre).u);
		res+=xs*(dep[u]+dep[(*pre).u]-dep[lca]*2); return;
	}
	if (pre1==Set.begin()) {
		if (xs==1) Set.insert(x); else Set.erase(x);
		int lca=LCA(u,(*nxt).u); 
		res+=xs*(dep[u]+dep[(*nxt).u]-dep[lca]*2); return;
	}*/
	if (nxt==Set.end()) nxt=Set.begin();
	if (pre1==Set.begin()) pre=Set.end(),pre--;
	if (xs==1) Set.insert(x); else Set.erase(x);
	int lca1=LCA(u,(*nxt).u),lca2=LCA(u,(*pre).u);
	res+=xs*(dep[u]-dep[lca1]-dep[lca2]+dep[LCA((*pre).u,(*nxt).u)]);
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(k);
	rep(i,2,n) {int x,y;read(x);read(y);add(x,y);add(y,x);}
	Dfs(1,0,0); init(); int now=0,r=0,ans=0;
//	rep(i,1,n) printf("%d : %d\n",i,dfn[i]);
	rep(l,1,n) {
		while (r<n&&now<=k) {
			add(++r,now,1); if (now>k) {add(r--,now,-1); break;}
		//	printf("<< %d %d %d\n",l,r,now);
		}
		ans=max(ans,r-l+1); //printf("%d %d %d\n",l,r,now);
		add(l,now,-1); //printf("<< %d %d %d\n",l+1,r,now);
	}
	cout<<ans;
	return 0;
}