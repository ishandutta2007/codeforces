#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define mk make_pair
const int N=100005;
const ll inf=(ll)5e18;

ll mx[N],n,q;
ll c[N],v[N],dp[N];
pii rest_mx[2];//value color

int main()
{
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&v[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	while(q--)
	{
		ll a,b;
		for(int i=0;i<=n;i++)
		{
			dp[i]=0;
			mx[i]=-inf; 
		}
		rest_mx[0].first=rest_mx[1].first=0;
		rest_mx[0].second=rest_mx[1].second=-1;
		scanf("%lld%lld",&a,&b);
		for(int i=1;i<=n;i++)
		{
			ll color=mx[c[i]],rest_color;
			if(c[i]==rest_mx[0].second) rest_color=rest_mx[1].first;
			else rest_color=rest_mx[0].first;
			dp[i]=max(color+v[i]*a,rest_color+v[i]*b);
			mx[c[i]]=max(mx[c[i]],dp[i]);
			if(rest_mx[0].first<dp[i]) 
			{
				if(rest_mx[0].second!=c[i])
					rest_mx[1]=rest_mx[0],rest_mx[0]=mk(dp[i],c[i]);
				else rest_mx[0]=mk(dp[i],c[i]);
			}
			else if(rest_mx[1].first<dp[i]&&rest_mx[0].second!=c[i]) 
				rest_mx[1]=mk(dp[i],c[i]);
		}
		ll ans=0;
		for(int i=1;i<=n;i++) 
		{
			//cout<<dp[i]<<" ";
			ans=max(ans,dp[i]);
		} //cout<<endl;
		printf("%lld\n",ans);
	}
	return 0;
}