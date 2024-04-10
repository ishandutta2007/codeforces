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
const ll INF=1e18+7;
ll n,m,T;
ll k[N],c[N],w[N],sc[N],ek[N];

int main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&m);
		rep(i,n)scanf("%I64d",&k[i]);
		rep(i,m)scanf("%I64d",&c[i]);
		rep(i,m)w[i]=0;
		rep(i,n)w[k[i]]++;
		sort(k+1,k+n+1);
		ek[0]=0;
		rep(i,n)ek[i]=ek[i-1]+c[k[i]];
		ll ans=INF;
		rep(i,m){
			sc[i]=sc[i-1]+c[i];
			w[i]+=w[i-1];
			if(i>=n-w[i])ans=min(ans,sc[i]+ek[n-i]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}