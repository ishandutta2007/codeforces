#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int arr[100005], dep[100005]; 
int res, cnt[50000005]; 
int lst[100005], to[200005], pre[200005], tot; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u)
{
	if (-1 == lst[u])
		res = dep[u]; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		dep[to[i]] = dep[u] ^ 1; 
		dfs(to[i]); 
	}
}
int main()
{
	// freopen("812E.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n, sum = 0, num = 0; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	for (int i = 1; i < n; i++)
	{
		int x; 
		scanf("%d", &x); 
		add_edge(--x, i); 
	}
	dfs(0); 
	ll ans = 0; 
	for (int i = 0; i < n; i++)
	{
		if ((dep[i] & 1) ^ (res & 1))
			cnt[arr[i]]++; 
		else
		{
			sum ^= arr[i]; 
			num++; 
		}
	}
	if (!sum)
		ans += (ll)num * (num - 1) / 2 + (ll)(n - num) * (n - num - 1) / 2; 
	for (int i = 0; i < n; i++)
	{
		if ((dep[i] & 1) ^ (res & 1) ^ 1)
			ans += cnt[sum ^ arr[i]]; 
	}
	printf("%lld\n", ans);
	return 0;
}