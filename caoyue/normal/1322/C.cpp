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
const ll N=5e5+7;
const ll mod1=1e9+7;;
const ll mod2=1004535809;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll p1[N],p2[N],s1[N],s2[N],c[N];
struct pir{
	ll a,b;
	friend bool operator < (pir x,pir y){
		if(x.a!=y.a)return x.a<y.a;
		return x.b<y.b;
	}
};
map<pir,ll>mp;
int main(){
	p1[0]=p2[0]=1;
	rep(i,500000){
		p1[i]=p1[i-1]*2%mod1;
		p2[i]=p2[i-1]*2%mod2;
	}
	ll T; scanf("%lld",&T);
	while(T--){
		ll n,m; scanf("%lld%lld",&n,&m);
		rep(i,n)s1[i]=s2[i]=0;
		rep(i,n)scanf("%lld",&c[i]);
		rep(i,m){
			ll x,y; scanf("%lld%lld",&x,&y);
			s1[y]=(s1[y]+p1[x]<mod1)?s1[y]+p1[x]:s1[y]+p1[x]-mod1;
			s2[y]=(s2[y]+p2[x]<mod2)?s2[y]+p2[x]:s2[y]+p2[x]-mod2;
		}
		mp.clear();
		rep(i,n){
			if(!s1[i]&&!s2[i])continue;
			pir g=(pir){s1[i],s2[i]};
			if(mp.count(g))mp[g]+=c[i];
			else mp[g]=c[i];
		}
		ll ans=0;
		for(map<pir,ll>::iterator g=mp.begin();g!=mp.end();g++)ans=gcd(g->second,ans);
		printf("%lld\n",ans);
	} 
	return 0;
}