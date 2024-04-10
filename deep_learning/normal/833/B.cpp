#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int lazy[200005], seg[200005], dp[35005], lst[35005], pre[35005], arr[35005]; 
void modify(int u, int l, int r, int L, int R, int x)
{
	if (L > R)
		return; 
	if (L <= l && r <= R)
	{
		lazy[u] += x; 
		seg[u] += x; 
		return; 
	}
	int m = l + r >> 1; 
	if (L <= m)
		modify(u << 1, l, m, L, R, x);
	if (m < R)
		modify(u << 1 | 1, m + 1, r, L, R, x); 
	seg[u] = max(seg[u << 1], seg[u << 1 | 1]) + lazy[u]; 
}
int query(int u, int l, int r, int L, int R)
{
	if (L > R)
		return 0; 
	if (L <= l && r <= R)
		return seg[u]; 
	int m = l + r >> 1, ans = 0; 
	if (L <= m)
		ans = max(ans, query(u << 1, l, m, L, R)); 
	if (m < R)
		ans = max(ans, query(u << 1 | 1, m + 1, r, L, R)); 
	return ans + lazy[u]; 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("833B.in", "r", stdin); 
#endif
	memset(lst, -1, sizeof(lst));
	int n, k; 
	scanf("%d%d", &n, &k); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		pre[i] = lst[arr[i]]; 
		lst[arr[i]] = i; 
	}
	modify(1, 0, n - 1, 1, n - 1, -1e9); 
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			modify(1, 0, n - 1, pre[j] + 1, j, 1); 
			dp[j + 1] = query(1, 0, n - 1, 0, j); 
		}
		memset(seg, 0, sizeof(seg)); 
		memset(lazy, 0, sizeof(lazy)); 
		for (int j = 0; j < n; j++)
			modify(1, 0, n - 1, j, j, dp[j]); 
	}
	printf("%d\n", dp[n]);
	return 0; 
}