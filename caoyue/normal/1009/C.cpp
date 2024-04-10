#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define db double
#define ll long long
const ll N=1e5+7;
const ll INF=1e9+7;
ll s1=0,s2=0,ans=0;
int n,m,x,y;
ll abss(ll x){
	if(x>=0)return x;
	return -x;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)s1+=(i-1);
	ll p=(n+1)/2;
	rep(i,n)s2+=abss(i-p);
	rep(i,m){
		scanf("%d%d",&x,&y);
		ans=ans+x*n;
		if(y>=0)ans=ans+y*s1;
		else ans=ans+y*s2;
	}
	db q=(db)ans/n;
	printf("%.15lf\n",q);
	return 0;
}