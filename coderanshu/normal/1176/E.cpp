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
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
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
	ll n,m;
	cin>>n>>m;
	vector<ll> v[n+2];
	while(m--)
	{
		ll xx,yy;
		cin>>xx>>yy;
		v[xx].pb(yy);v[yy].pb(xx);
	}
	queue<pair<ll,bool>> q;
	vector<ll> ans;
	bool vis[n+1]={0};
	vis[1]=1;
	q.push({1,true});
	while(!q.empty())
	{
		pair<ll,bool> t=q.front();
		q.pop();
		if(t.S)ans.pb(t.F);
		for(auto j:v[t.F])
		{
			if(!vis[j])
			{
				vis[j]=true;
				q.push({j,(t.S^1)});
			}
		}
	}
	if(sz(ans)>n/2)
	{
		bool vis2[n+1]={0};
		for(auto j:ans)vis2[j]=1;
		ans.clear();
		for(ll i=1;i<=n;++i)
			if(!vis2[i])ans.pb(i);
	}
	cout<<sz(ans)<<endl;
	for(auto j:ans)
		cout<<j<<" ";
	cout<<endl;
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
	cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<_time_;
	return 0;
}