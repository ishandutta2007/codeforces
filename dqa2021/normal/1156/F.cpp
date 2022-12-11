//try to solve after the contest

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int inv[5010];

int n,m;  //m and n
int w[5010],tot[5010]/*,suf[5010]*/;
int dp[5010][5010];
int bin[5010];
int ans;
int main()
{
	scanf("%d",&n); m=n;
	inv[1]=1; for (int i=2;i<=n;i++) inv[i]=(ll)(Mod-Mod/i)*inv[Mod%i]%Mod;
	for (int i=1;i<=n;i++) scanf("%d",w+i); sort(w+1,w+n+1);
	int tmp=0;
	for (int i=1;i<=n;i++)
		if (i==1||w[i]!=w[i-1]) w[++tmp]=w[i],tot[tmp]=1;
		else tot[tmp]++;
	n=tmp;
//	for (int i=n;i;i--) suf[i]=suf[i+1]+tot[i];
	for (int i=1;i<=n;i++) dp[i][1]=(ll)tot[i]*inv[m]%Mod;
	for (int j=1;j<m;j++)
	{
		memset(bin,0,sizeof bin);
		for (int i=1;i<=n;i++)
		{
			ans=(ans+(ll)dp[i][j]*(tot[i]-1)%Mod*inv[m-j])%Mod;
			if (i!=n) bin[i+1]=(bin[i+1]+(ll)dp[i][j]*inv[m-j])%Mod;
		}
		for (int i=1;i<=n;i++) bin[i]=(bin[i]+bin[i-1])%Mod,dp[i][j+1]=(ll)tot[i]*bin[i]%Mod;
	}
	printf("%d\n",ans);
	return 0;
}