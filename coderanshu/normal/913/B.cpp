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
bool ans=true;int n;
vector<int> v[1005];
vector<bool> vis(1005,false);
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	int count;
	vis[s]=true;
	while(!q.empty())
	{
		int t=q.front();q.pop();
		count=0;
		for(auto j:v[t])
		{
			count+=(v[j].size()==0);
			if(!vis[j])
			{
				vis[j]=true;q.push(j);
			}
		}
		if(!(v[t].size()==0) && count<3)
			{
				ans=false;
				return ;
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
	for(i=2;i<=n;++i)
	{
		cin>>x;
		v[x].pb(i);
	}
	bfs(1);

	if(ans)cout<<"Yes";
	else cout<<"No";
	return 0;
}