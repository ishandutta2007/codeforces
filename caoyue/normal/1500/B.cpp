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
const ll N=1e6+7;
const ll INF=1e18+7;
ll n,m,k,cnt=0,tt;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll a[N],b[N],c[N];
bool check(ll x){
	ll ss=0;
	rep(i,cnt){
		if(x<c[i])continue;
		ll v=x-c[i];
		ss+=(1+v/tt);
	}
	return (x-ss)>=k;
}
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	rep(i,n){
		ll x; scanf("%I64d",&x); 
		a[x]=i;
	}
	rep(i,m){
		ll y; scanf("%I64d",&y);
		b[y]=i;
	}
	ll t=n*m/gcd(n,m),u=gcd(n,m);
	tt=t;
	ll wn=n/u,wm=m/u,ph=n/u,hh=n/u;
	REP(i,2,wn){
		if(hh%i==0){
			while(hh%i==0)hh/=i;
			ph=ph/i*(i-1);
		}
	}
	ll iv=1;
	rep(i,ph-1)iv=iv*wm%wn;
	rep(i,2*max(n,m)){
		if(!a[i]||!b[i])continue;
		ll o1=a[i]-1,o2=b[i]-1;
		if(o1%u!=o2%u)continue;
		ll w=(o1-o2%n+n)%n/u;
		ll kk=w*iv%wn;
		c[++cnt]=kk*m+b[i];
	}
	ll L=1,R=INF;
	while(L<R-1){
		ll mid=(L+R)>>1;
		if(check(mid))R=mid;
		else L=mid;
	}
	if(check(L))printf("%I64d\n",L);
	else printf("%I64d\n",R);
	return 0;
}