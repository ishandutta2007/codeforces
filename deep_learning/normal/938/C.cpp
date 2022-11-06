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
int main()
{
#ifndef ONLINE_JUDGE
	freopen("938C.in", "r", stdin); 
#endif
	int t; 
	scanf("%d", &t); 
	while (t--)
	{
		int x; 
		scanf("%d", &x); 
		bool f = false; 
		for (int n = 1; n <= 100000 && !f; n++)
		{
			if ((ll)n * n <= x)
				continue; 
			int m = sqrt((ll)n * n - x); 
			if ((ll)m * m + x != (ll)n * n)
				continue; 
			if (n / (n / m) == m)
			{
				printf("%d %d\n", n, n / m);
				f = true; 
			}
		}
		if (!f)
			puts("-1"); 
	}
	return 0; 
}