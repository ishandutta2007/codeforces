#include <bits/stdc++.h>
using namespace std;
const int N=605;
typedef long long ll;
const ll MOD=1000000007;

ll dp[N][N],g[N][N],C[N][N];
ll n,a[N],cnt[N],top=0;

bool check(ll x,ll y)
{
	ll tmp=x*y;
	return tmp==(ll)sqrt(tmp)*(ll)sqrt(tmp);
}

int main() 
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
			if(check(a[i],a[j])) a[j]=a[i];
	}
	sort(a+1,a+n+1); a[0]=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1]) cnt[++top]=1;
		else ++cnt[top];
	}
	//for(int i=1;i<=top;i++) cout<<cnt[i]<<endl;
	g[0][0]=1; dp[0][0]=1;
	for(int i=0;i<=600;i++)
		for(int j=0;j<=i;j++) C[i][j]=((j==0) ? 1 : C[i-1][j]+C[i-1][j-1])%MOD;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++) g[i][j]=((i+j-1)*g[i-1][j]%MOD+j*(g[i-1][j-1]))%MOD;
	//cout<<g[3][2]<<endl;
	ll sum=0;
	for(int i=0;i<top;i++)
	{
		sum+=cnt[i];
		for(int j=0;j<=sum;j++)
		{
			for(int k=1;k<=cnt[i+1];k++)
			{
				for(int l=0;l<=min(j,k);l++)
				{
					//cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<g[cnt[i+1]][k]<<" "<<C[j][l]<<" "<<C[sum+1-j][k-l]<<endl;
					if(j+cnt[i+1]-k-l<0) continue;
					dp[i+1][j+cnt[i+1]-k-l]=(dp[i+1][j+cnt[i+1]-k-l]+dp[i][j]*g[cnt[i+1]][k]%MOD*C[j][l]%MOD*C[sum+1-j][k-l])%MOD;
					//cout<<dp[i+1][j+cnt[i+1]-k-l]<<endl;
				}
			}
		}
	}
	cout<<dp[top][0]<<endl;
	return 0;
}
/*g[t][k]:tkt!*C(t-1,k-1);*(i+j-1)j,
iS(n,m)=S(n-1,m-1)+S(n-1,m)*m
 */