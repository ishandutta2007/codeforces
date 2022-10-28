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
int level[200005],temp[200005],n,v[200005];
vector<int> adj[200005];
void bfs(int r)
{
	vector<bool> vis(n+1,false);
	int i;
	queue<int>q;
	for(i=1;i<=n;++i)
	{
		temp[i]=-1;
		if(v[i]%2==r)
		{
			q.push(i);
			vis[i]=true;
			temp[i]=0;
		}	
	}
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(auto j:adj[t])
		{
			if(!vis[j])
			{
				vis[j]=true;q.push(j);temp[j]=temp[t]+1;
			}
		}
	}
	for(i=1;i<=n;++i)
	{
		if(vis[i] && v[i]%2!=r)
			level[i]=temp[i];
		else if(!vis[i] && v[i]%2!=r)level[i]=-1;
	}
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
	}
	for(i=1;i<=n;++i)
	{
		if(i-v[i]>0)
		{
			adj[i-v[i]].pb(i);
		}
		if(i+v[i]<=n)
		{
			adj[i+v[i]].pb(i);
		}
	}
	bfs(0);bfs(1);
	for(i=1;i<=n;++i)cout<<level[i]<<" ";
	return 0;
}