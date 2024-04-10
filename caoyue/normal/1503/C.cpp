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
const ll INF=1e14+7;
ll n;
ll a[N],c[N];
struct pir{
	ll l,r;
	friend bool operator <(pir u,pir v){
		return (u.l!=v.l)?(u.l<v.l):(u.r>v.r);
	}
}dl[N];
set<pir>S;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("hh.out","w",stdout);
	scanf("%lld",&n);
	ll ans=0;
	rep(i,n)scanf("%lld%lld",&a[i],&c[i]);
	rep(i,n)ans+=(ll)(c[i]);
	rep(i,n)c[i]+=a[i];
	rep(i,n){
		if(S.empty())S.insert((pir){a[i],c[i]});
		else{
			set<pir>::iterator o=S.upper_bound((pir){c[i],-INF});
			ll nl=a[i],nr=c[i],cc=0;
			while(1){
				if(o==S.begin()){
					break;
				}
				o--;
				if((*o).r<nl){
					break;
				}
				nl=min(nl,(*o).l);
				nr=max(nr,(*o).r);
				dl[++cc]=(*o);
			}
			rep(j,cc)S.erase(dl[j]);
			S.insert((pir){nl,nr}); 
		}
	}
	ll ls=-1;
	for(set<pir>::iterator g=S.begin();g!=S.end();g++){
		if(~ls)ans=(ans+(ll)((*g).l-ls));
		ls=(*g).r;
	}
	printf("%lld\n",ans);
	return 0;
}