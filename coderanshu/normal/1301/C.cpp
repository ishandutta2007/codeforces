#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll tests;
	cin>>tests;
	while(tests--)
	{
		ll n,m;
		cin>>n>>m;
		if(m==0)
		{
			cout<<"0\n";continue;
		}
		if(m==n)
		{
			cout<<(n*(n+1))/2<<endl;continue;
		}
		ll x=(n*(n+1))/2;
		ll z=n-m;
		if(m>=z-1)
		{
			cout<<x-z<<endl;continue;
		}
		ll mm=z/(m+1);
		ll km=z%(m+1);
		if(z%(m+1)==0)
		{
			cout<<x-(m+1)*(mm)*(mm+1)/2<<endl;continue;
		}
		cout<<x-km*(mm+1)*(mm+2)/2-(m+1-km)*(mm+1)*mm/2<<endl;
	}
	return 0;
}