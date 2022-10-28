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
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 

const long double PI = acos(-1);

//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

char a[1005][1005];
bool mark[1005][1005];
ll dis[1005][1005];
ll n,m;
void bfs()
{
	ll i,j;
	queue<pair<pll,ll>> q;
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			if(mark[i][j])
				q.push({{i,j},0});
	while(!q.empty())
	{
		pair<pll,ll> p=q.front();
		q.pop();
		i=p.F.F,j=p.F.S;
		ll dist=p.S;
		if(i>0 && !mark[i-1][j])
		{
				mark[i-1][j]=true;
				dis[i-1][j]=dist+1;
				q.push({{i-1,j},dis[i-1][j]});
		}
		if(j>0 && !mark[i][j-1])
		{
				mark[i][j-1]=true;
				dis[i][j-1]=dist+1;
				q.push({{i,j-1},dis[i][j-1]});
		}
		if(i<n-1 && !mark[i+1][j])
		{
				mark[i+1][j]=true;
				dis[i+1][j]=dist+1;
				q.push({{i+1,j},dis[i+1][j]});
		}
		if(j<m-1 && !mark[i][j+1])
		{
				mark[i][j+1]=true;
				dis[i][j+1]=dist+1;
				q.push({{i,j+1},dis[i][j+1]});
		}
	}
}
int _runtimeTerror_()
{
	ll t,i,j;
	cin>>n>>m>>t;
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			cin>>a[i][j];
	memf(mark);
	bool mark2[n+1][m+1];
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
		{
			if(i>0 && a[i-1][j]==a[i][j])
				mark[i][j]=true;
			if(j>0 && a[i][j-1]==a[i][j])
				mark[i][j]=true;
			if(i<n-1 && a[i+1][j]==a[i][j])
				mark[i][j]=true;
			if(j<m-1 && a[i][j+1]==a[i][j])
				mark[i][j]=true;
			mark2[i][j]=mark[i][j];
		}
	bfs();
	for(int i=0;i<t;++i)
	{
		ll x,y,p;
		cin>>x>>y>>p;
		--x;--y;
		//cout<<dis[x][y]<<endl;
		if(mark2[x][y])
		{
			p%=2;
			int xx=a[x][y]-'0';
			p+=xx;
			p%=2;
			cout<<p<<endl;continue;
		}
		if(!mark[x][y])
		{
			cout<<a[x][y]<<endl;
			continue;
		}
		if(p<dis[x][y])
			cout<<a[x][y]<<endl;
		else
		{
			p-=dis[x][y];
			p%=2;
			p+=a[x][y]-'0';p%=2;
			cout<<p<<endl;
		}
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
	cerr<<"\n"<<_time_;
	return 0;
}