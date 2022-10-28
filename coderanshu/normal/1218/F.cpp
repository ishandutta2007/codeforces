#pragma GCC optimize("Ofast")

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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,i,k,A;
	cin>>n>>k;
	ll a[n],c[n],ma=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>A;
	multiset<ll> s;
	for(i=0;i<n;i++)
			cin>>c[i];
	ll anscost=0;
	for(i=0;i<n;i++)
	{
		s.insert(c[i]);
		if(k>=a[i])
			continue;
		if(s.size()*A+k<a[i])
		{
			cout<<-1;return 0;
		}
		while(k<a[i])
		{
			anscost+=*s.begin();
			s.erase(s.begin());
			k+=A;
		}
	}
	cout<<anscost;
	return 0;

}