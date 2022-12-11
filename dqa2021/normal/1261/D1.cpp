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
const int Mod=998244353;

int n,k,w[200010];
int dp[2010][4010];
void add(int &x,ll y)
{
	x=(x+y)%Mod;
}
int main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++) w[i]=read();
	dp[0][0]=1;
	int sum=0;
	for (int i=0;i<n;i++)
	{
		if (w[i+1]==w[(i+1)%n+1])
		{
			for (int j=0;j<=sum;j++)
			{
				add(dp[i+1][j+1],1LL*k*dp[i][j]);
			}
			sum++;
			continue;
		}
		for (int j=0;j<=sum;j++)
		{
			add(dp[i+1][j],dp[i][j]);
			add(dp[i+1][j+1],1LL*(k-2)*dp[i][j]);
			add(dp[i+1][j+2],dp[i][j]);
		}
		sum+=2;
	}
	int ans=0;
	for (int i=n+1;i<=sum;i++) ans=(ans+dp[n][i])%Mod;
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}