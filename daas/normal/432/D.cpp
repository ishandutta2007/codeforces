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
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,Next[100001],dp[100001],ans[100001][2],cnt;
char s[100001];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1,bj=0;i<n;++i)
	{
		while(bj && s[i+1]!=s[bj+1]) bj=Next[bj];
		if(s[i+1]==s[bj+1]) ++bj;
		Next[i+1]=bj;
	}
	for(int i=n;i>=1;--i) dp[i]+=1,dp[Next[i]]+=dp[i];
	for(int i=n;i!=0;i=Next[i]) ans[++cnt][0]=i,ans[cnt][1]=dp[i];
	printf("%d\n",cnt);
	for(int i=cnt;i>=1;--i) printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}