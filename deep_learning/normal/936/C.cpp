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
char a[10005], b[10005], tmp[10005]; 
int n; 
std::vector<int> ans; 
inline void rev(int len)
{
	ans.pb(len); 
	memcpy(tmp, a + n - len, len); 
	memcpy(tmp + len, a, n - len); 
	memcpy(a, tmp, n); 
	std::reverse(a, a + len); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("936C.in", "r", stdin); 
#endif
	scanf("%d%s%s", &n, a, b); 
	for (int i = 0; i < n; i++)
	{
		int pos = -1;
		for (int j = i; j < n; j++)
		{
			if (a[j] == b[i])
				pos = j; 
		}
		if (-1 == pos)
		{
			puts("-1"); 
			return 0; 
		}
		rev(n); 
		rev(pos);
		rev(1); 
	}
	rev(n); 
	printf("%d\n", (int)ans.size()); 
	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
	return 0; 
}