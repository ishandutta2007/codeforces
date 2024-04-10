#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=305;
const LL inf=1e18;
int n,m,ans;LL e[11][N][N],dis[N][N],cp[N][N];bool flcyc;
void chkma(LL &x,LL y){x=x>y?x:y;}
void init(){for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)e[0][i][j]=dis[i][j]=-inf;} 
int main(){
	scanf("%d%d",&n,&m);init();
	for(int i=1,u,v,w,w2;i<=m;i++)scanf("%d%d%d%d",&u,&v,&w,&w2),e[0][u][v]=w,e[0][v][u]=w2;
	for(int t=1;t<=10;t++){
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)e[t][i][j]=e[t-1][i][j];
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
			chkma(e[t][i][j],e[t-1][i][k]+e[t-1][k][j]);
	}
	for(int t=10;~t;t--){
		memcpy(cp,dis,sizeof(cp));
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)chkma(cp[i][j],e[t][i][j]);
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
			chkma(cp[i][j],dis[i][k]+e[t][k][j]);
		bool fl=false;
		for(int i=1;i<=n;i++)if(cp[i][i]>0){fl=flcyc=true;break;}
		if(!fl)memcpy(dis,cp,sizeof(dis)),ans+=(1<<t);
	}
	if(!flcyc)puts("0");else printf("%d\n",ans+1);
	return 0;
}