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
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1e6+7;
const ll INF=1e9+7;
ll n,tp;
ll a[N],sm[N];
ll S[N];
bool rs(ll x,ll y,ll z){
	ll x1=z-y,x2=y-x,y1=sm[z]-sm[y],y2=sm[y]-sm[x];
	return x2*y1<x1*y2;
}
int main(){
	scanf("%lld",&n);
	rep(i,n)scanf("%lld",&a[i]);
	rep(i,n)sm[i]=sm[i-1]+a[i];
	S[0]=0;
	rep(i,n){
		while(tp&&rs(S[tp-1],S[tp],i))tp--;
		S[++tp]=i;
	}
	rep(i,tp){
		db ss=(db)(sm[S[i]]-sm[S[i-1]])/(S[i]-S[i-1]);
		REP(j,S[i-1]+1,S[i])printf("%.10lf\n",ss);
	}
	puts("");
	return 0;
}