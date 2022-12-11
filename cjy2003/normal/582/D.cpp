#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int p,a,s[4040],la,n;
char A[1010];
int dp[2][4040][2][2],ans;
inline int c2(int x){return 1ll*x*(x-1)/2%mod;}
int main()
{
	scanf("%d %d",&p,&a);
	scanf("%s",A+1);
	la=strlen(A+1);
	for(int i=1;i<=la;++i)A[i]-='0';
	while(1)
	{
		long long res=0;
		bool flag=0;
		for(int i=1;i<=la;++i)
		{
			res=res*10+A[i];flag|=A[i]!=0;
			A[i]=res/p,res%=p;
		}
		if(!flag)break;
		s[++n]=res;
	}
//	for(int i=n;i;--i)printf("%d",s[i]);printf("\n");
	int t=0;
	dp[t][0][1][0]=1;
	for(int i=n;i>=1;--i)
	{
		t=!t;
		memset(dp[t],0,sizeof(dp[t]));
		for(int j=0;j<=n;++j)
		{
			dp[t][j][0][0]=(dp[t][j][0][0]+1ll*dp[!t][j][0][0]*c2(p+1))%mod;
			dp[t][j+1][0][1]=(dp[t][j+1][0][1]+1ll*dp[!t][j][0][0]*c2(p))%mod;
			
			dp[t][j][0][0]=(dp[t][j][0][0]+1ll*dp[!t][j][0][1]*c2(p))%mod;
			dp[t][j+1][0][1]=(dp[t][j+1][0][1]+1ll*dp[!t][j][0][1]*c2(p+1))%mod;
			
			dp[t][j][0][0]=(dp[t][j][0][0]+1ll*dp[!t][j][1][0]*c2(s[i]+1))%mod;
			dp[t][j+1][0][1]=(dp[t][j+1][0][1]+1ll*dp[!t][j][1][0]*c2(s[i]))%mod;
			dp[t][j][1][0]=(dp[t][j][1][0]+1ll*dp[!t][j][1][0]*(s[i]+1))%mod;
			dp[t][j+1][1][1]=(dp[t][j+1][1][1]+1ll*dp[!t][j][1][0]*s[i])%mod;
			
			dp[t][j][0][0]=(dp[t][j][0][0]+1ll*dp[!t][j][1][1]*(c2(p)+mod-c2(p-s[i])))%mod;
			dp[t][j+1][0][1]=(dp[t][j+1][0][1]+1ll*dp[!t][j][1][1]*(c2(p+1)+mod-c2(p-s[i]+1)))%mod;
			dp[t][j][1][0]=(dp[t][j][1][0]+1ll*dp[!t][j][1][1]*(p-s[i]-1))%mod;
			dp[t][j+1][1][1]=(dp[t][j+1][1][1]+1ll*dp[!t][j][1][1]*(p-s[i]))%mod;
		}
	}
	for(int i=a;i<=n;++i)ans=(1ll*ans+dp[t][i][0][0]+dp[t][i][1][0])%mod;
	printf("%d",ans);
	return 0;
}