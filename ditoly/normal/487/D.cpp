#include<cstdio>
int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#define MAXN 100000
#define MAXM 10
#define K 1000
char s[MAXN+5][MAXM+5];
int n,m,x[MAXN+5][MAXM+5],y[MAXN+5][MAXM+5];
int u[MAXN+5][MAXM+5],cnt;
void work(int i,int j)
{
	u[i][j]=cnt;
	if(u[i][j-1]!=cnt&&s[i][j-1]=='>')
		x[i][j-1]=x[i][j],y[i][j-1]=y[i][j],work(i,j-1);
	if(u[i][j+1]!=cnt&&s[i][j+1]=='<')
		x[i][j+1]=x[i][j],y[i][j+1]=y[i][j],work(i,j+1);
	if(i%K&&u[i+1][j]!=cnt&&s[i+1][j]=='^')
		x[i+1][j]=x[i][j],y[i+1][j]=y[i][j],work(i+1,j);
}
void build(int i)
{
	int j,k;cnt++;
	for(j=1;j<=m;j++)if(s[i][j]=='^')
		x[i][j]=i-1,y[i][j]=j,work(i,j);
	for(j=i;j<=n&&j<i+K;j++)
	{
		if(s[j][1]=='<')x[j][1]=j,y[j][1]=0,work(j,1);
		if(s[j][m]=='>')x[j][m]=j,y[j][m]=m+1,work(j,m);
		for(k=1;k<=m;k++)if(u[j][k]!=cnt)x[j][k]=y[j][k]=-1;
	}
}
int main()
{
	int q,i,j,k;char c;
	n=read();m=read();q=read();
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		for(j=m;j;j--)s[i][j]=s[i][j-1];
		s[i][0]=s[i][m+1]=0;
	}
	for(i=1;i<=m;i++)x[0][i]=0,y[0][i]=i;
	for(i=1;i<=n;i++)x[i][0]=x[i][m+1]=i,y[i][0]=0,y[i][m+1]=m+1;
	for(i=1;i<=n;i+=K)build(i);
	while(q--)
	{
		do c=getchar();while(c!='A'&&c!='C');
		i=read();j=read();
		if(c=='A')
		{
			while(i>0&&j>0&&j<=m)i=x[k=i][j],j=y[k][j];
			printf("%d %d\n",i,j);
		}
		if(c=='C')
		{
			s[i][j]=getchar();
			build((i-1)/K*K+1);
		}
	}
}