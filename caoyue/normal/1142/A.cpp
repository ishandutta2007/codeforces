#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=7;
const ll INF=1e18+7;
ll n,k,a,b,x=INF,y=0;
ll gcd(ll u,ll v){return v?gcd(v,u%v):u;}
void wz(ll u,ll v){
	ll d=abs(u-v);
	x=min(x,n*k/gcd(n*k,d));
	y=max(y,n*k/gcd(n*k,d));
}
ll hh(ll u,ll v){
	rep0(i,n)wz(u,v+i*k);
}
int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&a,&b);
	hh(a,b);
	hh(a,k-b);
	hh(k-a,b);
	hh(k-a,k-b);
	printf("%I64d %I64d\n",x,y);
	return 0;
}