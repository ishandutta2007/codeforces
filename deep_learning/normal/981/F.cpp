#include <algorithm>
#include <cstring>
#include <cstdio>
int n, len, a[200005], b[200005], pre[200005]; 
inline void add(int l, int r, int idx)
{
	l = std::lower_bound(b, b + n, l) - b; 
	r = std::upper_bound(b, b + n, r) - b - 1; 
	if (l > r)
		return; 
	l = (l + n - idx) % n; 
	r = (r + n - idx) % n; 
	if (l <= r)
	{
		pre[l]++; 
		pre[r + 1]--; 
	}
	else
	{
		pre[l]++; 
		pre[0]++; 
		pre[r + 1]--; 
	}
}
int main()
{
	// freopen("981F.in", "r", stdin); 
	scanf("%d%d", &n, &len); 
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int i = 0; i < n; i++)
		scanf("%d", b + i);
	std::sort(a, a + n); 
	std::sort(b, b + n); 
	int l = 0, r = len, ans = -1;
	while (l <= r)
	{
		int m = l + r >> 1; 
		memset(pre, 0, sizeof(pre)); 
		for (int i = 0; i < n; i++)
		{
			int mn_l = std::max(0, a[i] - m), mx_r = std::min(len - 1, a[i] + m); 
			int L = -1, R = len; 
			if (a[i] - (len - m) >= mn_l)
				mn_l = 0; 
			else
				L = std::max(-1, a[i] - (len - m)); 
			if (a[i] + (len - m) <= mx_r)
				mx_r = len - 1; 
			else
				R = std::min(len, a[i] + (len - m)); 
			add(mn_l, mx_r, i); 
			add(0, L, i); 
			add(R, len - 1, i); 
		}
		for (int i = 1; i < n; i++)
			pre[i] += pre[i - 1]; 
		bool f = false; 
		for (int i = 0; i < n; i++)
			f |= pre[i] == n; 
		if (f)
		{
			ans = m; 
			r = m - 1; 
		}
		else
			l = m + 1; 
	}
	printf("%d\n", ans);
	return 0;
}