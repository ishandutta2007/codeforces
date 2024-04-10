#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 131072
class segtree
{
public:
	vector<int>seg[SIZE * 2];
	vector<int>merge(vector<int>a, vector<int>b)
	{
		vector<int>r;
		r.resize(60);
		for (int i = 0; i < a.size(); i++)r[i] = a[i] + b[(i + a[i]) % 60];
		return r;
	}
	void init(vector<int>v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			seg[i + SIZE].resize(60);
			for (int j = 0; j < 60; j++)
			{
				if (j%v[i] == 0)seg[i + SIZE][j] = 2;
				else seg[i + SIZE][j] = 1;
			}
		}
		for (int i = v.size(); i < SIZE; i++)seg[i + SIZE].resize(60);
		for (int i = SIZE - 1; i >= 1; i--)
		{
			seg[i] = merge(seg[i * 2], seg[i * 2 + 1]);
		}
	}
	void update(int a, int b)
	{
		a += SIZE;
		for (int i = 0; i < 60; i++)
		{
			if (i%b == 0)seg[a][i] = 2;
			else seg[a][i] = 1;
		}
		for (;;)
		{
			a /= 2;
			if (a == 0)break;
			seg[a] = merge(seg[a * 2], seg[a * 2 + 1]);
		}
	}
	vector<int>get(int beg, int end, int node, int lb, int ub)
	{
		if (beg <= lb&&ub <= end)
		{
			return seg[node];
		}
		if (end <= (lb + ub) / 2)return get(beg, end, node * 2, lb, (lb + ub) / 2);
		if ((lb + ub) / 2 + 1 <= beg)return get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub);
		return merge(get(beg, end, node * 2, lb, (lb + ub) / 2), get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
segtree tree;
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	tree.init(vec);
	int query;
	scanf("%d", &query);
	for (int i = 0; i < query; i++)
	{
		char za;
		int zb, zc;
		scanf(" %c%d%d", &za, &zb, &zc);
		if (za == 'C')
		{
			zb--;
			tree.update(zb, zc);
		}
		else
		{
			zb--;
			zc--;
			zc--;
			printf("%d\n", tree.get(zb, zc, 1, 0, SIZE - 1)[0]);
		}
	}
}