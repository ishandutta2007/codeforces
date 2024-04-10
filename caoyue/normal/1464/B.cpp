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
const ll N=1e5+7;
const ll INF=1e9+7;
char s[N];
ll a[N],s0[N],s1[N],e0[N],e1[N];
ll n,v1,v2;

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,n){
		if(s[i]!='?')a[i]=s[i]-'0';
		else a[i]=-1;
	}
	scanf("%lld%lld",&v1,&v2);
	if(v1<v2){
		swap(v1,v2);
		rep(i,n)if(~a[i])a[i]^=1;
	}
	rep(i,n){
		s0[i]=s0[i-1]+(a[i]==0);
		s1[i]=s1[i-1]+(a[i]==1);
	}
	ll ss=0;
	rep(i,n){
		e0[i]=e0[i-1];
		e1[i]=e1[i-1];
		if(a[i]<0){
			e0[i]+=v1*(s1[n]-s1[i])+v2*s1[i];
			e1[i]+=v1*s0[i]+v2*(s0[n]-s0[i]);
			ss++;
		}
	}
	ll ans=e1[n],nw=0;
	rep(i,n){
		if(a[i]<0){
			nw++;
			ans=min(ans,e1[i-1]+e0[n]-e0[i-1]+v2*(nw-1)*(ss-nw+1));
		}
	}
	rep(i,n)if(a[i]==0)ans+=v1*(s1[n]-s1[i])+v2*s1[i];
	printf("%lld\n",ans);
	return 0;
}