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
	ll k,i;string s;
	cin>>s>>k;
	ll ques=0,star=0;
	ll len=s.length();
	for(auto j:s)
	{
		ques+=(j=='?');
		star+=(j=='*');
	}
	len-=ques+star;
	if(k<len-ques-star)
	{
		cout<<"Impossible";return 0;
	}
	if(k>len && star==0)
	{
		cout<<"Impossible";return 0;
	}
	if(star==0)
	{
		ll z=len-k;
		for(i=0;i<s.length();++i)
		{
			if(z==0)break;
			if(z>0 && s[i]=='?')
			{
				--z;s[i-1]='?';
			}
		}
		for(auto j:s)
		{
			if(j!='?')cout<<j;
		}
		return 0;
	}
	len-=ques+star;
	ll z=k-len;bool done=false;
	for(i=0;i<s.length();++i)
	{
		if(i<s.length()-1)
		{
			if(s[i+1]=='?')s[i]='?';
			if(s[i+1]=='*')
			{
				if(!done)
				{
					done=true;s[i+1]='1';
				}
				else {s[i]='?';s[i+1]='?';}
			}
		}
	}
	// /cout<<s<<endl<<z<<endl;
	for(auto j=0;j<s.length();++j)
	{
		if(j<s.length()-1 && s[j+1]=='1')continue; 
		if(s[j]=='1')
		{
			for(i=0;i<z;++i)cout<<s[j-1];
			continue;
		}
		if(s[j]!='?')cout<<s[j];
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