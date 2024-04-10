#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
const int MAXN=4e5+10;
int n,q,a[MAXN],u[MAXN],v[MAXN];
vector<pi> e[MAXN];
int fa[MAXN],faw[MAXN];
ll f[MAXN],g[MAXN],h[MAXN];
int top[MAXN][20],power[20],depth[MAXN];
ll sumf[MAXN],sumh[MAXN],sumd[MAXN];
void dfs1(int u){
	for(auto V:e[u]){
		int v=V.fr,w=V.se;
		if(v==fa[u])continue;
		sumd[v]=sumd[u]+w;
		fa[v]=u;faw[v]=w;
		dfs1(v);
	}
}
void dfs2(int u){
	f[u]=a[u];
	for(auto V:e[u]){
		int v=V.fr,w=V.se;
		if(v==fa[u])continue;
		dfs2(v);
		f[u]+=max(f[v]-w*2,0LL);
	}
}
void dfs3(int u){
	for(auto V:e[u]){
		int v=V.fr,w=V.se;
		if(v==fa[u])continue;
		//
		g[v]=max(g[u]+f[u]-w*2-max(f[v]-w*2,0LL),0LL); 
		dfs3(v);
	}
}
void dfs4(int u){
	depth[u]=depth[fa[u]]+1;
	sumf[u]=sumf[fa[u]]+f[u];
	sumh[u]=sumh[fa[u]]+h[u];
	top[u][0]=fa[u];
	rep(j,1,19)top[u][j]=top[top[u][j-1]][j-1];
	for(auto V:e[u]){
		int v=V.fr;
		if(v==fa[u])continue;
		depth[v]=depth[u]+1;
		dfs4(v);
	}
} 
int lca(int u,int v){
	if(depth[u]<depth[v])swap(u,v);
	per(j,19,0){
		if(depth[u]-power[j]>=depth[v])u=top[u][j];
	}
	if(u==v)return u;
	per(j,19,0){
		if(top[u][j]!=top[v][j]){
			u=top[u][j];v=top[v][j];
		}
	}
	return top[u][0];
}
void solve(int u,int v){
	int p=lca(u,v);ll ret=0;
	ret+=sumf[u]+sumf[v]-sumf[fa[p]]*2-f[p];
	ret-=(sumh[u]+sumh[v]-sumh[fa[p]]*2-h[p]*2);
	ret+=g[p];
	ret-=(sumd[u]+sumd[v]-sumd[p]*2);
	printf("%lld\n",ret);
}
int main(){
	power[0]=1;rep(i,1,19)power[i]=power[i-1]*2;
	scanf("%d%d",&n,&q);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n-1){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		e[u].pb(mp(v,w));e[v].pb(mp(u,w));
	}
	rep(i,1,q){
		scanf("%d%d",&u[i],&v[i]);
	}
	dfs1(1);
	dfs2(1);
	dfs3(1);
	rep(i,1,n)h[i]=max(0LL,f[i]-2*faw[i]);
	dfs4(1);
	rep(i,1,q){
		solve(u[i],v[i]);
	}
	return 0;
}