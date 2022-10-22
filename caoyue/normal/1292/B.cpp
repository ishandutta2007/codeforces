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
const ll N=77;
const ll INF=2e16+7;
ll X[N],Y[N];
ll n=0,ax,ay,bx,by,sx,sy,t;
ll d(ll x1,ll y1,ll x2,ll y2){return abs(x1-x2)+abs(y1-y2);}
int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&X[0],&Y[0],&ax,&ay,&bx,&by,&sx,&sy,&t);
	while(X[n]<=INF&&Y[n]<=INF){
		X[n+1]=X[n]*ax+bx;
		Y[n+1]=Y[n]*ay+by;
		n++;
	}
	ll ans=0;
	rep0(i,n){
		REP(j,i,n-1){
			if(d(X[i],Y[i],X[j],Y[j])+d(sx,sy,X[i],Y[i])<=t)ans=max(ans,j-i+1);
			if(d(X[i],Y[i],X[j],Y[j])+d(sx,sy,X[j],Y[j])<=t)ans=max(ans,j-i+1);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}