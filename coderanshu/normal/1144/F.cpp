#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define aint(v) v.begin(),v.end()
#define sz(a) (int)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int power(int b,int e,int m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
int power( int b, int e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

const int N=200005;
vector<int> v[N];
int c[N];
bool vis[N];
bool bfs(int s)
{
	vis[s]=true;
	queue<int> q;q.push(s);

	while(!q.empty())
	{
		int t=q.front();q.pop();
		for(auto j:v[t])
		{
			if(!vis[j])
			{
				c[j]=c[t]^1;
				q.push(j);
				vis[j]=true;
			}
			else
			{
				if(c[j]==c[t])return false;
			}
		}
	}
	return true;
}
int _runtimeTerror_()
{
	int n,m;
	cin>>n>>m;
	int i;
	vector<pair<int,int>> edges;
	for(i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
		edges.pb({x,y});
	}
	c[1]=0;
	if(bfs(1))
	{
		cout<<"YES\n";
		for(auto j:edges)
		{
			if(c[j.F]==0)cout<<1;
			else cout<<0;
		}
	}
	else
		cout<<"NO\n";
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