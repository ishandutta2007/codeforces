#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=2e5+7;
const ll INF=1e9+7;
ll f[N],st[N][22],mn[N];
ll qry(ll L,ll R){
	ll k=mn[R-L+1];
	return min(st[L][k],st[R-(1<<k)+1][k]);
}
int main(){
	ll c,n,ans=0; scanf("%I64d%I64d",&n,&c);
	if(c==1){
		printf("0\n");
		return 0;
	}
	rep(i,n)scanf("%I64d",&st[i][0]);
	rep(i,n)ans+=st[i][0];
	for(ll i=1;(1<<i)<=n;i++){
		rep(j,n-(1<<i)+1)st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		REP(j,(1<<i)+1,(1<<(i+1)))mn[j]=i;
	}
	f[0]=0;
	rep(i,n){
		f[i]=f[i-1];
		if(i>=c)f[i]=max(f[i],f[i-c]+qry(i-c+1,i));
	}
	printf("%I64d\n",ans-f[n]);
	return 0;
}