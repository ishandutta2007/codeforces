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
ll n;
char mark[500];
bool check(string s,vector<string> v)
{
	string t="";int i;
	for(i=0;i<2*n-2;++i)mark[i]='.';
	for(i=0;i<n-1;++i)
	{
		t+=s[i];
		bool found=false;
		for(auto j=0;j<2*n-2;++j)
		{
			if(v[j]==t && mark[j]=='.')
			{
				found=true;
				mark[j]='P';
				break;
			}
		}
		if(!found)return false;
	}
	t+=s[i];
	for(i=0;i<n-1;++i)
	{
		t.erase(t.begin());
		bool found=false;
		for(auto j=0;j<2*n-2;++j)
		{
			if(v[j]==t && mark[j]=='.')
			{
				mark[j]='S';
				found=true;
				break;
			}
		}
		if(!found)return false;
	}
	return true;
}
int _runtimeTerror_()
{
	ll i;
	cin>>n;	
	vector<string> v(2*n-2),temp;
	for(int i=0;i<2*n-2;++i)cin>>v[i];
	temp=v;
	sort(all(v),[&](string a,string b){return a.length()<b.length();});
	string x=v[0]+v[2*n-3];
	if(check(x,temp))
	{
		for(i=0;i<2*n-2;++i)cout<<mark[i];return 0;
	}
	x=v[0]+v[2*n-4];
	if(check(x,temp))
	{
		for(i=0;i<2*n-2;++i)cout<<mark[i];return 0;
	}
	x=v[1]+v[2*n-4];
	if(check(x,temp))
	{
		for(i=0;i<2*n-2;++i)cout<<mark[i];return 0;
	}
	x=v[1]+v[2*n-3];
	if(check(x,temp))
	{
		for(i=0;i<2*n-2;++i)cout<<mark[i];return 0;
	}
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