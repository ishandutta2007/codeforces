#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1e6+7;
const ll mod=1e9+7;
ll f[N][2],g[N][2];
ll n,m;

int main(){
	scanf("%I64d%I64d",&n,&m);
	f[1][0]=2;
	REP(i,2,n){
		f[i][1]=f[i-1][0];
		f[i][0]=(f[i-1][1]+f[i-1][0])%mod;
	}
	g[1][0]=2;
	REP(i,2,m){
		g[i][1]=g[i-1][0];
		g[i][0]=(g[i-1][1]+g[i-1][0])%mod;
	}
	printf("%I64d\n",(g[m][0]+g[m][1]+f[n][0]+f[n][1]-2+mod)%mod);
	return 0;
}