#include<cstdio>
int G(int a,int b){return b?G(b,a%b):a;}
const int N=702;
int a[N],f[N][N],l[N][N],r[N][N],g[N][N],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=0;i<=n+1;i++)for(int j=i+1;j<=n+1;j++)g[i][j]=G(a[i],a[j])>1;
	for(int i=1;i<=n;i++)l[i][i]=r[i][i]=1;
	for(int k=0;k<n;k++)
	  for(int i=1;i+k<=n;i++)
		for(int j=i;j<=i+k;j++)if(l[i][j]&&r[j][i+k])
		  f[i][i+k]=1,
		  l[i][i+k+1]|=g[j][i+k+1],r[i-1][i+k]|=g[i-1][j];
	puts(f[1][n]?"Yes":"No");
	return 0;
}