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
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e5+7;
const int INF=1e9+7;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll a[N],b[N];
ll v=0,n,m;

int main(){
	scanf("%I64d%I64d",&n,&m);
	rep(i,n)scanf("%I64d",&a[i]);
	rep(i,m)scanf("%I64d",&b[i]);
	rep(i,n-1)v=gcd(v,abs(a[i+1]-a[i]));
	rep(i,m){
		ll p=gcd(b[i]+a[1],v);
		printf("%I64d ",p);
	}
	puts("");
	return 0;
}