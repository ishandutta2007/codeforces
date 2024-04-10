#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
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
const int N = 102000, mo = 1e9+7;
bool vis[N];
int n,m,q,o,rt[N],size[N],d[N],f[N],g[N],sum[N];
vector<int> vec[N];
map<Pii,double> Map;
int head[N],edgenum;
struct Edge {
	int to,nxt;
} edge[N<<1];
inline void add(int u, int v) {
	edge[++edgenum].to=v;
	edge[edgenum].nxt=head[u];
	head[u]=edgenum;
}
inline ll gcd(ll a, ll b) {return !b ? a : gcd(b,a%b);}
inline void exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline ll inv(ll a, ll mo) {
	ll x,y; exgcd(a,mo,x,y); return x>=0 ? x : x+mo;
}

inline void LOCAL() {freopen("1.in","r",stdin);}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline void dp(int u, int fa) {
	vis[u]=1; L(i,u) if (edge[i].to!=fa) {dp(edge[i].to,u); f[u]=max(f[u],f[edge[i].to]+1);}
}
inline void dp1(int u, int fa) {
	int mx1=g[u],mx2=0;
	L(i,u) if (edge[i].to!=fa)
		if (f[edge[i].to]+1>mx1) {mx2=mx1; mx1=f[edge[i].to]+1;}
		else if (f[edge[i].to]+1>mx2) mx2=f[edge[i].to]+1;
	L(i,u) if (edge[i].to!=fa) g[edge[i].to]=(mx1==f[edge[i].to]+1) ? mx2+1 : mx1+1;
	L(i,u) if (edge[i].to!=fa) dp1(edge[i].to,u);
}
inline void dfs(int root, int u, int fa) {
	vis[u]=1; rt[u]=root; size[u]=1; d[root]=max(d[root],f[u]);
	vec[root].push_back(f[u]);
	L(i,u) if (edge[i].to!=fa) {
		dfs(root,edge[i].to,u); size[u]+=size[edge[i].to];
	}
}
int main() {
	read(n); read(m); read(q);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	rep(i,1,m) {int x,y; read(x); read(y); add(x,y); add(y,x);}
	rep(i,1,n) if (!vis[i]) {dp(i,-1); dp1(i,0);}
	rep(i,1,n) f[i]=max(f[i],g[i]);
	memset(vis,0,sizeof(vis));
	rep(i,1,n) if (!vis[i]) {dfs(i,i,-1); sort(vec[i].begin(),vec[i].end());}
	while(q--) {
		int u,v; read(u); read(v); u=rt[u]; v=rt[v];
		if (u==v) {puts("-1"); continue;}
		if (size[u]>size[v]) swap(u,v); //siz[u]<=siz[v]
		if (Map.count(Pii(u,v))) {printf("%.10lf\n",Map[Pii(u,v)]); continue;}
		int mx=max(d[u],d[v]);
		sum[size[v]]=0; per(i,size[v]-1,0) sum[i]=sum[i+1]+vec[v][i];
		ll res=0;
		rep(i,0,size[u]-1) { //max(mx, vec[u][i]+vec[v][j]+1)
			int l=0,r=size[v]-1,ans=-1;
			while (l<=r) { //sigma > mx
				int mid=(l+r)>>1;
				if (vec[u][i]+vec[v][mid]+1>mx) {ans=mid; r=mid-1;}
				else l=mid+1;
			}
			if (ans==-1) res+=(ll)mx*size[v];
			else res+=(ll)ans*mx+(size[v]-ans)*(vec[u][i]+1)+sum[ans];
		}
		printf("%.10lf\n",(double)res/size[u]/size[v]); Map[Pii(u,v)]=(double)res/size[u]/size[v]; //res / fm
	}
	return 0;
}
/*
dpf[v] <-- max(g[u],f[v]+1)
 
*/