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
const int N=200005;
vector<ll> v[N];
bool vis[N];
ll dep[N],p[N],in[N],out[N],curr=0;
void dfs(ll s)
{
	vis[s]=true;
	in[s]=curr;
	++curr;
	for(auto j:v[s])
	{
		if(!vis[j])
		{
			p[j]=s;
			dep[j]=dep[s]+1;
			dfs(j);
		}
	}
	out[s]=curr-1;
}
int _runtimeTerror_()
{
	ll n,m,i;
	cin>>n>>m;
	for(i=0;i<n-1;++i)
	{
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	dfs(1);
	p[1]=1;
	while(m--)
	{
		int k;
		cin>>k;
		bool done=true;
		vector<ll> v(k);
		for(int i=0;i<k;++i)
		{
			cin>>v[i];
			v[i]=p[v[i]];
		}
		sort(all(v),[&](ll a,ll b){return dep[a]<dep[b];});
		for(i=0;i<k-1;++i)
		{
			if(in[v[i+1]]>=in[v[i]] && in[v[i+1]]<=out[v[i]])continue;
			else
			{
				done=false;break;
			}
		}
		puts(done?"YES":"NO");
	}
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