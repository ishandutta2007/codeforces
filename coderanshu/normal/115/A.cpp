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
int n,ans;
vector<int> v[2005];
vector<bool> vis(2005,false);
int level[2005];
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	vis[s]=true;
	level[s]=0;
	ans=max(ans,level[s]);
	while(!q.empty())
	{
		int t=q.front();q.pop();
		for(auto j:v[t])
		{
			if(!vis[j])
			{
				level[j]=level[t]+1;
				ans=max(ans,level[j]);
				vis[j]=true;q.push(j);
			}
		}
	}
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x,i;
	cin>>n;
	int myans=0;
	vector<int> check;
	for(i=1;i<=n;++i)
	{
		cin>>x;
		if(x!=-1)
		{
			v[x].pb(i);
		}
		else check.pb(i);
	}
	for(int i:check)
	{
		if(!vis[i])
		{
			ans=-1;
			bfs(i);
			myans=max(myans,ans);
		}
	}
	cout<<myans+1;
	return 0;
}