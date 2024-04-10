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
int n,curr;
bool ans=true;
set<int> v[200005];
vector<bool> vis(200005,false);
int arr[200005];
void bfs(int s)
{
	int sz,j;
	queue<int> q;
	q.push(s);
	vis[s]=true;
	++curr;
	while(!q.empty())
	{
		int t=q.front();q.pop();
		sz=v[t].size()+curr;
		for(;curr<sz;++curr)
		{
			if(v[t].count(arr[curr]))
			{
				v[t].erase(arr[curr]);
				v[arr[curr]].erase(t);
				q.push(arr[curr]);

			}
			else
			{
				ans=false;return ;
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
	int x,y,i;
	cin>>n;
	curr=0;
	for(i=0;i<n-1;++i)
	{
		cin>>x>>y;
		v[x].insert(y);
		v[y].insert(x);
	}
	for(i=0;i<n;++i)
		cin>>arr[i];
	bfs(1);
	if(ans)cout<<"Yes";
	else cout<<"No";
	return 0;
}