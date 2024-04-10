#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=5e5+7;
const ll INF=1e18+7;
ll n,k;
ll c[N],w[N];

int main(){
	scanf("%I64d%I64d",&n,&k);
	rep(i,n)scanf("%I64d",&c[i]);
	sort(c+1,c+n+1);
	k++;
	if(c[1]>=0){
		ll ans=0;
		for(ll i=n;i;i--)ans+=c[i]*(i-1);
		printf("%I64d\n",ans);
		return 0;
	}
	ll nw=n,ss=0,ans=-INF,sm=0;
	rep(i,n){
		if(c[i]>=0){
			nw=i-1;
			break;
		}
	}
	REP(i,nw+1,n){
		ss+=c[i]*(i-nw-1);
		sm+=c[i];
	}
	rep(i,nw){
		w[i]=c[i]*((i-1)/k);
		w[i]+=w[i-1];
	}
	for(ll i=nw;~i;i--){
		ans=max(ans,w[i]+((i+k-1)/k)*sm+ss);
		ss+=sm;
		sm+=c[i];
	}
	printf("%I64d\n",ans);
	return 0;
}