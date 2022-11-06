#include <iostream>
#include <utility>
#include <cstdio>
#include <vector>
#include <map>
#define mp make_pair
using namespace std;
map<pair<int, int>, pair<int, int> > mx, mx2;  
inline void upd(int a, int b, int c, int idx)
{
	if (c > mx[mp(a, b)].first)
	{
		mx2[mp(a, b)] = mx[mp(a, b)]; 
		mx[mp(a, b)] = mp(c, idx); 
	}
	else if (c > mx2[mp(a, b)].first && idx != mx[mp(a, b)].second)
		mx2[mp(a, b)] = mp(c, idx);
}
int main()
{
	// freopen("733D.in", "r", stdin); 
	int n, res = 0; 
	vector<int> ans; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		int a, b, c; 
		scanf("%d%d%d", &a, &b, &c); 
		if (min(a, min(b, c)) > res)
		{
			res = min(a, min(b, c)); 
			ans = vector<int>(1, i); 
		}
		upd(a, b, c, i); 
		upd(a, c, b, i); 
		upd(b, a, c, i); 
		upd(b, c, a, i); 
		upd(c, a, b, i); 
		upd(c, b, a, i); 
	}
	for (map<pair<int, int>, pair<int, int> >::iterator it = mx.begin(); it != mx.end(); it++)
	{
		if (mx2.count(it->first)
		 && min(it->first.first, min(it->first.second, it->second.first + mx2[it->first].first)) > res)
		{
			res = min(it->first.first, min(it->first.second, it->second.first + mx2[it->first].first)); 
			ans = vector<int>(2, it->second.second); 
			ans[1] = mx2[it->first].second; 
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i] + 1, " \n"[i + 1 == ans.size()]);
	return 0; 
}