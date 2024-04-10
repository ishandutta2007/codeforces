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
const int MAXN=210,moder=1e9+7;
struct Edge{
	int u,v;
}edge[MAXN*2];
int first[MAXN],next[MAXN*2],tot;
int n,u,v;
int fa[MAXN][10],depth[MAXN];
ll ans,f[MAXN][MAXN];
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);tmp=tmp*tmp%moder;
	if(n&1)tmp=tmp*a%moder;
	return tmp;
}
void addedge(int u,int v){
	edge[++tot]=(Edge){u,v};next[tot]=first[u];first[u]=tot;
}
void dfs(int u){
	rep(j,1,9)fa[u][j]=fa[fa[u][j-1]][j-1];
	for(int j=first[u];j;j=next[j]){
		int v=edge[j].v;if(v==fa[u][0])continue;
		fa[v][0]=u;depth[v]=depth[u]+1;dfs(v);
	} 
}
int lca(int x,int y){
	if(depth[x]>depth[y])swap(x,y);
	per(j,9,0){
		if(depth[y]-(1<<j)>=depth[x])y=fa[y][j];
	}
	if(x==y)return x;
	per(j,9,0){
		if(fa[x][j]!=fa[y][j])x=fa[x][j],y=fa[y][j];
	}
	return fa[x][0];
}
ll calc(int u){
	rep(j,0,9)fa[u][j]=0;
	depth[u]=1;
	dfs(u);
	ll ans=0;
	rep(i,1,n){
		rep(j,i+1,n){
			int l=lca(i,j);
			ans=(ans+f[depth[i]-depth[l]][depth[j]-depth[l]])%moder;
		}
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&u,&v);
		addedge(u,v);addedge(v,u);
	}
	rep(i,1,n)f[i][0]=1;
	rep(i,1,n){
		rep(j,1,n){
			f[i][j]=(f[i][j]+f[i-1][j]*power(2,moder-2))%moder;
			f[i][j]=(f[i][j]+f[i][j-1]*power(2,moder-2))%moder;
		}
	}
	rep(i,1,n){
		ans=(ans+calc(i)*power(n,moder-2))%moder;
	}
	cout<<ans;
	return 0;
}