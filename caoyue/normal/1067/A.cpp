#include<iostream>
#include<cstring>
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
const int N=1e5+7;
const int M=222;
const int INF=1e9+7;
const int mod=998244353;
int f[N][M],g[N][M],a[N],b[M],c[M];
int n;

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	if(~a[1])g[1][a[1]]=1;
	else rep(i,200)g[1][i]=1;
	REP(i,2,n){
		c[0]=b[201]=0;
		rep(j,200)c[j]=(c[j-1]+(f[i-1][j]+g[i-1][j])%mod)%mod;
		for(int j=200;j;j--)b[j]=(b[j+1]+f[i-1][j])%mod;
		if(~a[i]){
			f[i][a[i]]=(b[a[i]]+g[i-1][a[i]])%mod;
			g[i][a[i]]=c[a[i]-1];
		}
		else rep(j,200)f[i][j]=(b[j]+g[i-1][j])%mod,g[i][j]=c[j-1];
	}
	int ans=0;
	rep(j,200)ans=(ans+f[n][j])%mod;
	printf("%d\n",ans);
	return 0;
}