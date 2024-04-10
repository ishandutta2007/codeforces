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
	string s;
	cin>>s;
	int n=s.length();
	if(n<3){cout<<"No";return 0;}
	for(int i=1;i<n-1;++i)
	{
		bool a[3];
		memf(a);
		if(s[i]=='A' || s[i-1]=='A' || s[i+1]=='A')a[0]=1;
		if(s[i]=='B' || s[i-1]=='B' || s[i+1]=='B')a[1]=1;
		if(s[i]=='C' || s[i-1]=='C' || s[i+1]=='C')a[2]=1;
		if(a[0]&&a[1]&&a[2])
		{
			cout<<"Yes";return 0;
		}
	}
	cout<<"No";
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