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
inline void print(int l, int r)
{
	for (int i = l + 1; i <= r; i++)
		printf("%d ", i);
	printf("%d ", l);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("932C.in", "r", stdin); 
#endif
	int n, a, b; 
	scanf("%d%d%d", &n, &a, &b); 
	for (int i = 0; i <= 1e6; i++)
	{
		if ((ll)i * a <= n && !((n - i * a) % b))
		{
			int cur = 1; 
			for (int j = 0; j < i; j++)
			{
				print(cur, cur + a - 1); 
				cur += a; 
			}
			for (int j = 0; j < (n - i * a) / b; j++)
			{
				print(cur, cur + b - 1); 
				cur += b; 
			}
			return 0; 
		}
	}
	puts("-1"); 
	return 0; 
}