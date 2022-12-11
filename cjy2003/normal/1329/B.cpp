#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,d,mod,dp[50];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&d,&mod);
		int p;
		for(int i=30;i;--i)if(d>>(i-1)&1){p=i;break;}
		int sum=1%mod;
		for(int i=1;i<=p;++i)
		{
			dp[i]=1ll*sum*(i==p?d-(1<<p-1)+1:1<<i-1)%mod;
	//		printf("%d\n",dp[i]);
			(sum+=dp[i])>=mod?sum-=mod:0;
		}
		(sum+=mod-1)>=mod?sum-=mod:0;
		printf("%d\n",sum);
	}
	return 0;
}