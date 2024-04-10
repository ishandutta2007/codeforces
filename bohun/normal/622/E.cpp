#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
int n, a, b;
vector <int> v[500005];
int res;
vector <int> c;
void dfs(int node, int par, int h)
{
	if(ss(v[node]) == 1)
		c.pb(h);
	for(auto it: v[node])
		if(it != par)
			dfs(it, node, h + 1);
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; n - 1 > i; ++i)
	{
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	for(auto it: v[1])
	{
		c.clear();
		dfs(it, 1, 0);
		sort(c.begin(), c.end());
		int w = -5;
		for(auto it: c)
		{
			w = max(w + 1, it);
		}
		res = max(res, w + 1);
	}
		
	cout << res;
		
	return 0;
}