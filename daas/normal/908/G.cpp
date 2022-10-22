#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
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
int dp[710][2][10][710],len,sum[710],ans;
char s[710];
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	sum[0]=1;
	for(int i=1;i<=len;++i) sum[i]=(ll)sum[i-1]*10%mod;
	for(int i=1;i<=len;++i) sum[i]=MOD(sum[i]+sum[i-1]-mod);
	for(int i=1;i<=9;++i) dp[0][0][i][0]=1;
	for(int i=1;i<=len;++i)
	{
		int c=s[i]-'0';
		//0->0
		for(int j=1;j<=9;++j)
			for(int k=0;k<i;++k)
			{
				int f=(c>=j);
				dp[i][0][j][k+f]=MOD(dp[i][0][j][k+f]+dp[i-1][0][j][k]-mod);
			}
		//0->1
		for(int j=0;j<c;++j)
			for(int k=1;k<=9;++k)
				for(int w=0;w<i;++w)
				{
					int f=(j>=k);
					dp[i][1][k][w+f]=MOD(dp[i][1][k][w+f]+dp[i-1][0][k][w]-mod);
				}
		//1->1
		for(int j=0;j<=9;++j)
			for(int k=1;k<=9;++k)
				for(int w=0;w<i;++w)
				{
					int f=(j>=k);
					dp[i][1][k][w+f]=MOD(dp[i][1][k][w+f]+dp[i-1][1][k][w]-mod);
				}
	}
	for(int i=1;i<=9;++i)
	{
		for(int j=1;j<=len;++j)
		{
			ans=MOD(ans+(ll)dp[len][0][i][j]*sum[j-1]%mod-mod);
			ans=MOD(ans+(ll)dp[len][1][i][j]*sum[j-1]%mod-mod);
		}
	}
	printf("%d\n",ans);
	return 0;
}
//ore no turn,draw!