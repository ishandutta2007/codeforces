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
const ll N=2007;
const ll mod=1e9+7;
ll f[N][N],g[N][N],s1[N][N],s2[N][N],w1[N][N],w2[N][N];
char s[N][N];
ll n,m;

int main(){
	scanf("%I64d%I64d",&n,&m);
	rep(i,n)scanf("%s",s[i]+1);
	rep(i,n)for(ll j=m;j;j--)if(s[i][j]=='R')w1[i][++w1[i][0]]=j;
	rep(j,m)for(ll i=n;i;i--)if(s[i][j]=='R')w2[j][++w2[j][0]]=i;
	f[1][1]=g[1][1]=s1[1][1]=s2[1][1]=1;
	rep(i,n){
		rep(j,m){
			if(i==1&&j==1)continue;
			if(w1[i][0]<m-j+1)g[i][j]=(f[i][j]+s1[i][j-1])%mod;
			else g[i][j]=(f[i][j]+s1[i][j-1]-s1[i][w1[i][m-j+1]-1]+mod)%mod;
			if(w2[j][0]<n-i+1)f[i][j]=(f[i][j]+s2[i-1][j])%mod;
			else f[i][j]=(f[i][j]+s2[i-1][j]-s2[w2[j][n-i+1]-1][j]+mod)%mod;
			s1[i][j]=(s1[i][j-1]+f[i][j])%mod;
			s2[i][j]=(s2[i-1][j]+g[i][j])%mod;
		}
	}
	if(n!=1||m!=1)printf("%I64d\n",(f[n][m]+g[n][m])%mod);
	else{
		if(s[1][1]=='R')puts("0");
		else puts("1");
	}
	return 0;
}