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
#define SZ(x) ((int)x.size())
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
const int N = 202000, mo = 1e9+7, M = 30000000;
int head[N],n,q,a[N],to[N],nxt[N],edgenum;
void addedge(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u];head[u]=edgenum;
}
int fa[N][18],dep[N];
void dfs(int u, int Fa, int Dep) {
	dep[u]=Dep; fa[u][0]=Fa;
	L(i,u) if (to[i]!=Fa) dfs(to[i],u,Dep+1);
}
void init(){
	dfs(1,0,0);
	rep(j,1,17) rep(i,1,n)
		fa[i][j]=dep[i]>=(1<<j)?fa[fa[i][j-1]][j-1]:0;
}
int LCA(int u, int v) {
	if (dep[u]<dep[v])swap(u,v);int del=dep[u]-dep[v];
	rep(j,0,17) if ((del>>j)&1) u=fa[u][j];
	if (u==v) return u;
	per(j,17,0) if (fa[u][j]!=fa[v][j]) u=fa[u][j],v=fa[v][j];
	return fa[u][0];
}
inline int min(int a, int b) {return a<b?a:b;}
struct node {
	int index,p,a,xs; //p^a
};
vector<node> mrk[N]; vector<Pii> ans[N]; //PI(pi^ai)

int lc[M],rc[M],v1[M],sz,rt[10000200];//,v2[M];
inline void ins(int &k, int v, int l, int r, int xs) {
	if (!k) k=++sz; v1[k]+=xs;if (l==r) return;// v2[k]+=v*xs; 
	int mid=(l+r)>>1; 
	if (v<=mid) ins(lc[k],v,l,mid,xs); else ins(rc[k],v,mid+1,r,xs);
}
inline int query(int k, int p, int l, int r) {
	if (!k||l==r) return v1[k]*min(p,l);
	int mid=(l+r)>>1; int res=0;
	if (p>l) res+=query(lc[k],p,l,mid); else res+=v1[lc[k]]*p;
	if (p>mid+1) res+=query(rc[k],p,mid+1,r); else res+=v1[rc[k]]*p;
	return res;
}
void add(int x, int xs) {
	for(int j=2; j*j<=x;j++) if (x%j==0) {
		int cnt=0; while (x%j==0) x/=j,cnt++; ins(rt[j],cnt,1,23,xs);
	}
	if (x>1) ins(rt[x],1,1,23,xs);
}
void DFS(int u, int fa) {
	add(a[u],1); per(i,SZ(mrk[u])-1,0) {
		int p=mrk[u][i].p,a=mrk[u][i].a,xs=mrk[u][i].xs;
		ans[mrk[u][i].index].push_back(Pii(p,xs*query(rt[p],a,1,23)));
	}
	L(i,u) if (to[i]!=fa) DFS(to[i],u);
	add(a[u],-1);
}
int power(int a, int n) {
	if (n<0) n+=mo-1; int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo;
		n>>=1;
	}
	return res;
}
int main() { //freopen("1.in","r",stdin);
	read(n);rep(i,1,n-1) {int u,v;read(u);read(v);addedge(u,v);addedge(v,u);}
	rep(i,1,n)read(a[i]); read(q); init();
	rep(i,1,q) {
		int u,v,x;read(u);read(v);read(x);int lca=LCA(u,v);
		for(int j=2; j*j<=x;j++) if (x%j==0) {
			int cnt=0; while (x%j==0) x/=j,cnt++;
			mrk[u].push_back((node){i,j,cnt,1});
			mrk[v].push_back((node){i,j,cnt,1});
			mrk[lca].push_back((node){i,j,cnt,-1});
			mrk[fa[lca][0]].push_back((node){i,j,cnt,-1});
		}
		if (x>1) { int cnt=1;
			mrk[u].push_back((node){i,x,cnt,1});
			mrk[v].push_back((node){i,x,cnt,1});
			mrk[lca].push_back((node){i,x,cnt,-1});
			mrk[fa[lca][0]].push_back((node){i,x,cnt,-1});
		}
	}
	DFS(1,0);
	rep(i,1,q) {
		ll res=1;
		per(j,SZ(ans[i])-1,0) res=1LL*res*power(ans[i][j].fi,ans[i][j].se)%mo;
		printf("%lld\n",res%mo);
	}
	return 0;
}