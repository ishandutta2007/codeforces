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
int T,n;
ll x[N];
ll k;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%I64d",&n,&k);
		rep(i,n)scanf("%I64d",&x[i]);
		k-=x[1];
		ll g=0;
		REP(i,2,n){
			if(!(x[i]-x[1]))continue;
			g=gcd(abs(x[i]-x[1]),g);
		}
		if(!k)puts("YES");
		else if(!g)puts("NO");
		else if(abs(k)%g!=0)puts("NO");
		else puts("YES");
	}
	return 0;
}