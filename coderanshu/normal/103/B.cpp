#pragma GCC optimize("Ofast")

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
#define INF 2e9
#define endl "\n"
int n;
vector<int> v[110];
vector<bool> vis(110,false);
void dfs(int s)
{
	vis[s]=true;
	for(auto j:v[s])
	{
		if(!vis[j])dfs(j);
	}
	return ;
}
bool isConnected()
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int m,x,y,check;
	cin>>n>>m;
	check=m;
	while(m--)
	{
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	dfs(1);
	//for(int i=1;i<=n;i++)cout<<vis[i]<<" ";
	if(isConnected() && n==check)
		cout<<"FHTAGN!";
	else cout<<"NO";
	return 0;
}