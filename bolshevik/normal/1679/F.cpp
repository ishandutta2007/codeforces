#include<cstdio>
using namespace std;
const int o=50010,MOD=998244353;
int n,m,e[10][10],f[o][1<<10],g[10][1<<10],ans;bool h[10][1<<10];
int main(){
	scanf("%d%d",&n,&m);
	for(int u,v;m--;e[u][v]=e[v][u]=1) scanf("%d%d",&u,&v);
	for(int i=0,mask;i<(1<<10);++i) for(int j=0;j<10;++j){
		mask=i;
		for(int k=0;k<10;++k) if((mask&(1<<k))&&!e[k][j]) mask^=(1<<k);
		g[j][i]=mask|(1<<j);
	}
	for(int i=0;i<(1<<10);++i) for(int j=0;j<10;++j)
		for(int k=j;k--;) if(e[k][j]&&(i&(1<<k))) h[j][i]=true;
	f[n+1][0]=1;
	for(int i=n;i;--i) for(int j=0;j<(1<<10);++j) if(f[i+1][j])
		for(int k=0;k<10;++k) if(!h[k][j]) f[i][g[k][j]]=(f[i][g[k][j]]+f[i+1][j])%MOD;
	for(int i=0;i<(1<<10);++i) ans=(ans+f[1][i])%MOD;
	printf("%d",ans);
	return 0;
}