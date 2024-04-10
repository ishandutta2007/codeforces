#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;
int lst[300005], to[600005], pre[600005], tot, arr[300005]; 
multiset<int> se; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
int main()
{
	// freopen("796C.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		se.insert(arr[i]); 
	}
	for (int i = 1; i < n; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		add_edge(--u, --v); 
		add_edge(v, u); 
	}
	int ans = 2e9; 
	for (int i = 0; i < n; i++)
	{
		int mx = arr[i]; 
		se.erase(se.find(arr[i])); 
		for (int j = lst[i]; ~j; j = pre[j])
		{
			mx = max(mx, arr[to[j]] + 1); 
			se.erase(se.find(arr[to[j]])); 
		}
		if (se.empty())
			ans = min(ans, mx); 
		else
			ans = min(ans, max(mx, *se.rbegin() + 2)); 
		se.insert(arr[i]); 
		for (int j = lst[i]; ~j; j = pre[j])
			se.insert(arr[to[j]]); 
	}
	printf("%d\n", ans);
	return 0; 
}