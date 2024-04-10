#include<cstdio>
using namespace std;
const int MOD=1E9+7;
int C[5010][5010],n,k,ans,tmp;
int mypow(int x,int n){int ans=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)ans=1ll*ans*x%MOD;return ans;}
int main()
{
	scanf("%d%d",&n,&k);
	C[0][0]=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=i;j++)
		{
			C[i][j]=(C[i-1][j-1]+1ll*j*C[i-1][j])%MOD;
		}
	}
	tmp=1;
	for(int i=1;i<=k;i++)
	{
		if(i>n)
		{
			break;
		}
		tmp=1ll*tmp*(n-i+1)%MOD;
		ans=(ans+1ll*mypow(2,n-i)*tmp%MOD*C[k][i]%MOD)%MOD;
	}
	printf("%d\n",ans);
	return 0;
}