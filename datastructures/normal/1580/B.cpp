#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,c,mod;
int fac[105],C[105][105],f[105][105][105];
int val[105];
void getmod(int &x){
	if (x>=mod)x-=mod;
	return;
}
int main(){
	cin>>n>>m>>c>>mod;
	for (int i=0;i<=n;i++)C[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1],getmod(C[i][j]);
	fac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for (int i=0;i<=n;i++)f[0][i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n&&j<=m;j++)
			for (int k=0;k<=i&&k<=c;k++){
                if (m-j>n-i)continue;
				if (j>i){
					if (k==0)f[i][j][k]=fac[i];
					continue;
				}
				if (j==1){
					if (k==1)f[i][j][k]=fac[i];
					else f[i][j][k]=0;
					continue;
				}
				memset(val,-1,sizeof(val));
				for (int o=1;o<=i;o++){
					int num=0;
					if (val[o]!=-1)num=val[o];
					else{
						if (o==1||o==i)num=f[i-1][j-1][k];
						else{
							for (int p=0;p<=k;p++)
								num=(num+1ll*f[o-1][j-1][p]*f[i-o][j-1][k-p])%mod;
						}
						val[o]=val[i-o+1]=num;
					}
					f[i][j][k]=(f[i][j][k]+1ll*num*C[i-1][o-1])%mod;
				}
			}
	cout<<f[n][m][c]<<endl;
	return 0;
}