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
const ll MAXN=110,mod=1e9+7;
ll T,n,k,u,v,ans;
ll g[MAXN][MAXN],fa[MAXN],f[MAXN],tmp[MAXN],depth[MAXN];
ll isfather[MAXN][MAXN],dis[MAXN][MAXN];
vector<ll>e[MAXN];
void dfs1(int u){
	g[u][0]=1;
	depth[u]=depth[fa[u]]+1;
	for(vector<ll>::iterator it=e[u].begin();it!=e[u].end();it++){
		ll v=*it;
		if(v==fa[u])continue;
		fa[v]=u;
		dfs1(v);
		rep(j,1,n){g[u][j]+=g[v][j-1];}
	}
}
void Merge(int v,int d){
	rep(j,0,k)tmp[j]=f[j];
	rep(j,1,k){
		f[j]=(f[j]+tmp[j-1]*g[v][d]%mod)%mod;
	}
}
void dfs2(int u){
	//u
	for(ll dist=2;dist<=n;dist+=2){
		memset(f,0,sizeof f);
		ll cnt=0;
		rep(v,1,n){
			if(dis[u][v]==dist/2){
				if(!isfather[u][v])cnt++;
			}
		}
		f[0]=1;f[1]=cnt;
		for(vector<ll>::iterator it=e[u].begin();it!=e[u].end();it++){
			ll v=*it;if(v==fa[u])continue;
			Merge(v,dist/2-1);
		}
		ans=(ans+f[k])%mod;
	} 
	for(vector<ll>::iterator it=e[u].begin();it!=e[u].end();it++){
		ll v=*it;if(v==fa[u])continue;
		dfs2(v);	
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		rep(i,1,n){
			rep(j,1,n){
				if(i!=j)dis[i][j]=mod;
			}
		}
		rep(i,1,n)e[i].clear();
		rep(i,1,n-1){
			cin>>u>>v;
			e[u].pb(v);e[v].pb(u);
			dis[u][v]=dis[v][u]=1;
		}
		rep(k,1,n){
			rep(i,1,n){
				rep(j,1,n){
					dis[i][j]=Min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		if(k==2){
			printf("%lld\n",n*(n-1)/2);
			continue;
		}
		memset(g,0,sizeof g);
		memset(fa,0,sizeof fa);
		dfs1(1);
		memset(isfather,0,sizeof isfather);
		rep(i,1,n){
			int u=i;
			while(u){
				isfather[u][i]=1;
				u=fa[u];
			}
		}
		ans=0;
		dfs2(1);
		printf("%lld\n",ans);
	} 

	return 0;
}