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
std::priority_queue<std::pair<ll, int> > que; 
int lst[200005], to[400005], pre[400005], tot; 
ll w[400005], dis[200005]; 
inline void add_edge(int u, int v, ll _w)
{
	to[tot] = v;
	pre[tot] = lst[u]; 
	w[tot] = _w; 
	lst[u] = tot++; 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("938D.in", "r", stdin); 
#endif
	memset(lst, -1, sizeof(lst)); 
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < m; i++)
	{
		int u, v;
		ll _w; 
		scanf("%d%d%lld", &u, &v, &_w); 
		add_edge(--u, --v, _w); 
		add_edge(v, u, _w); 
	}
	for (int i = 0; i < n; i++)
	{
		ll x; 
		scanf("%lld", &x); 
		dis[i] = x; 
		que.push(mp(-dis[i], i)); 
	}
	while (!que.empty())
	{
		ll d = -que.top().first; 
		int u = que.top().second; 
		que.pop(); 
		if (d != dis[u])
			continue; 
		for (int i = lst[u]; ~i; i = pre[i])
		{
			if (dis[to[i]] > dis[u] + w[i] + w[i])
			{
				dis[to[i]] = dis[u] + w[i] + w[i]; 
				que.push(mp(-dis[to[i]], to[i])); 
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%lld%c", dis[i], " \n"[i + 1 == n]);
	return 0; 
}