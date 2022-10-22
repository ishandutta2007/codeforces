#include<cstdio>
using namespace std;
#pragma GCC optimize(2)
#pragma GCC optimize(3)
const int o=110;
int n,m,k,p,f[o][o][o],c[o][o],fac[o];bool vis[o][o][o];
int dp(int i,int j,int $){
	if(j>i||!j) return $?0:fac[i];
	if(vis[i][j][$]) return f[i][j][$];vis[i][j][$]=1;
	for(int x=1;x<=i;++x) for(int y=0,_;y+(j==1)<=$;++y)
		if(_=c[i-1][x-1]*1ll*dp(x-1,j-1,y)%p) f[i][j][$]=(f[i][j][$]+_*1ll*dp(i-x,j-1,$-(j==1)-y))%p;
	return f[i][j][$];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=fac[0]=1;i<=n;++i) fac[i]=fac[i-1]*1ll*i%p;
	for(int i=c[0][0]=1;i<=n;++i) for(int j=c[i][0]=1;j<=i;++j) c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
	printf("%d",dp(n,m,k));
	return 0;
}