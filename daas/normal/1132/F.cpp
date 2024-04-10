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
int n,dp[501][501];
char s[501];
int fun(int l,int r)
{
	if(l>r)
		return 0;
	if(l==r)
		return 1;
	if(dp[l][r]!=-1)
		return dp[l][r];
	dp[l][r]=fun(l+1,r)+1;
	for(int i=l+1;i<=r;++i)
		if(s[l]==s[i])
			dp[l][r]=min(dp[l][r],fun(l+1,i-1)+fun(i,r));
	return dp[l][r];
}
int main()
{
	n=read();
	scanf("%s",s+1);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",fun(1,n));
	return 0;
}