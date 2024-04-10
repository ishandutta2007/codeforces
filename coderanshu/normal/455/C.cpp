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
const int N=300002;
vector<int> v[N];
bool vis[N];
int p[N],r[N],ans[N],dep[N],init;
vector<int> check;
void in(int n)
{
	for(int i=1;i<=n;++i)
	{
		r[i]=0;p[i]=i;ans[i]=0;
	}
}
int parent(int i)
{
	if(i==p[i])return i;
	return p[i]=parent(p[i]);
}
void merge(int x,int y)
{
	x=parent(x);y=parent(y);
	if(x==y)return ;
	int zz=max({ans[x],ans[y],(ans[x]+1)/2+(ans[y]+1)/2+1});
	if(r[x]>r[y])
	{
		p[y]=x;
		ans[x]=zz;
	}
	else
	{
		p[x]=y;ans[y]=zz;
	}
	if(r[x]==r[y])
		++r[y];
}
void dfs(int s,int &md,int &val,int para)
{
	vis[s]=true;
	for(auto j:v[s])
	{
		if(!vis[j])
		{
			check.pb(j);
			dep[j]=dep[s]+1;
			p[j]=init;
			if(dep[j]>md)
			{
				md=dep[j];
				val=j;
			}
			dfs(j,md,val,para);
			dep[j]=0;
		}
	}
	if(para==1)
		vis[s]=false;
}
int findDiameter(int s)
{
	dep[s]=0;
	int ans1=0;
	int md=0,val=s,para;
	dfs(s,md,val,para=1);
	dep[val]=0;
	md=0;
	dfs(val,md,s,para=0);
	return md;
}
int _runtimeTerror_()
{
	int n,m,q;
	cin>>n>>m>>q;
	in(n);
	while(m--)
	{
		int xx,yy;
		cin>>xx>>yy;
		v[xx].pb(yy);v[yy].pb(xx);
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			check.clear();
			init=i;
			ans[i]=findDiameter(i);
		}
	}
	while(q--)
	{
		int tt,xx,yy;
		cin>>tt>>xx;
		if(tt==1)
		{
			cout<<ans[parent(xx)]<<endl;
		}
		else
		{
			cin>>yy;
			merge(xx,yy);
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
	return 0;
}