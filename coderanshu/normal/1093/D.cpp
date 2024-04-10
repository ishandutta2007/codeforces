#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define PI 3.1415926536
#define INF 

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
bool vis[300005];
ll n,s1,s2;
vector<ll> adj[300005];
int color[300005];
void initialize()
{
	s1=s2=0;
	for(auto i=1;i<=n;i++)
	{
		vis[i]=false;
		adj[i].clear();
		color[i]=0;
	}
}
bool bfs(ll s)
{
	queue<ll> q;
	q.push(s);
	color[s]=1;
	bool ans=true;
	while(!q.empty())
	{
		ll t=q.front();q.pop();
		vis[t]=true;
		if(color[t]==1)
			s1++;
		else
			s2++;
		for(auto j:adj[t])
		{
			if(vis[j])
			{
				if(color[j]==color[t])
					ans=false;
			}
			else
			{
				vis[j]=true;q.push(j);
				color[j]=color[t]^1^2;
			}
		}
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll t,m,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ll ans=1;
		bool verify=true;
		initialize();
		while(m--)
		{
			cin>>x>>y;
			adj[x].pb(y);adj[y].pb(x);
		}
		for(ll i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				s1=s2=0;
				verify=verify && bfs(i);
				if(verify)
				{
					if(s1!=0 && s2!=0)
						ans=(ans*((power(2,s1,MM)+power(2,s2,MM))%MM))%MM;
					else if(s1==0 && s2!=0)
						ans=(ans*power(3,s2,MM))%MM;
					else if(s1!=0 && s2==0)
						ans=(ans*power(3,s1,MM))%MM;

				}
				else {ans=0;break;}
			}
		}
		cout<<ans;
		cout<<"\n";
	}
	return 0;
}