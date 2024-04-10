#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e6+7;
const int INF=1e9+7;
ll c1[N],c2[N];
ll n,m=0,ans=0;

int main(){
	scanf("%I64d",&n);
	c2[0]++;
	rep(i,n){
		ll x; scanf("%I64d",&x);
		m^=x;
		if(i&1)c1[m]++;
		else c2[m]++;
	}
	rep0(i,N){
		ans=(ans+c1[i]*(c1[i]-1)/2);
		ans=(ans+c2[i]*(c2[i]-1)/2);
	}
	printf("%I64d\n",ans);
	return 0;
}