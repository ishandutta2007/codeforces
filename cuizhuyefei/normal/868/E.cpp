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
const int N = 105, inf = 1e7;
int n,m,a[N],b[N],c[N],dis[N][N],s,deg[N],mrk[N],dfn[N],low[N],num;
int head[N],to[N],nxt[N],val[N],edgenum;
inline void add(int u, int v, int d) {
	to[++edgenum]=v; val[edgenum]=d;
	nxt[edgenum]=head[u]; head[u]=edgenum;
	a[edgenum]=u; b[edgenum]=v; c[edgenum]=d;
}
inline void getdis(int s, int u, int now, int fa) {
	dis[s][u]=now;
	L(i,u) if (to[i]!=fa) getdis(s,to[i],now+val[i],u);
}
inline void dfs1(int u, int fa) {
	dfn[u]=++num;
	L(i,u) if (to[i]!=fa) {dfs1(to[i],u); mrk[u]+=mrk[to[i]];}
	low[u]=num;
}
int f[N][N],lev[N],len;
inline int dp(int u, int x) {
	if (!x) return 0; if (f[u][x]) return f[u][x];
	int l=1,r=n*m*50,ans=0;
	while (l<=r) {
		int mid=(l+r)>>1; int cnt=0;
		rep(i,1,len) if (lev[i]!=u) {
			int a=0; per(j,x-1,0) if (dp(lev[i],j)<mid-dis[u][lev[i]]) {a=j+1; break;}
		//	if (a==x+1) cnt-=inf; else 
			cnt+=x-a;
		}
	//	printf("%d %d --> %d : %d %d\n",u,x,mid,cnt,x);
		if (cnt>=x) {ans=mid; l=mid+1;} else r=mid-1;
	}
//	printf("f[%d][%d]=%d\n",u,x,ans);
	return f[u][x]=ans;
}
inline int getans(int u, int x, int y) {
	if (deg[u]==1) return f[u][x-y];
	int l=1,r=n*m*50,ans=0;
	while (l<=r) {
		int mid=(l+r)>>1; int cnt=0;
		rep(i,1,len) if (dfn[u]<=dfn[lev[i]]&&low[u]>=dfn[lev[i]]) {
			int a=0; per(j,x,0) if (dp(lev[i],j)<mid-dis[u][lev[i]]) {a=j+1; break;}
			if (a==x+1) cnt-=inf; else cnt+=x-a;
		}
		if (cnt>=y) {ans=mid; l=mid+1;} else r=mid-1;
	}
	return ans;
}
int main() { //freopen("1.in","r",stdin);
	read(n); rep(i,2,n) {int x,y,z; read(x);read(y);read(z);add(x,y,z);add(y,x,z); deg[x]++; deg[y]++;}
	read(s); read(m); rep(i,1,m) {int x; read(x); mrk[x]++;}
	rep(i,1,n) if (deg[i]==1) lev[++len]=i;
	rep(i,1,n) getdis(i,i,0,0); dfs1(s,0);
	rep(i,1,n) rep(j,1,m) if (deg[i]==1) dp(i,j);
	int ans=1e9; //puts("OwO");
	L(i,s) {
		ans=min(ans,val[i]+getans(to[i],m,mrk[to[i]]));
	}
	printf("%d",ans);
	return 0;
}