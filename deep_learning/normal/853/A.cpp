#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
#define my_abs(x) ((x) < 0 ? -(x) : (x))
using namespace std; 
typedef long long ll; 
struct flight
{
	int val, idx; 
	inline bool operator <(const flight &a) const
	{
		return val > a.val; 
	}
} arr[300005];
int fa[600005], ans[300005]; 
int getfa(int u)
{
	if (fa[u] == u)
		return u; 
	return fa[u] = getfa(fa[u]); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("853A.in", "r", stdin); 
#endif
	int n, k; 
	scanf("%d%d", &n, &k); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i].val); 
		arr[i].idx = i + 1; 
	}
	ll res = 0; 
	sort(arr, arr + n); 
	for (int i = 0; i < 600005; i++)
		fa[i] = i; 
	for (int i = 0; i < n; i++)
	{
		int st = max(k + 1, arr[i].idx); 
		int pos = getfa(st); 
		ans[arr[i].idx - 1] = pos; 
		fa[pos] = pos + 1; 
		res += (ll)arr[i].val * (pos - arr[i].idx); 
	}
	printf("%lld\n", res);
	for (int i = 0; i < n; i++)
		printf("%d%c", ans[i], " \n"[i + 1 == n]);
	return 0; 
}