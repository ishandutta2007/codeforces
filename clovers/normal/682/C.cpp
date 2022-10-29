#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
const int N=200005;
ll dp[N],a[N],sz[N],bl[N],ans=0;
int n;
vector<pii> v[N];

void dfs(int u,int f)
{
	//cout<<u<<" "<<bl[u]<<endl;
	if(bl[u]) ans++;
	for(int i=0;i<(int)v[u].size();i++)
	{
		int to=v[u][i].first;
		ll w=v[u][i].second;
		if(to==f) continue;
		dp[to]=max(0LL,dp[u]+w);
		if(dp[to]>a[to]||bl[u]) bl[to]=1;
		dfs(to,u);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=2;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(make_pair(i,y));
		v[i].push_back(make_pair(x,y));
	} 
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}