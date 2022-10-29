#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 95542721;
#define SIZE 131072
class segtree
{
public:
	ll seg[SIZE * 2][48];
	int flag[SIZE * 2];
	void init(vector<ll>v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			seg[i + SIZE][0] = v[i] % mod;
			for (int j = 1; j < 48; j++)seg[i + SIZE][j] = seg[i + SIZE][j - 1] * seg[i + SIZE][j - 1] % mod*seg[i + SIZE][j - 1] % mod;
		}
		for (int i = SIZE - 1; i >= 1; i--)for (int j = 0; j < 48; j++)seg[i][j] = (seg[i * 2][j] + seg[i * 2 + 1][j]) % mod;
	}
	void rotate(int node, int t)
	{
		int d[48];
		for (int i = 0; i < 48; i++)d[i] = seg[node][(i + t) % 48];
		for (int i = 0; i < 48; i++)seg[node][i] = d[i];
	}
	void update(int beg, int end, int node, int lb, int ub)
	{
		if (end < lb || ub < beg)return;
		if (beg <= lb&&ub <= end)
		{
			flag[node]++;
			rotate(node, 1);
			return;
		}
		if (flag[node])
		{
			rotate(node * 2, flag[node]);
			rotate(node * 2 + 1, flag[node]);
			flag[node * 2] += flag[node];
			flag[node * 2 + 1] += flag[node];
			flag[node] = 0;
		}
		update(beg, end, node * 2, lb, (lb + ub) / 2), update(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub);
		for (int i = 0; i < 48; i++)seg[node][i] = (seg[node * 2][i] + seg[node * 2 + 1][i]) % mod;
	}
	ll get(int beg, int end, int node, int lb, int ub)
	{
		if (end < lb || ub < beg)return 0LL;
		if (beg <= lb&&ub <= end)return seg[node][0];
		if (flag[node])
		{
			rotate(node * 2, flag[node]);
			rotate(node * 2 + 1, flag[node]);
			flag[node * 2] += flag[node];
			flag[node * 2 + 1] += flag[node];
			flag[node] = 0;
		}
		return (get(beg, end, node * 2, lb, (lb + ub) / 2) + get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub)) % mod;
	}
};
segtree tree;
int main()
{
	int num;
	scanf("%d", &num);
	vector<ll>v;
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		v.push_back(z);
	}
	tree.init(v);
	int query;
	scanf("%d", &query);
	for (int i = 0; i < query; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		zb--, zc--;
		if (za == 1)printf("%I64d\n", tree.get(zb, zc, 1, 0, SIZE - 1));
		else tree.update(zb, zc, 1, 0, SIZE - 1);
	}
}