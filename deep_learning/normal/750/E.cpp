#include <bits/stdc++.h>
#define INF 0x3FFFFFFF
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll; 
char str[204800];
struct Node
{
	int dp[5][5]; 
	void init(int pos)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i == j)
					dp[i][j] = 0; 
				else
					dp[i][j] = INF; 
			}
		}
		if (str[pos] < 4)
		{
			dp[str[pos]][str[pos]] = 1; 
			dp[str[pos]][str[pos] + 1] = 0; 
		}
		else if (str[pos] == 4)
		{
			dp[3][3] = 1; 
			dp[4][4] = 1; 
		}
	}
	Node operator +(const Node &a)
	{
		Node ans; 
		for (int i = 0; i < 5; i++)
		{
			for (int j = i; j < 5; j++)
			{
				ans.dp[i][j] = INF; 
				for (int k = i; k <= j; k++)
					ans.dp[i][j] = min(ans.dp[i][j], dp[i][k] + a.dp[k][j]); 
			}
		}
		return ans; 
	}
} seg[819200]; 
void build(int u, int l, int r)
{
	if (l == r)
	{
		seg[u].init(l); 
		return; 
	}
	int m = l + r >> 1; 
	build(u << 1, l, m); 
	build(u << 1 | 1, m + 1, r); 
	seg[u] = seg[u << 1] + seg[u << 1 | 1]; 
}
Node query(int u, int l, int r, int L, int R)
{
	// cout << l << " " << r << " " << L << " " << R << endl; 
	if (l >= L && r <= R)
		return seg[u]; 
	int m = l + r >> 1; 
	if (L <= m && m < R)
		return query(u << 1, l, m, L, R) + query(u << 1 | 1, m + 1, r, L, R); 
	if (L <= m)
		return query(u << 1, l, m, L, R); 
	if (m < R)
		return query(u << 1 | 1, m + 1, r, L, R); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("750E.in", "r", stdin); 
#endif
	int n, q; 
	scanf("%d%d", &n, &q); 
	scanf("%s", str); 
	for (int i = 0; i < n; i++)
	{
		char &c = str[i]; 
		if (c == '6')
			c = 4; 
		else if (c == '2')
			c = 0; 
		else if (c == '0')
			c = 1; 
		else if (c == '1')
			c = 2; 
		else if (c == '7')
			c = 3; 
		else
			c = 5; 
	}
	build(1, 0, n - 1); 
	while (q--)
	{
		int l, r; 
		scanf("%d%d", &l, &r);
		Node ans = query(1, 0, n - 1, --l, --r); 
		printf("%d\n", ans.dp[0][4] == INF ? -1 : ans.dp[0][4]);
	}
	return 0; 
}