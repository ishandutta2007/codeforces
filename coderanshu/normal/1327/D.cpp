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
#define sz(a) (ll)a.size()
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
vector<int> v[200005];
void divisor(int n=200000)
{
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;j+=i)
			v[j].pb(i);
	}
}
int _runtimeTerror_()
{
	int n,i;
	cin>>n;
	int p[n+1],c[n+1];
	bool vis[n+1];
	memf(vis);
	for(i=1;i<=n;++i)
	{
		cin>>p[i];
	}
	int ans=n;
	for(int i=1;i<=n;++i)
		cin>>c[i];
	for(i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			vector<int> check;
			int pos=i;
			while(!vis[i])
			{
				vis[i]=true;
				check.pb(i);
				i=p[i];
			}
			int len=sz(check);
			for(auto j:v[len])
			{
				bool thisdiv=false;
				for(i=0;i<j;++i)
				{
					bool thisstr=true;
					int color=c[check[i]];
					for(int k=i;k<len;k+=j)
					{
						if(c[check[k]]!=color)
						{
							thisstr=false;
							break;
						}
					}
					if(thisstr)
					{
						thisdiv=true;
						ans=min(ans,j);
						break;
					}
				}
				if(thisdiv)
					break;
			}
		}
	}
	cout<<ans<<endl;
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
	divisor();
	int TESTS=1;
	cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}