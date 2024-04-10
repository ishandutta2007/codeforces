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
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=2e5+7;
const ll INF=1e9+7;
ll n,k,m;
struct pir{ll x,d;}p[N];
bool g[N];
bool cmp(pir x,pir y){return x.x>y.x;}
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	rep(i,n)scanf("%I64d",&p[i].x),p[i].d=i;
	sort(p+1,p+n+1,cmp);
	ll sm=0,ans=0,ss=0;
	rep(i,k*m){
		g[p[i].d]=1;
		ans+=p[i].x;
	}
	printf("%I64d\n",ans);
	rep(i,n){
		sm+=g[i];
		ss+=g[i];
		if(sm==m&&ss!=m*k){
			printf("%I64d ",i);
			sm=0;
		}
	}
	puts("");
	return 0;
}