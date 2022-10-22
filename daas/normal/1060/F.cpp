#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,head[51],tot,size[51];
double dp[51][51],g[51],mem[51],C[51][51];
struct sb
{
	int to,nextn;
}a[101];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void fun(int u,int fa)
{
	dp[u][0]=size[u]=1;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		fun(v,u);
		for(int j=0;j<=size[v];++j)
		{
			g[j]=(size[v]-j)*dp[v][j];
			for(int k=0;k<j;++k)
				g[j]+=0.5*dp[v][k];
		}
		for(int j=0;j<=size[u]+size[v];++j)
			mem[j]=0;
		for(int j=0;j<size[u];++j)
			for(int k=0;k<=size[v];++k)
				mem[j+k]+=dp[u][j]*g[k]*C[j+k][k]*C[size[u]-j-1+size[v]-k][size[v]-k];
		size[u]+=size[v];
		for(int j=0;j<=size[u];++j)
			dp[u][j]=mem[j];
	}
}
int main()
{
	n=read();
	for(int i=0;i<=n;++i)
		C[i][0]=C[i][i]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		ADD(u,v);
		ADD(v,u);
	}
	double P=1.0;
	for(int i=1;i<n;++i)
		P*=i;
	for(int i=1;i<=n;++i)
	{
		memset(dp,0,sizeof(dp));
		fun(i,0);
		printf("%.10lf\n",dp[i][n-1]/P);
	}
	return 0;
}