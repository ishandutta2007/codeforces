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
bool notPrime[1000005];
ll divPrime[1000005];
void sieve(int n=1000000)
{
	int k=sqrt(n);
	memf(notPrime);
	notPrime[1]=true;
	for(int i=2;i<=k;++i)
	{
		if(!notPrime[i])
		{
			for(int k=i*i;k<=n;k+=i)
			{
				notPrime[k]=true;
				divPrime[k]=i;
			}
		}
	}
}
vector<ll> g[1000000],primes;
ll ans;
ll level[1000005];
bool vis[1000005];
void bfs(ll s)
{
	if(g[s].empty())return ;
	for(auto i:primes)
	{
		level[i]=0;vis[i]=false;
	}
	queue<pair<ll,ll>> q;q.push({s,-1});vis[s]=true;
	while(!q.empty())
	{
		pair<ll,ll> t={q.front().F,q.front().S};q.pop();
		for(auto j:g[t.F])
		{
			if(!vis[j])
			{
				q.push({j,t.F});vis[j]=true;level[j]=level[t.F]+1;
			}
			else if(vis[j] && j!=t.S)
			{
				ans=min(ans,level[j]+level[t.F]+1);return ;
			}
		}
	}
}
int _runtimeTerror_()
{
	sieve();
	primes.pb(1);
	for(int i=2;i<=1e6;++i)
	{
		if(!notPrime[i])
			primes.pb(i);
	}
	ll n;
	cin>>n;
	ll i,a[n];
	for(i=0;i<n;++i)
	{
		cin>>a[i];
		ll k=a[i];vector<ll> v;
		while(k!=1 && notPrime[k])
		{
			ll z=divPrime[k],count=0;
			while(k%z==0){k/=z;++count;}
			if(count&1)v.pb(z);
		}
		if(k>1)v.pb(k);
		if(v.empty())
		{
			cout<<1<<endl;return 0;
		}
		if(v.size()==1){g[1].pb(v[0]);g[v[0]].pb(1);}
		else 
		{
			g[v[0]].pb(v[1]);g[v[1]].pb(v[0]);
		}
	}
	ans=1e9;
	for(i=1;i<=1002;++i)
	{
		bfs(i);
	}
	if(ans==1e9)cout<<-1;
	else	
	cout<<ans<<endl;
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