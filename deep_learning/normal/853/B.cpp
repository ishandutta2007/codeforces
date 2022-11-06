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
	int day, cost, u; 
	flight()
	{
	}
	flight(int _day, int _cost, int _u)
	{
		day = _day; 
		cost = _cost;
		u = _u; 
	}
	inline bool operator <(const flight &a) const
	{
		return day < a.day; 
	}
} in[1000005], out[1000005]; 
int in_cnt, out_cnt, mn[1000005], n, m, k; 
ll pre[1000005]; 
bool ok[1000005], vis[1000005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("853B.in", "r", stdin); 
#endif
	scanf("%d%d%d", &n, &m, &k); 
	for (int i = 0; i < m; i++)
	{
		int d, f, t, c; 
		scanf("%d%d%d%d", &d, &f, &t, &c); 
		if (!f)
			out[out_cnt++] = flight(-d, c, --t); 
		else
			in[in_cnt++] = flight(d, c, --f); 
	}
	sort(in, in + in_cnt); 
	sort(out, out + out_cnt); 
	// for (int i = 0; i < out_cnt; i++)
	// 	printf("%d %d %d\n", -out[i].day, out[i].cost, out[i].u);
	memset(mn, 0x3f, sizeof(mn)); 
	int idx = 0, cnt = n;  
	ll ans = 0, res = 1e18; 
	for (int i = 1; i < 1000005; i++)
	{
		pre[i] = pre[i - 1]; 
		while (idx < in_cnt && in[idx].day == i)
		{
			// cout << in[idx].u << endl; 
			if (mn[in[idx].u] > in[idx].cost)
			{
				cnt -= !vis[in[idx].u]; 
				if (!vis[in[idx].u])
					pre[i] += in[idx].cost; 
				else
					pre[i] -= mn[in[idx].u] - in[idx].cost; 
				vis[in[idx].u] = true; 
				mn[in[idx].u] = in[idx].cost; 
			}
			idx++; 
		}
		if (!cnt)
			ok[i] = true; 
		// if (i <= 3)
		// 	cout << i << " " << pre[i] << endl; 
	}
	memset(mn, 0x3f, sizeof(mn)); 
	memset(vis, false, sizeof(vis)); 
	idx = 0; 
	cnt = n; 
	bool f = false; 
	for (int i = 1000004; i > k; i--)
	{
		while (idx < out_cnt && -out[idx].day == i)
		{
			if (mn[out[idx].u] > out[idx].cost)
			{
				cnt -= !vis[out[idx].u]; 
				if (!vis[out[idx].u])
					ans += out[idx].cost; 
				else
					ans -= mn[out[idx].u] - out[idx].cost; 
				vis[out[idx].u] = true; 
				mn[out[idx].u] = out[idx].cost; 
			}
			idx++; 
		}
		// if (i <= 3)
		// 	cout << i << " " << cnt << " " << ans << endl; 
		if (!cnt && ok[i - k - 1])
		{
			f = true; 
			res = min(res, ans + pre[i - k - 1]); 
		}
	}
	if (!f)
		printf("-1\n");
	else
		printf("%lld\n", res);
	return 0; 
}