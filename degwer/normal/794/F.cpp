#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 131072
typedef long long ll;
class segtree
{
public:
	ll seg[SIZE * 2][10];
	int flag[SIZE * 2][10];
	void init(vector<vector<ll> >vec)
	{
		for (int i = 0; i < vec.size(); i++)for (int j = 0; j < 10; j++)seg[i + SIZE][j] = vec[i][j];
		for (int i = SIZE - 1; i >= 1; i--)for (int j = 0; j < 10; j++)seg[i][j] = seg[i * 2][j] + seg[i * 2 + 1][j];
		for (int i = 1; i < SIZE * 2; i++)for (int j = 0; j < 10; j++)flag[i][j] = j;
	}
	void lazy(int node)
	{
		bool f = false;
		for (int i = 0; i < 10; i++)if (flag[node][i] != i)f = true;
		if (!f)return;
		ll d[10];
		for (int i = 0; i < 10; i++)d[i] = seg[node * 2][i];
		for (int i = 0; i < 10; i++)seg[node * 2][i] = 0;
		for (int i = 0; i < 10; i++)seg[node * 2][flag[node][i]] += d[i];
		for (int i = 0; i < 10; i++)d[i] = flag[node * 2][i];
		for (int i = 0; i < 10; i++)flag[node * 2][i] = flag[node][d[i]];
		for (int i = 0; i < 10; i++)d[i] = seg[node * 2 + 1][i];
		for (int i = 0; i < 10; i++)seg[node * 2 + 1][i] = 0;
		for (int i = 0; i < 10; i++)seg[node * 2 + 1][flag[node][i]] += d[i];
		for (int i = 0; i < 10; i++)d[i] = flag[node * 2 + 1][i];
		for (int i = 0; i < 10; i++)flag[node * 2 + 1][i] = flag[node][d[i]];
		for (int i = 0; i < 10; i++)flag[node][i] = i;
	}
	void update(int beg, int end, int node, int lb, int ub, int na, int nb)
	{
		if (ub<beg || end<lb)return;
		if (beg <= lb&&ub <= end)
		{
			seg[node][nb] += seg[node][na];
			seg[node][na] = 0;
			for (int i = 0; i < 10; i++)
			{
				if (flag[node][i] == na)flag[node][i] = nb;
			}
			return;
		}
		lazy(node);
		update(beg, end, node * 2, lb, (lb + ub) / 2, na, nb);
		update(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub, na, nb);
		for (int i = 0; i < 10; i++)seg[node][i] = seg[node * 2][i] + seg[node * 2 + 1][i];
	}
	ll get(int beg, int end, int node, int lb, int ub)
	{
		if (ub<beg || end<lb)return 0;
		if (beg <= lb&&ub <= end)
		{
			ll r = 0;
			for (int i = 0; i < 10; i++)r += seg[node][i] * i;
			return r;
		}
		lazy(node);
		return get(beg, end, node * 2, lb, (lb + ub) / 2) + get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub);
	}
};
segtree tree;
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	vector<vector<ll> >zv;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vector<ll>zzz;
		zzz.resize(10);
		ll t = 1;
		for (;;)
		{
			if (z == 0)break;
			zzz[z % 10] += t;
			t *= 10;
			z /= 10;
		}
		zv.push_back(zzz);
	}
	tree.init(zv);
	for (int p = 0; p < query; p++)
	{
		int z;
		scanf("%d", &z);
		if (z == 1)
		{
			int l, r, x, y;
			scanf("%d%d%d%d", &l, &r, &x, &y);
			l--, r--;
			if (x == y)continue;
			tree.update(l, r, 1, 0, SIZE - 1, x, y);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l--, r--;
			printf("%I64d\n", tree.get(l, r, 1, 0, SIZE - 1));
		}
	}
}