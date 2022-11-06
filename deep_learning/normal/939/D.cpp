#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
std::vector<std::pair<int, int> > ans; 
char a[100005], b[100005]; 
int fa[35]; 
int getfa(int u)
{
	if (u == fa[u])
		return u; 
	return fa[u] = getfa(fa[u]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("939D.in", "r", stdin); 
#endif
	int n; 
	scanf("%d%s%s", &n, a, b); 
	for (int i = 0; i < 35; i++)
		fa[i] = i; 
	for (int i = 0; i < n; i++)
	{
		int x = getfa(a[i] - 'a'), y = getfa(b[i] - 'a'); 
		if (x != y)
		{
			ans.pb(mp(x, y)); 
			fa[x] = y; 
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto x : ans)
		printf("%c %c\n", x.first + 'a', x.second + 'a');
	return 0; 
}