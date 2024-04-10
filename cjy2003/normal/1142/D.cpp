#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,t,dp[2][11];
long long ans;
char a[100010];
int main()
{
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;++i)
	{
		t^=1;a[i]-='0';
		memset(dp[t],0,sizeof(dp[t]));
		if(a[i])dp[t][a[i]]=1;
		for(int j=a[i]+1;j<=10;++j)
			dp[t][(j*(j-1)/2+9+1+a[i])%11]+=dp[t^1][j];	
		for(int j=0;j<=10;++j)
			ans+=dp[t][j];
	}
	printf("%I64d",ans);
	return 0;
}