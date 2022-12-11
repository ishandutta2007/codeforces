#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (flg) x=-x;
	return x;
}
typedef long long ll;
const int Mod=1e9+7;

int n,m;
int dp[100010][2];
int ans;
int main()
{
	scanf("%d%d",&n,&m);
	dp[1][0]=2;
	for (int i=2;i<=n||i<=m;i++)
	{
		dp[i][1]=dp[i-1][0];
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%Mod;
	}
	//printf("%d %d %d %d\n",dp[n][0],dp[n][1],dp[m][0],dp[m][1]);
	ans=(0LL+dp[n][0]+dp[n][1]+dp[m][0]+dp[m][1]-2)%Mod;
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}