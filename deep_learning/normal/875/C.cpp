#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define mp make_pair
#define pb push_back
using namespace std; 
typedef long long ll; 
int lst[100005], to[100005], pre[100005], tot; 
int col[100005], vis[100005], a[100005], b[100005]; 
inline void add_edge(int u, int v)
{
	// cout << u << " " << v << endl; 
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u)
{
	vis[u] = 1; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (!vis[to[i]] && !col[to[i]])
		{
			dfs(to[i]); 
			continue; 
		}
		if (col[to[i]] == 2 || vis[to[i]] == 2)
		{
			printf("No\n");
			exit(0); 
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("875C.in", "r", stdin); 
#endif
	memset(lst, -1, sizeof(lst)); 
	int n, m, lst_len; 
	scanf("%d%d", &n, &m); 
	scanf("%d", &lst_len); 
	for (int i = 0; i < lst_len; i++)
		scanf("%d", a + i); 
	for (int i = 1; i < n; i++)
	{
		int l; 
		scanf("%d", &l); 
		for (int j = 0; j < l; j++)
			scanf("%d", b + j); 
		bool f = false; 
		for (int j = 0; j < lst_len && j < l; j++)
		{
			// cout << a[j] << " " << b[j] << endl; 
			if (a[j] == b[j])
				continue; 
			if (a[j] > b[j])
			{
				if (col[a[j] - 1] == 2 || col[b[j] - 1] == 1)
				{
					printf("No\n");
					return 0; 
				}
				col[a[j] - 1] = 1; 
				col[b[j] - 1] = 2; 
				// cout << a[j] << " " << b[j] << endl; 
			}
			else
				add_edge(b[j] - 1, a[j] - 1); 
			f = true; 
			break; 
		}
		if (!f && lst_len > l)
		{
			printf("No\n");
			return 0; 
		}
		memcpy(a, b, l << 2); 
		lst_len = l; 
	}
	for (int i = 0; i < m; i++)
	{
		if (col[i] == 1 && !vis[i])
			dfs(i); 
	}
	printf("Yes\n");
	int cnt = 0; 
	for (int i = 0; i < m; i++)
		cnt += col[i] == 1 || vis[i] == 1; 
	printf("%d\n", cnt);
	for (int i = 0; i < m; i++)
	{
		if (col[i] == 1 || vis[i] == 1)
			printf("%d%c", i + 1, " \n"[!--cnt]);
	}
	return 0; 
}