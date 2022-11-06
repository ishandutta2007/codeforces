#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
using namespace std; 
typedef long long ll; 
int seg[100005], arr[100005], n; 
vector<int> app[100005]; 
inline void modify(int pos, int x)
{
	for (; pos <= n; pos += pos & -pos)
		seg[pos] += x; 
}
inline int query(int pos)
{
	int res = 0; 
	for (; pos; pos -= pos & -pos)
		res += seg[pos]; 
	return res; 
}
int main()
{
	// freopen("B.in", "r", stdin); 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", arr + i); 
		app[arr[i]].pb(i); 
		modify(i, 1); 
	}
	int cur = 1; 
	ll ans = 0; 
	for (int i = 1; i <= 100000; i++)
	{
		if (!app[i].size())
			continue; 
		if (*app[i].begin() >= cur)
		{
			ans += query(*app[i].rbegin()) - query(cur - 1); 
			cur = *app[i].rbegin(); 
		}
		else
		{
			int pos = lower_bound(app[i].begin(), app[i].end(), cur) - app[i].begin(); 
			pos--; 
			ans += query(n) - query(cur - 1) + query(app[i][pos]); 
			cur = app[i][pos]; 
		}
		for (int j = 0; j < app[i].size(); j++)
			modify(app[i][j], -1); 
	}
	printf("%lld\n", ans);
	return 0; 
}