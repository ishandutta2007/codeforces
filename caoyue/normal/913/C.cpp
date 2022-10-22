#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=37;
const ll INF=1e9+7;
ll c[N],f[N];
ll n,L;
ll dfs(ll x,ll V){
	ll q=(1<<x),nw=0,v=0;
	while(v<V){
		nw++;
		v+=q;
	}
	if(!x)return V*c[0];
	if(v*nw==V)return nw*c[x];
	return min(nw*c[x],(nw-1)*c[x]+dfs(x-1,V-(nw-1)*q));
}
int main(){
	scanf("%I64d%I64d",&n,&L);
	memset(c,120,sizeof(c));
	rep0(i,n)scanf("%I64d",&c[i]);
	rep(i,30)c[i]=min(c[i],c[i-1]*2);
	printf("%I64d\n",dfs(30,L));
	return 0;
}