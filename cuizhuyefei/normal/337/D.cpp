#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 100030;
bool used[N];
int dp[N],ans[N];
int n,m,d,head[N],edgenum;
struct Edge {
	int to,nxt;
} edge[N<<1];

inline void add(int u, int v) {
	edge[++edgenum].to=v;
	edge[edgenum].nxt=head[u];
	head[u]=edgenum;
}


inline void LOCAL() {freopen("1.in","r",stdin);}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline void dfs1(int u, int fa) {
	if (used[u]) dp[u]=0;
	L(i,u) if (edge[i].to!=fa) {
		dfs1(edge[i].to,u); dp[u]=max(dp[u],dp[edge[i].to]+1);
	}
}
inline void dfs2(int u, int fa) {
	int mx=-10,mx1=-10; if (used[u]) ans[u]=max(ans[u],0); //!!inf
	L(i,u) if (edge[i].to!=fa) {
		int v=edge[i].to;
		if (dp[v]>mx) {mx1=mx; mx=dp[v];}
		else if (dp[v]>mx1) mx1=dp[v]; //!!!!!!!!!!!
	}
	L(i,u) if (edge[i].to!=fa) {
		if (dp[edge[i].to]==mx) ans[edge[i].to]=mx1+2;
		else ans[edge[i].to]=mx+2;
		ans[edge[i].to]=max(ans[edge[i].to],ans[u]+1); //fa!
	}
	L(i,u) if (edge[i].to!=fa) dfs2(edge[i].to,u);
}
int main() { //LOCAL();
	read(n); read(m); read(d);
	rep(i,1,m) {int x; read(x); used[x]=1;}
	rep(i,1,n-1) {
		int u,v; read(u); read(v);
		add(u,v); add(v,u);
	}
	memset(dp,0xaf,sizeof(dp));
	memset(ans,0xaf,sizeof(ans));
	dfs1(1,-1); dfs2(1,-1);
	int res=0; rep(i,1,n) //printf("%d : %d %d\n",i,dp[i],ans[i]);
		res+=(max(ans[i],dp[i])<=d);
	printf("%d",res);
	return 0;
}