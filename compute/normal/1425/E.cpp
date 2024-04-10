#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vi a(n),d(n);
	ll ans=0;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>d[i];
	vector<ll> suf(n);
	vector<ll> smax(n);
	suf[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--) suf[i]=suf[i+1]+a[i];
	smax[n-1]=max(0,a[n-1]-d[n-1]);
	for(int i=n-2;i>=0;i--) smax[i]=max(smax[i+1],suf[i]-d[i]);
	if(k==0)
	{
		cout<<smax[0]<<'\n';
		return 0;
	}
	else if(k==1)
	{
		int mi=1e9;
		ll pre=0;
		ans=max(ans,smax[1]+(a[0]>d[0]?a[0]-d[0]:0));
		mi=d[0],pre=a[0];
		for(int i=1;i<n-1;i++)
		{
			mi=min(mi,d[i]);
			pre+=a[i];
			ans=max(ans,max(0LL,pre-mi)+smax[i+1]);
		}
		ll dp0=a[n-1],dp1=-1e9;
		for(int i=n-2;i>0;i--)
		{
			ll n1=max(dp1+a[i],dp0+(a[i]>d[i]?a[i]-d[i]:0)),n0=dp0+a[i];
			dp1=n1;
			dp0=n0;
		}
		ans=max(ans,dp1+a[0]-d[0]);
	}
	else{
		int mi=1e9;
		for(int i=0;i<n-1;i++) mi=min(mi,d[i]);
		ll sum=suf[0];
		ans=max(ans,sum-mi);
	}
	ans=max(ans,1LL*a[n-1]-d[n-1]);
	cout<<ans<<'\n';
}