#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int n,m;
char c[253][253];
int f[32800][2][2],nf[32800][2][2],ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",c[i]);
	if(n<m){
		swap(n,m);
		for(int i=0;i<n;i++)for(int j=i;j<n;j++)swap(c[i][j],c[j][i]);
	}
	f[0][0][0]=1;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){         
		memset(nf,0,sizeof(nf));
		for(int k=0;k<(1<<m);k++)for(int p=0;p<2;p++)for(int q=0;q<2;q++)if(f[k][p][q]){
			int np=p;
			if(p&&j==0)np=0;
			if(c[i][j]=='x')(nf[(k|(1<<j))^(1<<j)][0][q]+=f[k][p][q])%=M;
			else{
				if(!q||(k&(1<<j))||np)(nf[k][np][q+(!(k&(1<<j))&&!np)]+=f[k][p][q])%=M;
				(nf[k|(1<<j)][1][q]+=f[k][p][q])%=M;
			}
		}
		memcpy(f,nf,sizeof(nf));
	}
	for(int i=0;i<(1<<m);i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)
		(ans+=f[i][j][k])%=M;
	printf("%d",ans);
}