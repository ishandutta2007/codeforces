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
const int N=1e5+7;
const int INF=1e9+7;
ll n,m,k;
ll p[N];
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	rep(i,m)scanf("%I64d",&p[i]);
	ll nw=1,ans=0;
	while(nw<=m){
		ll s=nw-1;
		nw++;
		while((p[s+1]-s-1)/k==(p[nw]-s-1)/k&&nw<=m)nw++;
		ans++;
	}
	printf("%I64d\n",ans);
	return 0;
}