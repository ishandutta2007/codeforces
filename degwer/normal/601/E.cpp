#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define SIZE 32768
ll base = 10000019;
ll mod = 1000000007;
int cst[15000];
int val[15000];
int ord[15000];
int fin[15000];
int dp[SIZE * 2][1001];
int cdp[1001];
class segtree
{
public:
	vector<int>seg[SIZE * 2];
	void add(int beg, int end, int node, int lb, int ub, int num)
	{
		if (ub < beg || end < lb)return;
		if (beg <= lb&&ub <= end)
		{
			seg[node].push_back(num);
			return;
		}
		add(beg, end, node * 2, lb, (lb + ub) / 2, num);
		add(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub, num);
	}
	void dfs(int node)
	{
		for (int i = 0; i < seg[node].size(); i++)
		{
			for (int j = 1; j <= 1000; j++)
			{
				cdp[j] = max(dp[node][j], cdp[j - 1]);
				if (j >= cst[seg[node][i]])cdp[j] = max(cdp[j], dp[node][j - cst[seg[node][i]]] + val[seg[node][i]]);
			}
			for (int j = 0; j <= 1000; j++)
			{
				dp[node][j] = cdp[j];
				cdp[j] = 0;
			}
		}
		if (node >= SIZE)return;
		for (int j = 0; j <= 1000; j++)
		{
			dp[node * 2][j] = dp[node * 2 + 1][j] = dp[node][j];
		}
		dfs(node * 2);
		dfs(node * 2 + 1);
	}
};
segtree tree;
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	for (int i = 0; i < num; i++)
	{
		scanf("%d%d", &val[i], &cst[i]);
		ord[i] = 0;
	}
	fill(fin, fin + 15000, SIZE - 1);
	int pt = num;
	int query;
	scanf("%d", &query);
	vector<int>que;
	for (int i = 0; i < query; i++)
	{
		int z;
		scanf("%d", &z);
		if (z == 1)
		{
			int za, zb;
			scanf("%d%d", &za, &zb);
			val[pt] = za;
			cst[pt] = zb;
			ord[pt] = i + 1;
			pt++;
		}
		if (z == 2)
		{
			int za;
			scanf("%d", &za);
			za--;
			fin[za] = i + 1;
		}
		if (z == 3)que.push_back(i + 1);
	}
	for (int i = 0; i < pt; i++)tree.add(ord[i], fin[i], 1, 0, SIZE - 1, i);
	tree.dfs(1);
	for (int i = 0; i < que.size(); i++)
	{
		ll now = 0;
		for (int j = gen; j >= 1; j--)
		{
			now *= base;
			now += dp[que[i] + SIZE][j];
			now %= mod;
		}
		printf("%I64d\n", now);
	}
}