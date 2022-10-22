#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=607;
const ll INF=1e16+7;
ll D[N][N],E[N][N],C[N][N];
ll n,m,q;
bool is[N][N];

int main(){
	scanf("%lld%lld",&n,&m);
	rep(i,n){
		rep(j,n){
			D[i][j]=(i==j)?0:INF;
			E[i][j]=INF;
			C[i][j]=-INF;
		}
	}
	rep(i,m){
		ll x,y,z; scanf("%lld%lld%lld",&x,&y,&z);
		E[x][y]=E[y][x]=z;
		D[x][y]=D[y][x]=z;
	}
	rep(k,n)rep(i,n)rep(j,n)D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
	scanf("%lld",&q);
	rep(i,q){
		ll x,y,l; scanf("%lld%lld%lld",&x,&y,&l);
		C[x][y]=max(C[x][y],l);
		C[y][x]=max(C[y][x],l);
	}
	rep(u,n){
		rep(y,n){
			ll mx=-INF;
			rep(v,n)mx=max(mx,C[u][v]-D[v][y]);
			rep(x,n){
				if(E[x][y]==INF)continue;
				if(E[x][y]+D[u][x]<=mx)is[x][y]=is[y][x]=1;
			}
		}
	}
	ll ans=0;
	rep(i,n)rep(j,n)ans+=is[i][j];
	printf("%lld\n",ans/2ll);
	return 0;
}