#include<cstdio>
#define ll long long
#define MOD 1000000007
#define MAXT 200
#define MAX 400000
int f[MAXT+5][MAX+5];
inline int F(int x,int y){return y<0?0:f[x][y];}
int main()
{
	int a,b,k,t,p,i,j;
	scanf("%d %d %d %d",&a,&b,&k,&t);
	k<<=1;a=t*k-a+b;t<<=1;p=t*k;
	if(a>p){puts("0");return 0;}
	for(i=0;i<=p;i++)f[0][i]=1;
	for(i=1;i<=t;i++)for(j=0;j<=p;j++)
		f[i][j]=((ll)F(i,j-1)+F(i-1,j)-F(i-1,j-k-1))%MOD;
	p=(F(t,p)-F(t,a))%MOD;if(p<0)p+=MOD;
	printf("%d",p);
}