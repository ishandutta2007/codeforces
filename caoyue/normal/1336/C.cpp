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
const ll N=3007;
const ll INF=1e9+7;
const ll mod=998244353;
char s[N],t[N];
ll f[N][N],g[N][N],pw[N];
ll n,m;

int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	pw[0]=1;
	rep(i,n)pw[i]=pw[i-1]*2%mod;
	rep(i,m)if(s[1]==t[i]){
		if(i!=m)f[1][i]=1;
		else g[1][m]=1;
	}
	ll ans=0;
	rep(i,n-1){
		for(ll j=1;j+i-1<m;j++){
			if(j>1&&s[i+1]==t[j-1])f[i+1][j-1]=(f[i+1][j-1]+f[i][j])%mod;
			if(s[i+1]==t[j+i]){
				if(j+i==m)g[i+1][j]=(g[i+1][j]+f[i][j])%mod;
				else f[i+1][j]=(f[i+1][j]+f[i][j])%mod;
			}
		}
		rep(j,m){
			g[i+1][j]=(g[i+1][j]+g[i][j])%mod;
			if(j>1&&s[i+1]==t[j-1])g[i+1][j-1]=(g[i+1][j-1]+g[i][j])%mod;
		}
		if(s[i+1]==t[m])g[i+1][m]=(g[i+1][m]+pw[i-1])%mod;
	}
	rep(i,n)ans=(ans+g[i][1])%mod;
	printf("%lld\n",ans*2%mod);
	return 0;
}