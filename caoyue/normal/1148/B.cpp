#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
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
const ll N=2e5+7;
const ll INF=1e17+7;
ll a[N],b[N];
ll n,m,k,ta,tb;

int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&ta,&tb,&k);
	rep(i,n)scanf("%I64d",&a[i]);
	rep(i,m)scanf("%I64d",&b[i]);
	if(k>=min(n,m)){
		puts("-1");
		return 0;
	}
	ll nw=1,ans=0;
	rep0(i,k+1){
		while(b[nw]<a[i+1]+ta&&nw<=m)nw++;
		ll v=k-i;
		if(nw+v>m){
			puts("-1");
			return 0;
		}
		ans=max(ans,b[nw+v]);
	}
	printf("%I64d\n",ans+tb);
	return 0;
}