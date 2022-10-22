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
const ll INF=1e16+7;
ll T,n,ans,cc,cp,tot;
ll a[N],s[N],s0[N],s1[N];
struct pir{ll x,v;}fc[N*4],fp[N*4];
bool cmp1(pir u,pir v){return u.x>v.x;}
map<ll,ll>mp;
ll c[N*16];
void ins(ll x,ll v){for(ll i=x;i<=tot;i+=((i&(-i))))c[i]+=v;}
ll check(ll L,ll R){
	ll ans=0;
	for(ll i=L-1;i;i-=((i&(-i))))ans-=c[i];
	for(ll i=R;i;i-=((i&(-i))))ans+=c[i];
	return ans;
}
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		rep(i,n)scanf("%lld",&a[i]);
		ans=s[0]=s0[0]=s1[0]=cc=cp=tot=0;
		rep(i,n)s[i]=s[i-1]+a[i];
		ll mx=(s[n]-1)/2ll;
		if(n==2){
			ans=(a[1]+a[2]<=mx)+(a[1]<=mx)+(a[2]<=mx)+(0<=mx);
			printf("%lld\n",ans);
			continue;
		}
		if(0<=mx)ans++;
		if(s[n]<=mx)ans++;
		rep(i,n-1)if(s[n]-s[i]<=mx)ans++;
		rep(i,n){
			s0[i]=s0[i-1]+((i%2ll==0)?a[i]:0);
			s1[i]=s1[i-1]+((i%2ll==1)?a[i]:0);
		}
		rep(i,n){
			if(i&1){
				fp[++cp]=(pir){i,s0[n]+s1[i-1]};
				if(i>3)fp[++cp]=(pir){i,s0[n]+s1[i-1]-a[1]};
			}
			else{
				fp[++cp]=(pir){i,s1[n]+s0[i-1]};
				if(i>3)fp[++cp]=(pir){i,s1[n]+s0[i-1]-a[1]};
			}
		}
		rep(i,n){
			if(i&1){
				fc[++cc]=(pir){i,-(s1[n]-s1[i])};
				if(i<n-2ll)fc[++cc]=(pir){i,-(s1[n]-s1[i])+a[n]};
			}
			else{
				fc[++cc]=(pir){i,-(s0[n]-s0[i])};
				if(i<n-2ll)fc[++cc]=(pir){i,-(s0[n]-s0[i])+a[n]};
			}
		}
		sort(fp+1,fp+cp+1,cmp1);
		sort(fc+1,fc+cc+1,cmp1);
		if(!cc||!cp){
			printf("%lld\n",ans);
			continue;
		}
		mp.clear();
		rep(i,cc)mp[fc[i].v]=1;
		for(map<ll,ll>::iterator o=mp.begin();o!=mp.end();o++){
			mp[o->first]=++tot;
		}
		rep(i,cc)fc[i].v=mp[fc[i].v];
		ll nw=1;
		rep0(i,tot+10)c[i]=0;
		rep(i,cp){
			while(nw<=cc){
				if(fc[nw].x+1<fp[i].x)break;
				if(fc[nw].x&1)ins(fc[nw].v,1);
				nw++;
			}
			if(fp[i].x&1)continue;
			map<ll,ll>::iterator oo=mp.upper_bound(mx-fp[i].v);
			if(oo==mp.begin())continue;
			oo--;
			ans+=check(1,oo->second);
		}
		nw=1;
		rep0(i,tot+10)c[i]=0;
		rep(i,cp){
			while(nw<=cc){
				if(fc[nw].x+1<fp[i].x)break;
				if(fc[nw].x%2ll==0)ins(fc[nw].v,1);
				nw++;
			}
			if(fp[i].x%2ll==0)continue;
			map<ll,ll>::iterator oo=mp.upper_bound(mx-fp[i].v);
			if(oo==mp.begin())continue;
			oo--;
			ans+=check(1,oo->second);
		}
		ll mod=998244353;
		printf("%lld\n",ans%mod);
	}
	return 0;
}