#include<cstdio>
#include<cstring>
#define MN 100
#define MM 1000
double f[MN+5][MN*MM+5];
double F(int x,int y){return y<0?0:f[x][y];}
int main()
{
	int n,m,i,j,x,s=0;
	scanf("%d%d",&n,&m);
	if(m==1)return 0*puts("1");
	for(i=0;i<=n*m;++i)f[0][i]=1;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&x);s+=x;
		for(j=1;j<=n*m;++j)f[i][j]=f[i][j-1]+
			F(i-1,j-1)-F(i-1,j-m-1)-F(i-1,j-x)+F(i-1,j-x-1);
	}
	for(i=1;i<n;++i)f[n][s-1]/=m-1;
	printf("%.10lf",f[n][s-1]+1);
}