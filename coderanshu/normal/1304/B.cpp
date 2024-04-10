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
bool isPal(string s)
{
	ll sz=s.length();
	for(ll i=0;i<sz/2;++i)
	{
		if(s[i]!=s[sz-1-i])
			return false;
	}
	return true;
}
int runtimeTerror()
{
	ll n,m,i,ans=0;
	cin>>n>>m;
	string str,ansStr,t;
	set<string> s;
	for(i=0;i<n;++i)
	{
		cin>>str;
		s.insert(str);
	}
	for(auto i=s.begin();i!=s.end();++i)
	{
		str=*i;
		if(isPal(str))
			{
				t=str;
				continue;
			}
		reverse(all(str));
		if(s.count(str))
		{
			s.erase(str);
			ans+=2*m;
			ansStr+=str;
		}
	}
	cout<<ans+t.length()<<endl;
	cout<<ansStr<<t;reverse(all(ansStr));
	cout<<ansStr;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int tests=1;
	//cin>>tests;
	while(tests--)
		runtimeTerror();
	return 0;
}