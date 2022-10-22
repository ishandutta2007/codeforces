#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
inline int read()
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
int n,m,q,num[41][41],dp[41][41][41][41],sum[41][41][41][41];
inline int get(int a,int b,int c,int d)
{
	return num[c][d]-num[a-1][d]-num[c][b-1]+num[a-1][b-1]==0;
}
int main()
{
	n=read(),m=read(),q=read();
	for(register int i=1;i<=n;++i)
	{
		string s;
		cin>>s;
		for(register int j=1;j<=m;++j)
			num[i][j]=num[i-1][j]+num[i][j-1]-num[i-1][j-1]+s[j-1]-'0';
	}
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=m;++j)
		{
			sum[i][j][i][j]=get(i,j,i,j);
			for(register int k=i-1;k>=1;--k)
				sum[k][j][i][j]=sum[k+1][j][i][j]+get(k,j,i,j);
			for(register int k=j-1;k>=1;--k)
				sum[i][k][i][j]=sum[i][k+1][i][j]+get(i,k,i,j);
			for(register int k=i-1;k>=1;--k)
				for(register int w=j-1;w>=1;--w)
					sum[k][w][i][j]=sum[k+1][w][i][j]+sum[k][w+1][i][j]-sum[k+1][w+1][i][j]+get(k,w,i,j);
		}
	//for(register int i=1;i<=n;++i)
	//	for(register int j=1;j<=n;++j)
	//		for(register int k=1;k<=i;++k)
	//			for(register int w=1;w<=j;++w)
	//				cout<<k<<" "<<w<<" "<<i<<" "<<j<<" "<<sum[k][w][i][j]<<endl;
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=m;++j)
		{
			dp[i][j][i][j]=sum[i][j][i][j];
			for(register int k=i+1;k<=n;++k)
				dp[i][j][k][j]=dp[i][j][k-1][j]+sum[i][j][k][j];
			for(register int k=j+1;k<=m;++k)
				dp[i][j][i][k]=dp[i][j][i][k-1]+sum[i][j][i][k];
			for(register int k=i+1;k<=n;++k)
				for(register int w=j+1;w<=m;++w)
					dp[i][j][k][w]=dp[i][j][k-1][w]+dp[i][j][k][w-1]-dp[i][j][k-1][w-1]+sum[i][j][k][w];
		}
	for(register int i=1;i<=q;++i)
	{
		int a=read(),b=read(),c=read(),d=read();
		printf("%d\n",dp[a][b][c][d]);
	}
	return 0;
}