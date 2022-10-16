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
const int MAXN=610,MAXM=1e6+10;
const ll INF=1e18;
int n,m,q,u,v,w;
struct Edge{int u,v,w;}edge[MAXM];
struct Pair{int u,v,w;}triple[MAXM];
int fst[MAXN],nxt[MAXM];
ll dis[MAXN][MAXN],g[MAXN][MAXN];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,n)dis[i][j]=INF,g[i][j]=-INF;rep(i,1,n)dis[i][i]=0;
	rep(i,1,m){scanf("%d%d%d",&u,&v,&w);edge[i]=(Edge){u,v,w};dis[u][v]=dis[v][u]=Min(dis[u][v],w);}
	scanf("%d",&q);
	rep(i,1,q){
		scanf("%d%d%d",&u,&v,&w);
		triple[i]=(Pair){u,v,w};nxt[i]=fst[u];fst[u]=i;
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				dis[i][j]=Min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	rep(i,1,n){
		rep(u,1,n){
			//g[i][u]
			for(int j=fst[u];j;j=nxt[j]){
				//triple[j]
				g[i][u]=Max(g[i][u],triple[j].w-dis[i][triple[j].v]); 
			}
		}
	}
	int ans=0;
	rep(i,1,m){
		int u=edge[i].u,v=edge[i].v; //(u,v)
		rep(a,1,n){
			if(g[v][a]-edge[i].w-dis[a][u]>=0 || g[u][a]-edge[i].w-dis[a][v]>=0){ans++;break;}
		} 
	}
	printf("%d",ans);
	return 0;
}