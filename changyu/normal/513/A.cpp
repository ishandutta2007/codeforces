#include<cstdio>
int f[2][51][51],n1,n2,m1,m2;
inline int max0(int a){return a>0?a:0;}
int main()
{
	scanf("%d%d%d%d",&n1,&n2,&m1,&m2);
	f[0][0][0]=1;
	for(int i=1;i<=n1;i++)f[1][i][0]=f[0][i][0]=1;
	for(int i=1;i<=n1;i++)
	for(int j=1;j<=n2;j++){
	  f[1][i][j]=0;
	  for(int k=max0(i-m1);k<i;k++)
		if(f[0][k][j])f[1][i][j]=1;
	  f[0][i][j]=1;
	  for(int k=max0(j-m2);k<j;k++)
		if(!f[1][i][k])f[0][i][j]=0;
	}puts(f[1][n1][n2]?"First":"Second");
	return 0;
}