#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>calc(vector<int>vec)
{
	vector<int>ret;
	int now[30];
	fill(now, now + 30, 0);
	for (int i = 0; i < vec.size(); i++)
	{
		int t = vec[i];
		bool f = false;
		for (int j = 29; j >= 0; j--)
		{
			if (now[j] != 0 && (t&(1 << j)) != 0)
			{
				t ^= now[j];
			}
			if (now[j] == 0 && (t&(1 << j)) != 0)
			{
				now[j] = t;
				f = true;
				break;
			}
		}
		if (f)ret.push_back(vec[i]);
	}
	return ret;
}
#define SIZE 262144
class segtree
{
public:
	vector<int>seg[SIZE * 2];
	int flag[SIZE * 2];
	void init(vector<int>v)
	{
		for (int i = 0; i < v.size(); i++)seg[i + SIZE].push_back(v[i]);
		for (int i = SIZE - 1; i >= 1; i--)
		{
			vector<int>z;
			for (int j = 0; j < seg[i * 2].size(); j++)z.push_back(seg[i * 2][j]);
			for (int j = 0; j < seg[i * 2 + 1].size(); j++)z.push_back(seg[i * 2 + 1][j]);
			seg[i] = calc(z);
		}
	}
	void update(int beg, int end, int node, int lb, int ub, int num)
	{
		if (ub < beg || end < lb)return;
		if (beg <= lb&&ub <= end)
		{
			for (int i = 0; i < seg[node].size(); i++)seg[node][i] ^= num;
			flag[node] ^= num;
			return;
		}
		if (flag[node])
		{
			for (int i = 0; i < seg[node * 2].size(); i++)seg[node * 2][i] ^= flag[node];
			for (int i = 0; i < seg[node * 2 + 1].size(); i++)seg[node * 2 + 1][i] ^= flag[node];
			flag[node * 2] ^= flag[node];
			flag[node * 2 + 1] ^= flag[node];
			flag[node] = 0;
		}
		update(beg, end, node * 2, lb, (lb + ub) / 2, num);
		update(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub, num);
		vector<int>z;
		for (int i = 0; i < seg[node * 2].size(); i++)z.push_back(seg[node * 2][i]);
		for (int i = 0; i < seg[node * 2 + 1].size(); i++)z.push_back(seg[node * 2 + 1][i]);
		seg[node] = calc(z);
	}
	vector<int>get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)
		{
			vector<int>r;
			return r;
		}
		if (beg <= lb&&ub <= end)
		{
			return seg[node];
		}
		if (flag[node])
		{
			for (int i = 0; i < seg[node * 2].size(); i++)seg[node * 2][i] ^= flag[node];
			for (int i = 0; i < seg[node * 2 + 1].size(); i++)seg[node * 2 + 1][i] ^= flag[node];
			flag[node * 2] ^= flag[node];
			flag[node * 2 + 1] ^= flag[node];
			flag[node] = 0;
		}
		vector<int>va = get(beg, end, node*2, lb, (lb + ub) / 2);
		vector<int>vb = get(beg, end, node*2+1, (lb + ub) / 2 + 1, ub);
		for (int i = 0; i < vb.size(); i++)va.push_back(vb[i]);
		return calc(va);
	}
};
segtree tree;
class segtree2
{
public:
	int seg[SIZE * 2];
	void update(int beg, int end, int node, int lb, int ub, int num)
	{
		if (ub < beg || end < lb)return;
		if (beg <= lb&&ub <= end)
		{
			seg[node] ^= num;
			return;
		}
		update(beg, end, node * 2, lb, (lb + ub) / 2, num);
		update(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub, num);
	}
	int get(int pl, int node, int lb, int ub)
	{
		if (lb == ub)return seg[node];
		if (pl <= (lb + ub) / 2)return seg[node] ^ get(pl, node * 2, lb, (lb + ub) / 2);
		else return seg[node] ^ get(pl, node * 2 + 1, (lb + ub) / 2 + 1, ub);
	}
};
segtree2 tree2;
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	vector<int>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	for (int i = 0; i < num; i++)
	{
		tree2.update(i, i, 1, 0, SIZE - 1, vec[i]);
	}
	vector<int>v;
	v.push_back(0);
	for (int i = 0; i < num - 1; i++)v.push_back(vec[i] ^ vec[i + 1]);
	tree.init(v);
	for (int i = 0; i < query; i++)
	{
		int z;
		scanf("%d", &z);
		if (z == 1)
		{
			int za, zb, zc;
			scanf("%d%d%d", &za, &zb, &zc);
			za--;
			zb--;
			tree2.update(za, zb , 1, 0, SIZE - 1, zc);
			tree.update(za, za, 1, 0, SIZE - 1, zc);
			tree.update(zb + 1, zb + 1, 1, 0, SIZE - 1, zc);
		}
		else
		{
			int za, zb;
			scanf("%d%d", &za, &zb);
			za--;
			zb--;
			vector<int>zv = tree.get(za + 1, zb, 1, 0, SIZE - 1);
			zv.push_back(tree2.get(za, 1, 0, SIZE - 1));
			printf("%d\n", 1 << calc(zv).size());
		}
	}
}