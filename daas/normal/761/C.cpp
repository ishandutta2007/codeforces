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
int n,m,step[51][3],dp[51][8];
char s[51];
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		step[i][0]=step[i][1]=step[i][2]=0x3f3f3f3f;
		scanf("%s",s);
		for(int j=1;j<=m;++j)
		{
			if('0'<=s[j-1] && s[j-1]<='9')
				step[i][0]=min(step[i][0],min(j-1,m-j+1));
			if('a'<=s[j-1] && s[j-1]<='z')
				step[i][1]=min(step[i][1],min(j-1,m-j+1));
			if(s[j-1]=='#' || s[j-1]=='*' || s[j-1]=='&')
				step[i][2]=min(step[i][2],min(j-1,m-j+1));
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1][1]=step[1][0];
	dp[1][2]=step[1][1];
	dp[1][4]=step[1][2];
	for(int i=2;i<=n;++i)
		for(int j=1;j<=7;++j)
			for(int k=0;k<3;++k)
				dp[i][j|(1<<k)]=min(dp[i][j|(1<<k)],dp[i-1][j]+step[i][k]);
	printf("%d\n",dp[n][7]);
	return 0;
}
/*
000 0
001 1
010 2
100 4
011 3
101 5
110 6
111 7*/