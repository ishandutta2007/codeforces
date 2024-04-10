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
const ll N=7;
const ll INF=4e18+7;
ll T,A,B,C;
set<ll>Sa,Sb,Sc;
ll calc(ll a,ll b,ll c){return (a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c);}
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&A,&B,&C);
		ll ans=INF;
		Sa.clear();
		Sb.clear();
		Sc.clear();
		rep(i,A){ll x; scanf("%lld",&x); Sa.insert(x);}
		rep(i,B){ll x; scanf("%lld",&x); Sb.insert(x);}
		rep(i,C){ll x; scanf("%lld",&x); Sc.insert(x);}
		for(set<ll>::iterator s=Sa.begin();s!=Sa.end();s++){
			ll o=*s;
			set<ll>::iterator g1=Sb.upper_bound(o),g2=Sb.lower_bound(o);
			set<ll>::iterator h1=Sc.upper_bound(o),h2=Sc.lower_bound(o);
			if(g1!=Sb.begin()){
				g1--;
				if(h1!=Sc.begin()){
					set<ll>::iterator h3=h1;
					h3--;
					ans=min(ans,calc(o,*g1,*h3));
				}
				if(h2!=Sc.end())ans=min(ans,calc(o,*g1,*h2));
			}
			if(g2!=Sb.end()){
				if(h1!=Sc.begin()){
					h1--;
					ans=min(ans,calc(o,*g2,*h1));
				}
				if(h2!=Sc.end())ans=min(ans,calc(o,*g2,*h2));
			}
		}
		for(set<ll>::iterator s=Sb.begin();s!=Sb.end();s++){
			ll o=*s;
			set<ll>::iterator g1=Sa.upper_bound(o),g2=Sa.lower_bound(o);
			set<ll>::iterator h1=Sc.upper_bound(o),h2=Sc.lower_bound(o);
			if(g1!=Sa.begin()){
				g1--;
				if(h1!=Sc.begin()){
					set<ll>::iterator h3=h1;
					h3--;
					ans=min(ans,calc(o,*g1,*h3));
				}
				if(h2!=Sc.end())ans=min(ans,calc(o,*g1,*h2));
			}
			if(g2!=Sa.end()){
				if(h1!=Sc.begin()){
					h1--;
					ans=min(ans,calc(o,*g2,*h1));
				}
				if(h2!=Sc.end())ans=min(ans,calc(o,*g2,*h2));
			}
		}
		for(set<ll>::iterator s=Sc.begin();s!=Sc.end();s++){
			ll o=*s;
			set<ll>::iterator g1=Sb.upper_bound(o),g2=Sb.lower_bound(o);
			set<ll>::iterator h1=Sa.upper_bound(o),h2=Sa.lower_bound(o);
			if(g1!=Sb.begin()){
				g1--;
				if(h1!=Sa.begin()){
					set<ll>::iterator h3=h1;
					h3--;
					ans=min(ans,calc(o,*g1,*h3));
				}
				if(h2!=Sa.end())ans=min(ans,calc(o,*g1,*h2));
			}
			if(g2!=Sb.end()){
				if(h1!=Sa.begin()){
					h1--;
					ans=min(ans,calc(o,*g2,*h1));
				}
				if(h2!=Sa.end())ans=min(ans,calc(o,*g2,*h2));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}