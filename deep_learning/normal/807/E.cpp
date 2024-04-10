#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std; 
typedef long long ll; 
map<ll, int> cnt; 
ll lst[100005];
int pos[100005];
bool vis[100005]; 
ll arr[100005], xx[100005]; 
int main()
{
	// freopen("807E.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		ll x; 
		scanf("%lld", &x); 
		cnt[x]++; 
	}
	int ans = 0; 
	while (cnt[1])
	{
		ll x = 1; 
		while (cnt[x])
		{
			cnt[x]--; 
			x <<= 1; 
		}
		lst[ans++] = x >> 1; 
	}
	int rem = 0; 
	for (map<ll, int>::iterator it = --cnt.end(); it != cnt.begin(); it--)
	{
		int tot = it->second; 
		while (tot--)
		{
			if (lst[rem] << 1 < it->first)
			{
				printf("-1\n");
				return 0; 
			}
			xx[rem++] = it->first;
		}
	}
	int l = -1, r = ans; 
	while (l <= r)
	{
		int m = l + r >> 1; 
		int tot = rem; 
		for (int i = 0; i < tot; i++)
			arr[i] = xx[i]; 
		for (int i = ans - m; i < ans; i++)
		{
			for (ll j = 1; j <= lst[i]; j <<= 1)
				arr[tot++] = j; 
		}
		memset(vis, false, sizeof(vis)); 
		sort(arr, arr + tot, greater<ll>()); 
		bool f = true; 
		if (tot > ans - m)
			f = false; 
		for (int i = 0; i < tot; i++)
		{
			if (lst[i] << 1 < arr[i])
			{
				f = false; 
				break; 
			}
		}
		if (f)
			l = m + 1; 
		else
			r = m - 1; 
	}
	for (int i = ans - r; i <= ans; i++)
		printf("%d%c", i, " \n"[i == ans]); 
	return 0; 
}