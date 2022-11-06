#include <iostream>
#include <cstdio>
#include <map>
using namespace std; 
typedef long long ll; 
ll seg[200005], h[100005], dp[100005]; 
int n, cnt, arr[100005], a[100005], b[100005]; 
map<int, int> mn; 
map<int, ll> tot; 
inline void modify(int pos, ll x)
{
	for (seg[pos += cnt] += x; pos; pos >>= 1)
		seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]); 
}
inline ll query(int l, int r)
{
	ll res = 0; 
	for (l += cnt, r += cnt; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			res = max(res, seg[l++]); 
		if (r & 1)
			res = max(res, seg[--r]); 
	}
	return res; 
}
int main()
{
	// freopen("777E.in", "r", stdin); 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		int a, b, h; 
		scanf("%d%d%d", &a, &b, &h); 
		if (mn.count(b))
			mn[b] = min(mn[b], a); 
		else
			mn[b] = a; 
		tot[b] += h; 
	}
	for (map<int, int>::iterator it = mn.begin(); it != mn.end(); it++)
	{
		arr[cnt] = it->first;
		a[cnt] = it->second; 
		b[cnt] = it->first; 
		h[cnt++] = tot[it->first]; 
	}
	ll ans = 0; 
	for (int i = 0; i < cnt; i++)
	{
		dp[i] = query(lower_bound(arr, arr + cnt, a[i] + 1) - arr, lower_bound(arr, arr + cnt, b[i]) - arr + 1) + h[i]; 
		modify(lower_bound(arr, arr + cnt, b[i]) - arr, dp[i]); 
		ans = max(ans, dp[i]); 
	}
	printf("%lld\n", ans);
	return 0; 
}