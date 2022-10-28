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
#define INF 2e8
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
vector<int> v[100005];
bool vis[100005];
int dep[100005],val[100005];
vector<pair<int,int>> ans;
void dfs(int s,int p)
{
	vis[s]=true;
	val[s]=INF;
	for(auto j:v[s])
	{
		if(!vis[j])
		{
			dep[j]=dep[s]+1;
			dfs(j,s);
			val[s]=min(val[j],val[s]);
		}
		else if(vis[j] && j!=p)
		{
			if(dep[j]<dep[s])
			{
				val[s]=min(val[s],dep[j]);
				ans.pb({s,j});
			}
			else val[s]=min(val[s],dep[s]);
		}
	}
	if(val[s]>=dep[s] && dep[s])
	{
		cout<<"0\n";
		exit(0);
	}
	if(dep[s])
		ans.pb({p,s});
}
int _runtimeTerror_()
{
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	dfs(1,-1);	
	for(auto j:ans)
	{
		cout<<j.F<<" "<<j.S<<endl;
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