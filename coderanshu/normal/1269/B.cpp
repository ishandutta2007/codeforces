#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define pi 3.1415926536

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
bool function(ll a[],ll b[],ll n, ll m,ll d)
{

}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n,m,i,k,ninv;
	cin>>n>>m;
	ll a[n],b[n];
	rep(i,0,n)
	{
		cin>>a[i];
	}
	rep(i,0,n)
	{
		cin>>b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	ll ans=m,temp;
	bool xy;
	for( ll k=0;k<n;k++)
	{
		xy=true;
		temp=(b[0]-a[k]+m)%m;
		for(i=k;i<n;i++)
		{
			if((b[i-k]-a[i]+m)%m!=temp)
			{
				xy=false;
				break;
			}
		}
		for(i=0;i<k;i++)
		{
			if((b[n-k+i]-a[i]+m)%m!=temp)
			{
				xy=false;
				break;
			}
		}
		if(xy)
			ans=min(ans,temp);

	}
	cout<<ans;
	return 0;
}