#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//cin
const int N=100005;
int n,m;
vector<int> f[N];
int cst[N];
bool vis[N];
long long ans;
int u,v;
int dfs(int i)
{
	if(vis[i]) return cst[i];
	int res=cst[i];
	vis[i]=1;
	for(int j=0;j<f[i].size();j++)
	{
		res=min(res,dfs(f[i][j]));
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>cst[i];
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		f[u].push_back(v);
		f[v].push_back(u);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) ans+=dfs(i);
	cout<<ans<<endl;
	return 0;
}
/*
5 2
2 5 3 4 8
1 4
4 5

10 0
1 2 3 4 5 6 7 8 9 10

10 5
1 6 2 7 3 8 4 9 5 10
1 2
3 4
5 6
7 8
9 10
8 8
1 2 3 4 5 6 7 8
1 2
1 3
1 4
1 5
2 3
2 4
5 6
6 7

*/