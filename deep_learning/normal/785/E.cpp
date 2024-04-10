#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll; 
const int sz = 450; 
int arr[300005], sorted[300005], num[300005], lp[455], rp[455]; 
inline void init()
{
	int cur = 0; 
	for (int i = 0; i < sz; i++)
	{
		lp[i] = cur; 
		for (int j = 0; j < sz; j++, cur++)
		{
			num[cur] = i; 
			sorted[cur] = arr[cur]; 
		}
		rp[i] = cur; 
		sort(sorted + lp[i], sorted + rp[i]); 
	}
}
inline int query(int l, int r, int mn, int mx)
{
	if (l > r)
		return 0; 
	int ans = 0; 
	if (num[l] == num[r])
	{
		for (int i = l; i <= r; i++)
			ans += arr[i] >= mn && arr[i] <= mx; 
		return ans; 
	}
	for (int i = l; i < rp[num[l]]; i++)
		ans += arr[i] >= mn && arr[i] <= mx; 
	for (int i = num[l] + 1; i < num[r]; i++)
		ans += upper_bound(sorted + lp[i], sorted + rp[i], mx) - lower_bound(sorted + lp[i], sorted + rp[i], mn); 
	for (int i = lp[num[r]]; i <= r; i++)
		ans += arr[i] >= mn && arr[i] <= mx; 
	return ans; 
}
inline void modify(int pos, int x)
{
	arr[pos] = x; 
	for (int i = lp[num[pos]]; i < rp[num[pos]]; i++)
		sorted[i] = arr[i]; 
	sort(sorted + lp[num[pos]], sorted + rp[num[pos]]); 
}
int main()
{
	// freopen("785E.in", "r", stdin); 
	int n, q; 
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		arr[i] = i; 
	init(); 
	ll ans = 0; 
	while (q--)
	{
		int l, r; 
		scanf("%d%d", &l, &r); 
		if (l > r)
			swap(l, r); 
		int x = arr[--l], y = arr[--r]; 
		if (x < y)
			ans += query(l + 1, r - 1, x, y) << 1 | 1; 
		else if (x > y)
			ans -= query(l + 1, r - 1, y, x) << 1 | 1; 
		modify(l, y); 
		modify(r, x); 
		printf("%lld\n", ans);
	}
	return 0; 
}