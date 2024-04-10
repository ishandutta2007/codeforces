#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=185;
const ll INF=1e16; 
vector<int>e[MAXN];
int n,k,d[MAXN],u,v;
ll f[MAXN][MAXN],g[MAXN],fa[MAXN]; //g(i)f(i,j)j
ll dis[MAXN][MAXN];
ll sol[MAXN];
void dp(int u){
	for(vit it=e[u].begin();it!=e[u].end();it++){
		int v=*it;
		if(v==fa[u])continue;
		fa[v]=u;dp(v);
	}
	rep(j,0,n)f[u][j]=INF;g[u]=0;
	rep(j,1,n){f[u][j]=k+d[dis[u][j]];}
	for(vit it=e[u].begin();it!=e[u].end();it++){
		int v=*it;
		if(v==fa[u])continue;
		rep(j,1,n){
			int K=g[v]; //v
			f[u][j]+=Min(f[v][j]-k,f[v][K]);
		}
	}
	rep(j,1,n){
		if(f[u][j]<f[u][g[u]])g[u]=j;
	}
}
void solve(ll u){
	//fa[u]u
	int K=g[u];
	if(f[u][sol[fa[u]]]-k < f[u][K]){
		sol[u]=sol[fa[u]];
	}else sol[u]=K;
	for(vit it=e[u].begin();it!=e[u].end();it++){
		int v=*it;if(v==fa[u])continue;
		solve(v);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)rep(j,1,n)if(i!=j)dis[i][j]=INF;
	rep(i,1,n-1)scanf("%d",&d[i]);
	rep(i,1,n-1){
		scanf("%d%d",&u,&v);
		e[u].pb(v);e[v].pb(u);
		dis[u][v]=dis[v][u]=1;
	}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)dis[i][j]=Min(dis[i][j],dis[i][k]+dis[k][j]);
	dp(1);
	ll k=g[1];
	printf("%lld\n",f[1][k]);
	sol[1]=k;
	for(vit it=e[1].begin();it!=e[1].end();it++){
		int v=*it;
		solve(v);
	} 
	rep(i,1,n){
		printf("%lld ",sol[i]);
	}
	return 0;
}