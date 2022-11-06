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
int dp[2000005][2], app[2000005], x1[1000005], x2[1000005]; 
std::pair<int, int> pre[2000005][2]; 
std::vector<int> turn; 
std::vector<std::pair<int, int> > shot; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("936D.in", "r", stdin); 
#endif
	int n, m1, m2, t, cnt = 0; 
	scanf("%d%d%d%d", &n, &m1, &m2, &t); 
	for (int i = 0; i < m1; i++)
	{
		scanf("%d", x1 + i); 
		app[cnt++] = x1[i]; 
		app[cnt++] = x1[i] + 1; 
	}
	for (int i = 0; i < m2; i++)
	{
		scanf("%d", x2 + i); 
		app[cnt++] = x2[i]; 
		app[cnt++] = x2[i] + 1; 
	}
	app[cnt++] = n; 
	std::sort(app, app + cnt); 
	cnt = std::unique(app, app + cnt) - app; 
	while (cnt - 1 && app[cnt - 1] > n)
		cnt--; 
	memset(dp, 0x3f, sizeof(dp)); 
	dp[0][0] = dp[0][1] = 0; 
	pre[0][0] = mp(-1, -1); 
	pre[0][1] = mp(0, 0); 
	for (int i = 0; i < cnt; i++)
	{
		int a = std::binary_search(x1, x1 + m1, app[i]), b = std::binary_search(x2, x2 + m2, app[i]); 
		// printf("%d %d %d %d %d %d\n", i, app[i], a, b, dp[i][0], dp[i][1]);
		if ((!i || dp[i][0] < app[i - 1]) && dp[i][0] + a * t < dp[i + 1][0])
		{
			dp[i + 1][0] = dp[i][0] + a * t; 
			pre[i + 1][0] = mp(i, 0); 
		}
		if ((!i || dp[i][1] < app[i - 1]) && dp[i][1] + b * t < dp[i + 1][1])
		{
			dp[i + 1][1] = dp[i][1] + b * t; 
			pre[i + 1][1] = mp(i, 1); 
		}
		if (!a && std::max(dp[i + 1][1], app[i] - t) < dp[i + 1][0])
		{
			dp[i + 1][0] = std::max(dp[i + 1][1], app[i] - t); 
			pre[i + 1][0] = mp(i + 1, 1); 
		}
		if (!b && std::max(dp[i + 1][0], app[i] - t) < dp[i + 1][1])
		{
			dp[i + 1][1] = std::max(dp[i + 1][0], app[i] - t); 
			pre[i + 1][1] = mp(i + 1, 0); 
		}
	}
	if (std::min(dp[cnt][0], dp[cnt][1]) >= n)
	{
		puts("No");
		return 0; 
	}
	int cur = cnt, x = dp[cnt][0] < dp[cnt][1] ? 0 : 1; 
	while (~cur)
	{
		if (cur && std::binary_search(x ? x2 : x1, x ? (x2 + m2) : (x1 + m1), app[cur - 1]))
			shot.pb(mp(dp[cur][x], x)); 
		auto nxt = pre[cur][x]; 
		if (cur == nxt.first)
			turn.pb(app[cur - 1]); 
		cur = nxt.first; 
		x = nxt.second; 
	}
	puts("Yes"); 
	printf("%d\n", (int)turn.size());
	for (int i = (int)turn.size() - 1; i >= 0; i--)
		printf("%d%c", turn[i], " \n"[!i]);
	printf("%d\n", (int)shot.size());
	for (int i = (int)shot.size() - 1; i >= 0; i--)
		printf("%d %d\n", shot[i].first, shot[i].second + 1);
	return 0; 
}