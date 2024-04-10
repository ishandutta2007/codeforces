#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
vector<int> e[N];
int a[N],f[N];
void dfs(int u,int ff)
{
	for (int v:e[u]) if (v!=f[u])
	{
		f[v]=u;
		dfs(v,-ff);
	}
	a[u]=ff*(int)e[u].size();
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;for (i=1;i<=n;i++) e[i].clear(),f[i]=0;
		for (i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,1);
		for (i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
	}
}