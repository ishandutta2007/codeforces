#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
ll a[100005],n,t;

bool check(ll in)
{
	ll sum=0;
	for(auto i=0;i<in;i++)
	{
		sum+=a[i];
	}
	if(sum<=t)return true;
	for(auto i=in;i<n;i++)
	{
		sum+=a[i]-a[i-in];
		if(sum<=t)
			return true;
	}
	return false;
}
ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e==1)
		return b;
	if(e%2==0)
		return power(b*b%m,e/2,m);
	else
		return b*power(b*b%m,(e-1)/2,m)%m;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i,be,en,mid;
	cin>>n>>t;
	for(i=0;i<n;i++)
		cin>>a[i];
	be=1;en=n;
	while(be<=en)
	{
		ll mid=(be+en)/2;
		if(check(mid))
			be=mid+1;
		else
			en=mid-1;
	}
	cout<<be-1;
	return 0;
}