#include <algorithm>
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
int ans[1000005], pre[1000005][15]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("932B.in", "r", stdin); 
#endif
	for (int i = 0; i <= 1e6; i++)
	{
		if (i < 10)
		{
			ans[i] = i; 
			continue; 
		}
		int x = i, sum = 1; 
		while (x)
		{
			if (x % 10)
				sum *= x % 10; 
			x /= 10; 
		}
		ans[i] = ans[sum]; 
	}
	for (int i = 1; i <= 1e6; i++)
	{
		for (int j = 0; j < 10; j++)
			pre[i][j] = pre[i - 1][j]; 
		pre[i][ans[i]]++; 
	}
	int q; 
	scanf("%d", &q); 
	while (q--)
	{
		int l, r, k; 
		scanf("%d%d%d", &l, &r, &k); 
		printf("%d\n", pre[r][k] - pre[l - 1][k]);
	}
	return 0; 
}