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
#define level 20
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
	ll i=0,n=s.length();
	for(i=0;i<n;++i)
	{
		if(s[i]=='n')continue;
		if(s[i]!='a' && s[i]!='u' && s[i]!='o' && s[i]!='i' && s[i]!='e')
		{
			if(i==s.length()-1)
			{
				cout<<"NO";return 0;
			}
			if(s[i+1]!='a' && s[i+1]!='u' && s[i+1]!='o' && s[i+1]!='i' && s[i+1]!='e')
			{
				cout<<"NO";return 0;
			}
			++i;
		}
	}
	cout<<"YES";
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int tests=1;
	//cin>>tests;
	while(tests--)
		_runtimeTerror_();
	return 0;
}