#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

ll ans=0,dp[505][505],a[505][3],n,k,sum1=0,sum2=0;
vector<ll> v[505];

int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i][1],&a[i][2]);
	for(int i=1;i<=n;i++)
	{
		sum1+=a[i][1];
		sum2+=a[i][2];
		ll x=a[i][1]%k;
		ll y=a[i][2]%k;
		v[i].push_back(x);
		if(a[i][1]+a[i][2]<k)
		{
			continue;
		}
		for(int j=0;j<=min(a[i][2],k-1);j++)
		{
			if(a[i][1]<k-j) continue;
			int tmp=(a[i][1]-(k-j))%k;
			v[i].push_back(tmp);
		}
		//for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<" "; puts("");
	}
	ans=(sum1+sum2)/k; ll r=sum1%k+sum2%k;
	if(r<k)
	{
		cout<<ans<<endl;
		return 0;
	}
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			for(int t=0;t<=k;t++)
			{
				dp[i][t]|=dp[i-1][(t+k-v[i][j])%k];
			}
		}
	}
	//for(int i=0;i<=k;i++) cout<<dp[n][i]<<endl;
	int bl=1;
	
	for(int i=0;i<=r-k;i++) if(dp[n][i]) bl=0; 
	cout<<ans-bl<<endl;
	return 0;
}