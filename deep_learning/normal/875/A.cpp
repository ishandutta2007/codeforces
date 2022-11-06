#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define mp make_pair
#define pb push_back
using namespace std; 
typedef long long ll; 
vector<int> ans; 
void dfs(int n, int x, int cur = 0)
{
	// cout << n << " " << x << " " << cur << endl; 
	if (!x)
	{
		if (!n)
			ans.pb(cur); 
		return; 
	}
	int tmp = n / (x + 1); 
	if (tmp < 10)
		dfs(n - tmp * (x + 1), x / 10, cur * 10 + tmp); 
	if (tmp && tmp - 1 < 10)
		dfs(n - (tmp - 1) * (x + 1), x / 10, cur * 10 + tmp - 1); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("875A.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n);
	dfs(n, 1e9); 
	printf("%d\n", (int)ans.size());
	sort(ans.begin(), ans.end()); 
	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
	return 0; 
}