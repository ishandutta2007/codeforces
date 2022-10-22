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
const int N=3e5+7;
const int INF=1e9+7;
ll n;
ll s[N];

int main(){
	scanf("%I64d",&n);
	rep(i,n)scanf("%I64d",&s[i]);
	sort(s+1,s+n+1);
	ll ans=0;
	rep(i,n/2)ans=(ans+(s[i]+s[n-i+1])*(s[i]+s[n-i+1]));
	printf("%I64d",ans);
	return 0;
}