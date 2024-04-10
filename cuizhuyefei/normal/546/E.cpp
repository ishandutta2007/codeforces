#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 2005, inf = 100000, M = 10200;
int n,m,a[N],b[N],head[N],nxt[M<<1],to[M<<1],cap[M<<1],edgenum=1;
int s,t,dis[N],cur[N],q[N];
inline void addedge(int u, int v, int c) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum; cap[edgenum]=c;
}
inline void add(int u, int v, int c) {addedge(u,v,c); addedge(v,u,0);}
inline void inc(int &x) {x++; if (x==N) x=0;}
inline bool bfs() {
	memset(dis,0x3f3f3f3f,sizeof(dis));
	int f=0,r=1; q[f]=t; dis[t]=0;
	while (f!=r) {
		int u=q[f]; inc(f); int Dis=dis[u];
		for (int i=head[u]; i!=0; i=nxt[i]) 
			if (cap[i^1]&&dis[to[i]]==0x3f3f3f3f) {dis[to[i]]=Dis+1; q[r++]=to[i];}
	}
	return dis[s]<0x3f3f3f3f;
}
inline int dfs(int u, int f) {
	if (u==t||!f) return f;
	int res=0;
	for (int i=cur[u]; i!=0; i=nxt[i]) if (cap[i]&&dis[to[i]]==dis[u]-1) {
		cur[u]=nxt[i];
		int tmp=dfs(to[i],min(f,cap[i]));
		f-=tmp; res+=tmp; cap[i]-=tmp; cap[i^1]+=tmp;
		if (!f) break;
	}
	return res;
}
inline int dinic() {
	int res=0;
	while (bfs()) {
	//	printf("%d\n",res);
		memcpy(cur,head,sizeof(head));
		res+=dfs(s,0x7f7f7f7f);
	}
	rep(u,1,t)
//	L(i,u) if (cap[i]) printf("%d %d %d\n",u,to[i],cap[i]);
//	L(i,t) if (cap[i^1]) printf("t: %d %d\n",to[i],cap[i^1]);
//	printf("maxflow %d\n",res);
	return res;
}
int ans[333][333];
int main() { //freopen("1.in","r",stdin);
	read(n); read(m); rep(i,1,n) read(a[i]); rep(i,1,n) read(b[i]); s=n*2+1; t=s+1;
	rep(i,1,n) {add(s,i,a[i]); add(n+i,t,b[i]); add(i,n+i,inf);}
	while (m--) {int x,y;read(x);read(y);add(x,n+y,inf);add(y,n+x,inf);}
	bool gg=0;
	int num=0; rep(i,1,n)num+=a[i]-b[i]; if (num) gg=1;
	int num1=0; rep(i,1,n)num1+=a[i]; if (dinic()!=num1) gg=1;
	if (gg) {puts("NO"); return 0;}
	puts("YES"); rep(u,1,n) for (int i=head[u]; i!=0; i=nxt[i]) 
		if (inf>cap[i]) ans[u][to[i]-n]=inf-cap[i];
//	rep(i,1,n) {ans[i][i]=a[i]; rep(j,1,n)if (j!=i) ans[i][i]-=ans[i][j];}
	rep(i,1,n) {rep(j,1,n) printf("%d ",ans[i][j]); puts("");}
	return 0;
}