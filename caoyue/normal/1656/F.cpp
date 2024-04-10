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
const ll N=1e6+7;
const ll INF=1e9+7;
ll T,n;
ll a[N],b[N];
struct pir{ll k,b;};
pir check(ll x){
	ll kk=0,bb=-x*x*(n-1);
	rep(i,n)b[i]=a[i]+x;
	kk+=(a[n]+a[1]);
	bb+=(b[n]*b[1]);
	REP(i,2,n-1){
		if(b[i]>=0){
			kk+=(a[i]+a[1]);
			bb+=b[i]*b[1];
		}
		else{
			kk+=(a[i]+a[n]);
			bb+=b[i]*b[n];
		}
	}
	return (pir){kk,bb};
}
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		rep(i,n)scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		ll l=-N,r=N;
		if(check(l).k<0){
			puts("INF");
			continue;
		}
		if(check(r).k>0){
			puts("INF");
			continue;
		}
		while(l<r-1){
			ll mid=(l+r)>>1;
			if(check(mid).k<=0)r=mid;
			else l=mid;
		}
		printf("%lld\n",max(check(l).b,check(r).b));
	}
	
	return 0;
}