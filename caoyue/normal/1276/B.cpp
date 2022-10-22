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
const ll INF=1e9+7;
vector<ll>Ea,Eb;
ll n,m,A,B;
ll f[N],sz[N],s[N];
ll ff(ll x){return (f[x]==x)?x:f[x]=ff(f[x]);}
int main(){
	ll T; scanf("%lld",&T);
	while(T--){
		Ea.clear();
		Eb.clear();
		scanf("%lld%lld%lld%lld",&n,&m,&A,&B);
		if(A>B)swap(A,B);
		rep(i,n){
			f[i]=i;
			sz[i]=1;
			s[i]=0;
		}
		rep(i,m){
			ll x,y; scanf("%lld%lld",&x,&y);
			if(x<y)swap(x,y);
			if(x==A&&y==B)continue;
			if(x!=B&&y!=A&&x!=A&&y!=B){
				ll u=ff(x),v=ff(y);
				if(u!=v){
					f[v]=u;
					sz[u]+=sz[v];
				}
			}
			else{
				if(x==B)Eb.push_back(y);
				if(y==A)Ea.push_back(x);
				if(x==A)Ea.push_back(y);
				if(y==B)Eb.push_back(x);
			}
		}
		rep0(i,Ea.size())s[ff(Ea[i])]|=1;
		rep0(i,Eb.size())s[ff(Eb[i])]|=2;
		ll s1=0,s2=0;
		rep(i,n){
			if(ff(i)!=i)continue;
			if(i==A||i==B)continue;
			if(s[i]==1)s1+=sz[i];
			if(s[i]==2)s2+=sz[i];
		}
		printf("%lld\n",s1*s2);
	}
	return 0;
}