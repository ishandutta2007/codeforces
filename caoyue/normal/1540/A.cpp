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
const ll N=2e5+7;
const ll INF=1e9+7;
ll T,n;
ll d[N];
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		rep(i,n)scanf("%lld",&d[i]);
		sort(d+1,d+n+1);
		ll ans=d[n];
		rep(i,n){
			ans+=(n-i)*d[i];
			ans-=(i-1)*d[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}