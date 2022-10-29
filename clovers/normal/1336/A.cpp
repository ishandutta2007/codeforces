#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=300001;
#define mk make_pair
#define int long long

int n,k,sz[N],dep[N];
vector<int> v[N];

void dfs(int u,int f)
{
	sz[u]=1;
	for(int i=0;i<(int)v[u].size();i++)
	{
		int to=v[u][i];
		if(to==f) continue;
		dep[to]=dep[u]+1;
		dfs(to,u);
		sz[u]+=sz[to];
	}
}

signed main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dep[1]=0;
	dfs(1,-1);
	for(int i=1;i<=n;i++) sz[i]-=(dep[i]+1);
	sort(sz+1,sz+n+1);
	int ans=n-1;
	for(int i=n-1;i>=k+1;i--) 
	{
		ans+=sz[i];
	}
	cout<<ans<<endl; 
	return 0;
}