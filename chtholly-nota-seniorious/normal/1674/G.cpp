#include "bits/stdc++.h"
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
int rd[N],cd[N],f[N];
vector<int> e[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m,i;
	cin>>n>>m;
	vector<pair<int,int>> edges(m);
	for (auto &[u,v]:edges) cin>>u>>v,++cd[u],++rd[v];
	for (auto [u,v]:edges) if (cd[u]>1&&rd[v]>1) e[u].push_back(v);
	fill_n(rd+1,n,0);
	for (i=1;i<=n;i++) for (int v:e[i]) ++rd[v];
	queue<int> q;
	for (i=1;i<=n;i++) if (!rd[i]) q.push(i);
	while (q.size())
	{
		int u=q.front();q.pop();
		for (int v:e[u])
		{
			f[v]=max(f[v],f[u]+1);
			if (!--rd[v]) q.push(v);
		}
	}
	cout<<*max_element(f+1,f+n+1)+1<<endl;
}