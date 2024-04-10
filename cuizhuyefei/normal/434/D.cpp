#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 70005, inf = 0x3f3f3f3f, M = 800200;
int a[N],b[N],c[N],l[N],r[N],bh[55][350],num;
int n,m,head[N],nxt[M<<1],to[M<<1],cap[M<<1],edgenum=1;
int s,t,dis[N],cur[N],q[N];
inline void addedge(int u, int v, int c) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum; cap[edgenum]=c;
}
inline void add(int u, int v, int c) {addedge(u,v,c); addedge(v,u,0);}
inline void inc(int &x) {x++; if (x==N) x=0;}
inline bool bfs() {
	memset(dis,inf,sizeof(dis));
	int f=0,r=1; q[f]=t; dis[t]=0;
	while (f!=r) {
		int u=q[f]; inc(f); int Dis=dis[u];
		for (int i=head[u]; i!=0; i=nxt[i]) 
			if (cap[i^1]&&dis[to[i]]==inf) {dis[to[i]]=Dis+1; q[r++]=to[i];}
	}
	return dis[s]<inf;
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
		memcpy(cur,head,sizeof(head));
		res+=dfs(s,inf);
	}
	return res;
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(m); s=N-2; t=s+1;
	rep(i,1,n) read(a[i]),read(b[i]),read(c[i]);
	rep(i,1,n) read(l[i]),read(r[i]);
	int ans=0;
	rep(i,1,n) {
		int mx=-10000000; rep(j,l[i],r[i]) mx=max(mx,a[i]*j*j+b[i]*j+c[i]); ans+=mx;
	//	printf("%d %d\n",i,mx);
		rep(j,l[i],r[i]) {
			bh[i][j+100]=++num; ++num; add(num-1,num,mx-(a[i]*j*j+b[i]*j+c[i]));
			if (j<r[i]) add(num,num+1,inf);
		}
		add(s,bh[i][l[i]+100],inf); add(num,t,inf);
	}
	while (m--) {
		int x,y,d; read(x); read(y); read(d);
		rep(i,l[x],r[x]) 
			if (i-d>=l[y]&&i-d<=r[y])
				add(bh[x][i+100],bh[y][i-d+100],inf);
			else if (i-d>r[y]) add(bh[x][i+100],bh[y][r[y]+100]+1,inf);
	}
	printf("%d",ans-dinic());
	return 0;
}