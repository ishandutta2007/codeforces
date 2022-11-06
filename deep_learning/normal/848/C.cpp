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
#define mp make_pair
#define pb push_back
#define my_abs(x) ((x) < 0 ? -(x) : (x))
using namespace std; 
typedef long long ll; 
const int sz = 320; 
int l[200005], r[200005], belong[200005], pre[200005], nxt[200005], arr[100005]; 
ll pre_sum[200005], nxt_sum[200005]; 
vector<int> app[100005]; 
// struct mp
// {
// 	int first, second; 
// 	mp()
// 	{
// 		first = 0; 
// 		second = 0; 
// 	}
// 	mp(int x, int y)
// 	{
// 		first = x; 
// 		second = y; 
// 	}
// 	inline bool operator <(const mp &a) const
// 	{
// 		if (first == a.first)
// 			return second < a.second; 
// 		return first < a.first; 
// 	}
// } sorted_pre[200005], sorted_nxt[200005]; 
pair<int, int> sorted_pre[200005], sorted_nxt[200005]; 
inline void init()
{
	int cur = 0; 
	for (int i = 0; i < sz; i++)
	{
		l[i] = cur; 
		for (int j = 0; j < sz; j++, cur++)
		{
			sorted_pre[cur] = mp(pre[cur], cur); 
			sorted_nxt[cur] = mp(nxt[cur], cur); 
			belong[cur] = i; 
		}
		r[i] = cur; 
		sort(sorted_pre + l[i], sorted_pre + r[i]); 
		sort(sorted_nxt + l[i], sorted_nxt + r[i]); 
		// for (int j = l[i]; j < r[i]; j++)
		// 	cout << sorted_pre[j].first << " " << sorted_pre[j].second << endl; 
		for (int j = l[i]; j < r[i]; j++)
		{
			pre_sum[j] = (j == l[i] ? 0 : pre_sum[j - 1]) + sorted_pre[j].second; 
			nxt_sum[j] = (j == l[i] ? 0 : nxt_sum[j - 1]) + sorted_nxt[j].second; 
		}
	}
}
inline ll query_greater(int lp, int rp, int mn)
{
	ll ans = 0; 
	if (belong[lp] == belong[rp])
	{
		for (int i = lp; i <= rp; i++)
		{
			if (nxt[i] >= mn)
				ans += i; 
		}
		return ans; 
	}
	for (int i = lp; i < r[belong[lp]]; i++)
	{
		if (nxt[i] >= mn)
			ans += i; 
	}
	for (int i = belong[lp] + 1; i < belong[rp]; i++)
	{
		int pos = lower_bound(sorted_nxt + l[i], sorted_nxt + r[i], mp(mn, -1)) - sorted_nxt; 
		// cout << l[i] << " " << r[i] << " " << pos << endl; 
		if (pos == r[i])
			continue; 
		if (pos == l[i])
			ans += nxt_sum[r[i] - 1]; 
		else
			ans += nxt_sum[r[i] - 1] - nxt_sum[pos - 1]; 
	}
	for (int i = l[belong[rp]]; i <= rp; i++)
	{
		if (nxt[i] >= mn)
			ans += i; 
	}
	return ans; 
}
inline ll query_less(int lp, int rp, int mx)
{
	ll ans = 0; 
	if (belong[lp] == belong[rp])
	{
		for (int i = lp; i <= rp; i++)
		{
			if (pre[i] <= mx)
				ans += i; 
		}
		return ans; 
	}
	for (int i = lp; i < r[belong[lp]]; i++)
	{
		if (pre[i] <= mx)
			ans += i; 
	}
	for (int i = belong[lp] + 1; i < belong[rp]; i++)
	{
		int pos = lower_bound(sorted_pre + l[i], sorted_pre + r[i], mp(mx, 200000)) - sorted_pre; 
		// cout << l[i] << " " << r[i] << " " << pos << endl; 
		if (pos != l[i])
			ans += pre_sum[pos - 1]; 
	}
	for (int i = l[belong[rp]]; i <= rp; i++)
	{
		if (pre[i] <= mx)
			ans += i; 
	}
	return ans; 
}
inline void modify_nxt(int pos, int x)
{
	// cout << "nxt:" << pos << " " << x << endl; 
	nxt[pos] = x; 
	for (int i = l[belong[pos]]; i < r[belong[pos]]; i++)
		sorted_nxt[i] = mp(nxt[i], i); 
	sort(sorted_nxt + l[belong[pos]], sorted_nxt + r[belong[pos]]); 
	for (int j = l[belong[pos]]; j < r[belong[pos]]; j++)
		nxt_sum[j] = (j == l[belong[pos]] ? 0 : nxt_sum[j - 1]) + sorted_nxt[j].second; 
}
inline void modify_pre(int pos, int x)
{
	// cout << "pre:" << pos << " " << x << endl; 
	pre[pos] = x; 
	for (int i = l[belong[pos]]; i < r[belong[pos]]; i++)
		sorted_pre[i] = mp(pre[i], i); 
	sort(sorted_pre + l[belong[pos]], sorted_pre + r[belong[pos]]); 
	for (int j = l[belong[pos]]; j < r[belong[pos]]; j++)
		pre_sum[j] = (j == l[belong[pos]] ? 0 : pre_sum[j - 1]) + sorted_pre[j].second; 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("848C.in", "r", stdin); 
#endif
	int n, q; 
	scanf("%d%d", &n, &q); 
	memset(pre, 0x3f, sizeof(pre)); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		app[arr[i]].pb(i); 
	}
	for (int i = 1; i <= n; i++)
	{
		if (!app[i].size())
			continue; 
		for (int j = 1; j < app[i].size(); j++)
			pre[app[i][j]] = app[i][j - 1]; 
		pre[app[i][0]] = -1; 
		for (int j = 0; j < app[i].size() - 1; j++)
			nxt[app[i][j]] = app[i][j + 1]; 
		nxt[app[i][app[i].size() - 1]] = n; 
	}
	init(); 
	while (q--)
	{
		int tp; 
		scanf("%d", &tp); 
		if (tp - 1)
		{
			int l, r; 
			scanf("%d%d", &l, &r); 
			l--; 
			r--; 
			// cout << query_greater(l, r, r + 1) << " " <<  query_less(l, r, l - 1) << endl; 
			printf("%lld\n", query_greater(l, r, r + 1) - query_less(l, r, l - 1));
		}
		else
		{
			int p, x; 
			scanf("%d%d", &p, &x);
			p--;
			int pos = lower_bound(app[arr[p]].begin(), app[arr[p]].end(), p) - app[arr[p]].begin(); 
			// cout << pos << endl; 
			if (pos)
				modify_nxt(app[arr[p]][pos - 1], pos + 1 == app[arr[p]].size() ? n : app[arr[p]][pos + 1]); 
			if (pos + 1 != app[arr[p]].size())
				modify_pre(app[arr[p]][pos + 1], !pos ? -1 : app[arr[p]][pos - 1]); 
			app[arr[p]].erase(app[arr[p]].begin() + pos); 
			pos = lower_bound(app[x].begin(), app[x].end(), p) - app[x].begin(); 
			// cout << pos << endl; 
			if (pos)
				modify_nxt(app[x][pos - 1], p); 
			if (pos != app[x].size())
				modify_pre(app[x][pos], p); 
			modify_pre(p, pos ? app[x][pos - 1] : -1); 
			modify_nxt(p, pos == app[x].size() ? n : app[x][pos]); 
			app[x].insert(app[x].begin() + pos, p); 
			// for (int i = 0; i < app[x].size(); i++)
			// 	printf("%d%c", app[x][i], " \n"[i + 1 == app[x].size()]);
			arr[p] = x; 
		}
	}
	return 0; 
}
//