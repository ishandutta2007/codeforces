#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
const int MAXN=4e4+10;
const int mod=1e9+7;
inline int MOD(int x) {return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,num[MAXN],cnt,dp[MAXN][500],ans[MAXN];
int main()
{
	for(int i=1;i<=40000;++i)
	{
		int tmp=i,val=0;
		while(tmp) val=val*10+tmp%10,tmp/=10;
		if(val==i) num[++cnt]=i;
	}
	dp[0][0]=1;
	for(int i=0;i<=40000;++i)
	{
		for(int j=1;j<=cnt;++j) dp[i][j]=MOD(dp[i][j]+dp[i][j-1]-mod);
		for(int j=1;j<=cnt && num[j]<=i+1;++j) dp[i+1][j]=MOD(dp[i+1][j]+dp[i+1-num[j]][j]-mod);
	}
	T=read();
	while(T--)
	{
		n=read();
		printf("%d\n",dp[n][cnt]);
	}
	return 0;
}
//ore no turn,draw!