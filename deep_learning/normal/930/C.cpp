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
int sum[100005], seq[100005], lis[100005]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("930C.in", "r", stdin); 
#endif
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++)
	{
		int l, r; 
		scanf("%d%d", &l, &r); 
		sum[--l]++; 
		sum[r]--; 
	}
	for (int i = 0; i < m; i++)
	{
		if (i)
			sum[i] += sum[i - 1]; 
	}
	int len = 0, ans = 0; 
	for (int i = 0; i < m; i++)
	{
		int pos = std::upper_bound(seq, seq + len, sum[i]) - seq; 
		seq[pos] = sum[i]; 
		len = std::max(len, pos + 1); 
		lis[i] = std::max(i ? lis[i - 1] : 0, len); 
	}
	len = 0; 
	for (int i = m - 1; i; i--)
	{
		int pos = std::upper_bound(seq, seq + len, sum[i]) - seq; 
		seq[pos] = sum[i]; 
		len = std::max(len, pos + 1); 
		ans = std::max(ans, len + lis[i - 1]); 
	}
	printf("%d\n", ans);
	return 0; 
}