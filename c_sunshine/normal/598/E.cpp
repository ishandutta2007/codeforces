#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
const int inf=(1<<28)-1;
int f[33][33][55];

int dp(int n,int m,int k)
{
	int &r=f[n][m][k];
	if(r!=-1)return r;
	if(n*m<k)return r=inf;
	if(n*m==k)return r=0;
	if(k==0)return r=0;
	r=inf;
	for(int t=m*m,i=1;i<n;i++)
		for(int j=0;j<=k;j++)
			r=min(r,dp(i,m,j)+dp(n-i,m,k-j)+t);
	for(int t=n*n,i=1;i<m;i++)
		for(int j=0;j<=k;j++)
			r=min(r,dp(n,i,j)+dp(n,m-i,k-j)+t);
	return r;
}

int main()
{
	memset(f,-1,sizeof(f));
	int t,n,m,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		printf("%d\n",dp(n,m,k));
	}
	return 0;
}