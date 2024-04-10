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
#define llevel 20
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

int _runtimeTerror_()
{	
	ll n,m;char c;
	cin>>n>>m>>c;
	char a[n+2][m+2];
	ll i,j;set<char>s;
	for(i=0;i<n;++i)for(j=0;j<m;++j)cin>>a[i][j];
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if(a[i][j]==c)
			{
				if(i>0)s.insert(a[i-1][j]);
				if(j>0)s.insert(a[i][j-1]);
				if(i<n-1)s.insert(a[i+1][j]);
				if(j<m-1)s.insert(a[i][j+1]);
			}
		}
	}
	if(s.count('.'))s.erase('.');
	if(s.count(c))s.erase(c);
	cout<<s.size();
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}