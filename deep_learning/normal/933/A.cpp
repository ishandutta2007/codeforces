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
#define calc(x, l, r) ((l) > (r) ? 0 : cnt[x][r] - ((l) ? cnt[x][(l) - 1] : 0))
typedef long long ll; 
int arr[2005], cnt[2][2005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("933A.in", "r", stdin); 
#endif
	int n, ans = 0; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		cnt[0][i] = (i ? cnt[0][i - 1] : 0) + (arr[i] == 1); 
		cnt[1][i] = (i ? cnt[1][i - 1] : 0) + (arr[i] == 2); 
	}
	for (int i = -1; i < n; i++)
		ans = std::max(ans, calc(0, 0, i) + calc(1, i + 1, n - 1));
	for (int l = 0; l < n; l++)
	{
		int res = 0, two = 0; 
		for (int r = l; r < n; r++)
		{
			if (arr[r] == 1)
			{
				res = std::max(res, two); 
				res++; 
			}
			else
				two++; 
			ans = std::max(ans, calc(0, 0, l - 1) + res + calc(1, r + 1, n - 1)); 
		}
	}
	printf("%d\n", ans);
	return 0; 
}