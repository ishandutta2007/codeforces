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
int que[500005]; 
ll pre[500005]; 
inline double calc(int pos, int x)
{
	return (double)(x + pre[pos]) / (pos + 1); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("939E.in", "r", stdin); 
#endif
	int q, n = 0, he = 0, ta = 0; 
	scanf("%d", &q);
	double ans = -1e9; 
	while (q--)
	{
		int tp; 
		scanf("%d", &tp); 
		if (tp - 1)
			printf("%.15lf\n", ans);
		else
		{
			int x; 
			scanf("%d", &x); 
			while (he < ta && calc(que[he], x) > calc(que[he + 1], x))
				he++; 
			ans = std::max(ans, x - calc(que[he], x)); 
			while (he < ta && calc(que[ta - 1], x) > calc(que[ta], x))
				ta--; 
			n++; 
			que[++ta] = n; 
			pre[n] = pre[n - 1] + x; 
		}
	}
	return 0; 
}