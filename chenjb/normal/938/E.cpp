#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=1E9+7;
int fac[1000010],n,a[1000010],ans;
int mypow(int x,int n){int ans=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)ans=1ll*ans*x%MOD;return ans;}
int cal(int x)
{
	return 1ll*fac[n]*mypow(x+1,MOD-2)%MOD;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<=1000000;i++)
	{
		fac[i]=1ll*fac[i-1]*i%MOD;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;)
	{
		if(a[i]==a[n])
		{
			break;
		}
		int j=i;
		for(;j<=n&&a[j]==a[i];)
		{
			j++;
		}
		ans=(ans+1ll*cal(n-i)*a[i]%MOD*(j-i))%MOD;
		i=j;
	}
	printf("%d\n",ans);
	return 0;
}