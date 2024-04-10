#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
const int d1[2]={25,1};
const int t1[2][2]={{24,1},
					{25,0}};
const int d2[3]={24,1,1};
const int t2[3][3]={{23,1,1},
					{24,0,1},
					{24,1,0}};
int c[26],n,ans=1;
int f[403][403][2][2];
int g[403][403][3][3],g1[403][403][3][3];
int main(){
	scanf("%d",&n);
	for(int i=0;i<26;i++)scanf("%d",&c[i]);
	ans=26*26;
	for(int i=3;i<=n;i++)ans=(long long)ans*25%MOD;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)f[2][i+j][i][j]=d1[i]*d1[j];
	for(int i=3;i<=n;i++)for(int j=0;j<i;j++)for(int k=0;k<2;k++)for(int l=0;l<2;l++)
		for(int p=0;p<2;p++)(f[i][j+p][l][p]+=(long long)f[i-1][j][k][l]*t1[k][p]%MOD)%=MOD;
	for(int i=0;i<26;i++)for(int j=c[i]+1;j<=n;j++)
		for(int k=0;k<2;k++)for(int l=0;l<2;l++)
			(ans+=MOD-f[n][j][k][l])%=MOD;
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)g[(i==1)+(j==1)][(i==2)+(j==2)][i][j]=d2[i]*d2[j];
	for(int i=3;i<=n;i++){
		memset(g1,0,sizeof(g1));
		for(int j=0;j<i/2+3;j++)for(int k=0;k<i-j;k++)for(int l=0;l<3;l++)for(int p=0;p<3;p++)
			for(int q=0;q<3;q++)(g1[j+(q==1)][k+(q==2)][p][q]+=(long long)g[j][k][l][p]*t2[l][q]%MOD)%=MOD;
		for(int j=0;j<=i;j++)for(int k=0;k<=i-j;k++)for(int l=0;l<3;l++)for(int p=0;p<3;p++)g[j][k][l][p]=g1[j][k][l][p];
	}
	for(int i=0;i<26;i++)for(int j=i+1;j<26;j++)
		for(int k=c[i]+1;k<=n;k++)for(int l=c[j]+1;l<=n;l++)
			for(int p=0;p<3;p++)for(int q=0;q<3;q++)
				(ans+=g[k][l][p][q])%=MOD;
	printf("%d",ans);
}