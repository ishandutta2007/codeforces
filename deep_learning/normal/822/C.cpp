#include <algorithm>
#include <iostream>
#include <cstring>
#include <utility>
#include <cstdio>
#include <vector>
#define mp make_pair
#define pb push_back
using namespace std; 
int app[200005]; 
vector<pair<int, int> > a[200005], b[200005]; 
int main()
{
	// freopen("822C.in", "r", stdin); 
	int n, x; 
	scanf("%d%d", &n, &x); 
	for (int i = 0; i < n; i++)
	{
		int l, r, w; 
		scanf("%d%d%d", &l, &r, &w); 
		a[l].pb(mp(r - l + 1, w)); 
		b[r].pb(mp(r - l + 1, w)); 
	}
	memset(app, 0x3f, sizeof(app)); 
	int ans = 2000000005; 
	for (int i = 0; i < 200005; i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			if (a[i][j].first <= x && app[x - a[i][j].first] != 0x3f3f3f3f)
				ans = min(ans, a[i][j].second + app[x - a[i][j].first]); 
		}
		for (int j = 0; j < b[i].size(); j++)
			app[b[i][j].first] = min(app[b[i][j].first], b[i][j].second); 
	}
	printf("%d\n", ans == 2000000005 ? -1 : ans);
	return 0; 
}