#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
const int mod=2520;
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
int T,dp[20][2520][5][3][2][2],z[20],top,P[10][4];
int check(int rest,int v2,int v3,int v5,int v7)
{
	for(int i=1;i<=v2;++i,rest/=2)
		if(rest%2)
			return 0;
	for(int i=1;i<=v3;++i,rest/=3)
		if(rest%3)
			return 0;
	for(int i=1;i<=v5;++i,rest/=5)
		if(rest%5)
			return 0;
	for(int i=1;i<=v7;++i,rest/=7)
		if(rest%7)
			return 0;
	return 1;
}
int fun(int len,int rest,int v2,int v3,int v5,int v7)
{
	if(dp[len][rest][v2][v3][v5][v7]!=-1)
		return dp[len][rest][v2][v3][v5][v7];
	if(!len)
		return dp[len][rest][v2][v3][v5][v7]=check(rest,v2,v3,v5,v7);
	int bck=0;
	for(int i=0;i<10;++i)
		bck+=fun(len-1,(rest*10+i)%mod,max(v2,P[i][0]),max(v3,P[i][1]),max(v5,P[i][2]),max(v7,P[i][3]));
	return dp[len][rest][v2][v3][v5][v7]=bck;
}
int calc_num(int len,int rest,int v2,int v3,int v5,int v7)
{
	if(!len)
		return check(rest,v2,v3,v5,v7);
	int bck=0;
	for(int i=0;i<z[len];++i)
		bck+=fun(len-1,(rest*10+i)%mod,max(v2,P[i][0]),max(v3,P[i][1]),max(v5,P[i][2]),max(v7,P[i][3]));
	return bck+calc_num(len-1,(rest*10+z[len])%mod,max(v2,P[z[len]][0]),max(v3,P[z[len]][1]),max(v5,P[z[len]][2]),max(v7,P[z[len]][3]));
}
int calc(int v)
{
	top=0;
	while(v)
	{
		z[++top]=v%10;
		v/=10;
	}
	return calc_num(top,0,0,0,0,0);
}
signed main()
{
	T=read();
	memset(dp,-1,sizeof(dp));
	P[2][0]=1;
	P[3][1]=1;
	P[4][0]=2;
	P[5][2]=1;
	P[6][0]=P[6][1]=1;
	P[7][3]=1;
	P[8][0]=3;
	P[9][1]=2;
	while(T--)
	{
		int l=read(),r=read();
		printf("%lld\n",calc(r)-calc(l-1));
	}
	return 0;
}