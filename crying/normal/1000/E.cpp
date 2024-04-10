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
const int MAXN=3e5+10;
int n,m,u[MAXN],v[MAXN],tag[MAXN];
int fa[MAXN],vis[MAXN],ans,f[MAXN];
int top[MAXN][20],power[20],depth[MAXN];
int d[MAXN];
vector<int>e[MAXN]; 
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
void dfs(int u){
	vis[u]=1;
	depth[u]=depth[top[u][0]]+1;
	rep(j,1,19)top[u][j]=top[top[u][j-1]][j-1];
	for(auto v:e[u]){
		if(vis[v])continue;
		top[v][0]=u;dfs(v);
	} 
}
void dfs2(int u){
	vis[u]=1;
	for(auto v:e[u]){
		if(vis[v])continue;
		dfs2(v);d[u]+=d[v];
	}
}
void dfs3(int u){
	vis[u]=1;
	for(auto v:e[u]){
		if(vis[v])continue;
		dfs3(v);
		ans=max(ans,f[u]+f[v]+d[v]);
		f[u]=max(f[u],f[v]+d[v]);
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
int main(){
	scanf("%d%d",&n,&m);
	power[0]=1;rep(i,1,19)power[i]=power[i-1]*2;
	rep(i,1,n)fa[i]=i;
	rep(i,1,m){
		scanf("%d%d",&u[i],&v[i]);
		if(Find(u[i])==Find(v[i]))continue;
		tag[i]=1;fa[Find(u[i])]=Find(v[i]);e[u[i]].pb(v[i]);e[v[i]].pb(u[i]);
	}
	rep(i,1,n){
		if(vis[i])continue;
		dfs(i);
	}
	rep(i,1,m){
		if(tag[i])continue;
		int p=lca(u[i],v[i]);
		d[u[i]]++;d[v[i]]++;d[p]-=2;
	}
	rep(i,1,n)vis[i]=0;
	rep(i,1,n)if(!vis[i])dfs2(i);
	rep(i,1,n)d[i]=((bool)(d[i]))^1;
	rep(i,1,n)vis[i]=0;
	rep(i,1,n)if(!vis[i])dfs3(i);
	printf("%d",ans);
	return 0;
}