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
const int N = 400, inf = 0x3f3f3f3f;
int n,k,a[N],f[N][N],g[N],pos[N],ans[N];
int head[N],to[N],nxt[N],edgenum;
inline void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
inline void DFS(int s, int u, int fa, int dis) {
	f[s][u]=a[dis];
	L(i,u) if (to[i]!=fa) DFS(s,to[i],u,dis+1);
}
inline void dfs(int u, int fa) {
//	printf("dfs %d %d\n",u,fa);
	L(j,u) if (to[j]!=fa) dfs(to[j],u);
	rep(i,1,n) L(j,u) if (to[j]!=fa) {
		int v=to[j]; f[u][i]+=min(f[v][i],g[v]+k);
	}
	g[u]=inf; rep(i,1,n) g[u]=min(g[u],f[u][i]); //WA1. SB
	rep(i,1,n) if (g[u]==f[u][i]) pos[u]=i;
}
inline void getans(int u, int i, int fa) {
	ans[u]=i;
	L(j,u) if (to[j]!=fa) {
		int v=to[j];
		if (f[v][i]<g[v]+k) getans(v,i,u);
		else getans(v,pos[v],u);
	}
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(k);
	rep(i,1,n-1) read(a[i]);
	rep(i,2,n) {int x,y;read(x);read(y);add(x,y);add(y,x);}
	rep(i,1,n) DFS(i,i,0,0);
	dfs(1,0); cout<<k+g[1]<<endl;
	getans(1,pos[1],0);
	rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}