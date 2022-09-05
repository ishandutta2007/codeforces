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
const int N = 400400;
int n,head[N],to[N],nxt[N],edgenum;
void addedge(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
int fa[N][19],dy[N],dep[N],FA[N],L[N],R[N],num,top[N][19],Ans[N],Ans1[N]; //Ans[i]-=(Ans1[i]>0)
inline void dfs(int u, int Fa, int Dep) {
	dep[u]=Dep; fa[u][0]=Fa; L[u]=++num;
	L(i,u) if (to[i]!=Fa) dfs(to[i],u,Dep+1);
	R[u]=num;
}
inline void init() {
	rep(i,1,18) dy[1<<i]=i;
	rep(j,1,18) rep(i,1,n)
		if (dep[i]>=(1<<j)) fa[i][j]=fa[fa[i][j-1]][j-1];
}
inline int LCA(int u, int v) {
	if (dep[u]<dep[v]) swap(u,v); int del=dep[u]-dep[v];
	while (del) {int bit=del&-del; del-=bit; u=fa[u][dy[bit]];}
	if (u==v) return u;
	per(i,18,0) if (fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
struct Bus {int u,v,lca;} que[N];
bool cmp2(Bus a, Bus b) {return dep[a.lca]<dep[b.lca];}

struct Line {int index,xs,p,l,r;} ju[N]; int len;
struct Dot {int x,y; Dot(int X=0, int Y=0){x=X; y=Y;}} dot[N]; int len1;
bool cmp(Line a, Line b) {return a.p<b.p;}
bool cmp1(Dot a, Dot b) {return a.x<b.x;}
int v[N];
inline void ins(int p) {while (p<=n) v[p]++,p+=p&-p;}
inline int query(int p) {int res=0; while (p) res+=v[p],p-=p&-p; return res;}
int main() { //freopen("1.in","r",stdin);
	read(n); rep(i,2,n) {int x;read(x);addedge(x,i);addedge(i,x);}
	int q; read(q); dfs(1,0,0); init();
	rep(i,1,q) {
		int u,v; read(u); read(v); int lca=LCA(u,v); que[i]=(Bus){u,v,lca};
		if (u!=lca&&v!=lca) dot[++len1]=Dot(min(L[u],L[v]),max(L[u],L[v]));
	}
	sort(que+1,que+q+1,cmp2);
	rep(i,1,q) {
	//	printf("%d %d %d\n",que[i].u,que[i].v,que[i].lca);
		for (int u=que[i].u; dep[u]>=dep[que[i].lca]; u=fa[u][0]) {
			if (FA[u]) break; FA[u]=que[i].lca;
		}
		for (int u=que[i].v; dep[u]>=dep[que[i].lca]; u=fa[u][0]) {
			if (FA[u]) break; FA[u]=que[i].lca;
		}
	}
	rep(i,1,n) {if (!FA[i]) FA[i]=i; top[i][0]=FA[i];}
	rep(j,1,18) rep(i,1,n) top[i][j]=top[top[i][j-1]][j-1];
	int m; read(m);
//	rep(i,1,n) printf("%d : %d\n",i,top[i][0]);
	rep(k,1,m) {
		int u,v,ans=0;read(u);read(v); int lca=LCA(u,v);
		per(i,18,0) if (dep[top[u][i]]>dep[lca]) u=top[u][i],ans+=1<<i;
		per(i,18,0) if (dep[top[v][i]]>dep[lca]) v=top[v][i],ans+=1<<i;
		if (dep[top[u][0]]>dep[lca]||dep[top[v][0]]>dep[lca]) Ans[k]=-1;
		else if (u==v) Ans[k]=ans;
		else if (lca==u||lca==v) Ans[k]=ans+1;
		else {
			Ans[k]=ans+2; if (L[u]>L[v]) swap(u,v);
			ju[++len]=(Line){k,1,R[u],L[v],R[v]};
			ju[++len]=(Line){k,-1,L[u]-1,L[v],R[v]};
		}
	}
	sort(ju+1,ju+len+1,cmp);
	sort(dot+1,dot+len1+1,cmp1);
	int p=0; rep(i,1,len) {
		while (p+1<=len1&&dot[p+1].x<=ju[i].p) ins(dot[++p].y);
		Ans1[ju[i].index]+=ju[i].xs*(query(ju[i].r)-query(ju[i].l-1));
	}
	rep(i,1,m) printf("%d\n",Ans[i]-(Ans1[i]>0));
	return 0;
}