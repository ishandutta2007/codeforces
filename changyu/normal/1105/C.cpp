#include<cstdio>
const int N=2e5+1,M=1e9+7;
int f[N][3],a[3],n,l,r;
int main(){
	scanf("%d%d%d",&n,&l,&r);
	a[0]=r/3-(l-1)/3;
	a[1]=(r+2)/3-(l+1)/3;
	a[2]=(r+1)/3-l/3;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	  for(int j=0;j<3;j++)
		for(int k=0;k<3;k++)
		  f[i][j]=(f[i][j]+1ll*f[i-1][(j-k+3)%3]*a[k])%M;
	printf("%d",f[n][0]);
	return 0;
}