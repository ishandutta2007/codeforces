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
	
	ll n,i;
	cin>>n;
	vector<ll> v(n);
	map<ll,ll> m;
	for(i=0;i<n;i++)
	{
		cin>>v[i];
		m[v[i]]++;
	}
	ll checkans=-1,checkvalue=0;
	for(auto j:m)
	{
		if(j.S>checkans)
		{
			checkvalue=j.F;
			checkans=j.S;
		}
	}
	cout<<n-checkans<<endl;
	for(i=0;i<n;i++)
	{
		if(v[i]==checkvalue)
			break;
	}
	for(auto j=i;j<n;j++)
	{
		if(v[j]!=checkvalue)
		{
			if(v[j]>checkvalue)
				cout<<2<<" "<<j+1<<" "<<j<<endl;
			else cout<<1<<" "<<j+1<<" "<<j<<endl;
		}
	}
	for(auto j=i-1;j>=0;--j)
	{
		if(v[j]>checkvalue)
			cout<<2<<" "<<j+1<<" "<<j+2<<endl;
		else cout<<1<<" "<<j+1<<" "<<j+2<<endl;
	}
	return 0;

}