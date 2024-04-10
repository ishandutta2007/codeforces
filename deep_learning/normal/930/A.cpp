#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
int cnt[1000005], dep[1000005], lst[1000005], to[1000005], pre[1000005], tot; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u)
{
	cnt[dep[u]]++; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		dep[to[i]] = dep[u] + 1;
		dfs(to[i]); 
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("930A.in", "r", stdin); 
#endif
	memset(lst, -1, sizeof(lst)); 
	int n, ans = 0; 
	scanf("%d", &n); 
	for (int i = 1; i < n; i++)
	{
		int x; 
		scanf("%d", &x); 
		add_edge(--x, i); 
	}
	dfs(0); 
	for (int i = 0; i <= n; i++)
		ans += cnt[i] & 1; 
	printf("%d\n", ans);
	return 0; 
}