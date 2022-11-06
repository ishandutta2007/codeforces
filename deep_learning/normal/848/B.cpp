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
map<int, vector<pair<int, int> > > app; 
map<int, queue<pair<int, int> > > que; 
map<int, vector<int> > pos; 
pair<int, int> ans[100005]; 
int g[100005], p[100005], t[100005], idx[100005]; 
inline bool comp(int x, int y)
{
	return p[x] < p[y]; 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("848B.in", "r", stdin); 
#endif
	int n, w, h; 
	scanf("%d%d%d", &n, &w, &h); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", g + i, p + i, t + i); 
		if (g[i] - 1)
		{
			pos[p[i] - t[i]].pb(p[i]); 
			app[p[i] - t[i]].pb(mp(p[i], i)); 
			ans[i] = mp(w, p[i]); 
		}
		else
			ans[i] = mp(p[i], h); 
		idx[i] = i; 
	}
	for (map<int, vector<pair<int, int> > >::iterator it = app.begin(); it != app.end(); it++)
	{
		sort(it->second.begin(), it->second.end()); 
		for (int i = (int)it->second.size() - 1; i >= 0; i--)
			que[it->first].push(it->second[i]); 
	}
	for (map<int, vector<int> >::iterator it = pos.begin(); it != pos.end(); it++)
		sort(it->second.begin(), it->second.end(), greater<int>()); 
	sort(idx, idx + n, comp); 
	for (int j = 0; j < n; j++)
	{
		int i = idx[j]; 
		if (g[i] - 1)
			continue; 
		if (!que.count(p[i] - t[i]))
			continue; 
		ans[que[p[i] - t[i]].front().second] = ans[i]; 
		que[p[i] - t[i]].push(mp(0, i)); 
		que[p[i] - t[i]].pop(); 
	}
	map<int, queue<pair<int, int> > >::iterator it = que.begin(); 
	map<int, vector<int> >::iterator it2 = pos.begin(); 
	for (; it != que.end(); it++, it2++)
	{
		for (int i = 0; i < it2->second.size(); i++)
		{
			ans[it->second.front().second] = mp(w, it2->second[i]); 
			it->second.pop(); 
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0; 
}