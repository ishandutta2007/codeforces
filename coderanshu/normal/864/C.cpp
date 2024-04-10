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
	ll a,b,f,k,i;
	cin>>a>>b>>f>>k;
	if(b<f)
	{
		cout<<-1;return 0;
	}
	if(k==1)
	{
		if(b<f)
		{
			cout<<-1;return 0;
		}
		if(b>=a)
		{
			cout<<0;return 0;
		}
		if(b<a-f)
		{
			cout<<-1;return 0;
		}
		cout<<1<<endl;return 0;
	}
	ll cur=b,ans=0;
	for(i=1;i<=k;++i)
	{
		if(cur<0)
		{
			cout<<-1;return 0;
		}
		if(i&1)
		{
			cur-=f;
			if(cur<0)
			{
				cout<<-1;return 0;
			}
			if(i<k)
			{
				if(cur<2*(a-f)){cur=b;++ans;}
				cur-=a-f;
			}
			else
			{
				if(cur<a-f){cur=b;++ans;}
			}
		}
		else
		{
			cur-=a-f;
			if(cur<0){cout<<-1;return 0;}
			if(i==k)
			{
				if(cur<f){cur=b;++ans;}
			}
			else
			{
				if(2*f>cur)
				{
					cur=b;++ans;
				}
				cur-=f;
			}
		}
	}
	cout<<ans;
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