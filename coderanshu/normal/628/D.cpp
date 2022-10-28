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
#define sz(a) (int)a.size()
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
const int N=2002;
int dp[N][N][2];
int m,d,n;
int digit(int pos,int prev,int mod,string &s)
{
	if(pos==n)
	{
		if(mod==0)
			return 1;
		return 0;
	}
	if(dp[pos][mod][prev]!=-1)return dp[pos][mod][prev];
	if(pos&1)
	{
		int x=0;
		if(prev==0)
		{
			x+=digit(pos+1,0,(10*mod+d)%m,s);
		}
		else if(prev==1)
		{
			if(d<s[pos]-'0')
				x+=digit(pos+1,0,(10*mod+d)%m,s);
			else if(d==s[pos]-'0')
				x+=digit(pos+1,1,(10*mod+d)%m,s);
		}
		return dp[pos][mod][prev]=x%M;
	}
	else
	{
		int x=0,NU;
		int a=s[pos]-'0';
		if(prev==0)NU=9;
		else NU=a;
		for(int i=0;i<=NU;++i)
		{
			if(i==d)continue;
			int ff=0;
			if(prev==1 && i==NU)ff=1;
			x+=digit(pos+1,ff,(10*mod+i)%m,s);
			x%=M;
		}
		return dp[pos][mod][prev]=x%M;
	}
}
bool check(string s)
{
	for(int i=0;i<sz(s);++i)
	{
		if(i&1 && s[i]-'0'!=d)
			return false;
		else if(i%2==0 && s[i]-'0'==d)
			return false;
	}
	int mod=0;
	for(int i=0;i<sz(s);++i)
	{
		mod=(10*mod+s[i]-'0')%m;
	}
	return (mod==0);
}
int _runtimeTerror_()
{
	string a,b;
	cin>>m>>d>>a>>b;
	mem1(dp);
	n=sz(b);
	int x=digit(0,1,0,b);
	mem1(dp);
	int y=digit(0,1,0,a);
	cout<<(x-y+check(a)+M)%M<<endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}