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
const ll N=70007;
const ll mod=1e9+7;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll x,y,cnt=0;
ll d[N],f[N];

int main(){
	scanf("%I64d%I64d",&x,&y);
	if(y%x!=0){puts("0"); return 0;}
	y/=x;
	rep(i,sqrt(y)){
		if(y%i==0){
			d[++cnt]=i;
			if(i*i!=y)d[++cnt]=y/i;
		}
	}
	sort(d+1,d+cnt+1);
	for(ll i=cnt;i;i--)f[i]=Pow(2,y/d[i]-1);
	for(ll i=cnt;i;i--){
		for(ll j=cnt;j>i;j--){
			if(d[j]%d[i]!=0)continue;
			f[i]=(f[i]<f[j])?f[i]-f[j]+mod:f[i]-f[j];
		}
	}
	printf("%lld\n",f[1]);
	return 0;
}