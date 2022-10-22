#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=3e5+7;
const ll INF=1e9+7;
ll n,m;
ll fac[N];
int main(){
	scanf("%I64d%I64d",&n,&m);
	fac[0]=1;
	rep(i,n)fac[i]=fac[i-1]*i%m;
	ll ans=0;
	rep(i,n)ans=(ans+(n-i+1)*(n-i+1)%m*fac[i]%m*fac[n-i])%m;
	printf("%I64d\n",ans);
	return 0;
}