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
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll n,m;
ll a[N],b[N];
ll calc(ll x){
	ll ans=0;
	rep(i,x){
		bool s=0;
		ll mn=INF;
		for(ll j=i;j<=n;j+=x){
			if(a[j]<0)s^=1;
			mn=min(mn,abs(a[j]));
			ans+=abs(a[j]);
		}
		if(s)ans-=mn*2ll;
	}
	return ans;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		rep(i,n)scanf("%lld",&a[i]);
		rep(i,m)scanf("%lld",&b[i]);
		ll g=0;
		rep(i,m)g=gcd(g,b[i]);
		ll ans=calc(g);
		rep(i,g)a[i]=-a[i];
		ans=max(ans,calc(g));
		printf("%lld\n",ans);
	}
	return 0;
}