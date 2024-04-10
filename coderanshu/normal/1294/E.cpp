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
 
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,(e-1)/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,(e-1)/2);
	return power(b*b,e/2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m,i,j;
	cin>>n>>m;
	ll a[n][m];
	ll ans=0,check;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cin>>a[i][j];
	}
	map<ll,ll> mapp;
	for(j=0;j<m;j++)
	{
		mapp.clear();
		for(i=0;i<n;i++)
		{
			if(a[i][j]>=j+1 && a[i][j]%m==(j+1)%m && a[i][j]<=n*m)
			{
			a[i][j]=(a[i][j]-j-1)/m+1;
				if(i+1>=a[i][j])
					mapp[i+2-a[i][j]]++;
				else
					mapp[n-a[i][j]+i+2]++;
			}
		}
		check=2e6;
		for(auto k=1;k<=n;k++)
			check=min(check,k-1+n-mapp[k]);
		ans+=check;
 
	}
	cout<<ans;
	return 0;
}