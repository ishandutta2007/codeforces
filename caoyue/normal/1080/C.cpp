#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=7;
const int INF=1e9+7;
ll sw(ll x,ll y){
	if(x&1)return (y+1)/2+sw(x-1,y);
	if(y&1)return x/2+sw(x,y-1);
	return x*y/2;
}
ll sb(ll x,ll y){return x*y-sw(x,y);}
ll cw(ll l,ll r,ll u,ll d){return sw(l-1,u-1)+sw(r,d)-sw(l-1,d)-sw(r,u-1);}
ll cb(ll l,ll r,ll u,ll d){return sb(l-1,u-1)+sb(r,d)-sb(l-1,d)-sb(r,u-1);}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		ll n,m; scanf("%I64d%I64d",&n,&m);
		ll l1,r1,u1,d1; scanf("%I64d%I64d%I64d%I64d",&l1,&u1,&r1,&d1);
		ll l2,r2,u2,d2; scanf("%I64d%I64d%I64d%I64d",&l2,&u2,&r2,&d2);
		ll l3=max(l1,l2),r3=min(r1,r2),u3=max(u1,u2),d3=min(d1,d2),w=sw(n,m),b=sb(n,m);
		w-=cw(l1,r1,u1,d1);
		w-=cw(l2,r2,u2,d2);
		b-=cb(l1,r1,u1,d1);
		b-=cb(l2,r2,u2,d2);
		w+=(r1-l1+1)*(d1-u1+1);
		b+=(r2-l2+1)*(d2-u2+1);
		if(l3<=r3&&u3<=d3){
			w+=cw(l3,r3,u3,d3);
			b+=cb(l3,r3,u3,d3);
			w-=(r3-l3+1)*(d3-u3+1);
		}
		printf("%I64d %I64d\n",w,b);
	}
	return 0;
}