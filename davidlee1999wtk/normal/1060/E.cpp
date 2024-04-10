#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#include<functional>
#include<sstream>
#include<ctime>
#define INF 1000000000
#define fi first
#define se second
#define N 200005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
LL dp_dn[N], sum_dn[N], sz[N], sum_up[N], tot = 0;
// dp_dn: sum of dis from subtree
// sum_dn: sum of dp_dn of direct child
// sum_up: sum of dis from ancestor and sibling.
LL ans = 0;
vector<int> G[N];
bool vis[N];
int fa[N];
void dfs(int x)
{
	int chl = 0, i, v;
	vis[x] = 1;
	sz[x] = 1;
	tot++;
	ans += sum_up[x];
	for (i = 0; i < G[x].size(); i++)
	{
		v = G[x][i];
		if (vis[v])
		{
			;
		}
		else
		{
			fa[v] = x;
			sum_up[v] = sum_dn[x] + sum_up[fa[x]] + dp_dn[fa[x]] + tot;
			dfs(v);
			sz[x] += sz[v];
			dp_dn[x] += sum_dn[v] + sz[v] - 1 + 1;
			sum_dn[x] += dp_dn[v];
		}
	}
}
int main()
{
	int n, i, a, b;
	cin >> n;
	for (i = 1; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
// davidlee1999WTK 2018/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/