#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
#define SIZE 262144
class segtree
{
public:
	int seg[SIZE * 2];
	int idx[SIZE * 2];
	void init(vector<int>v)
	{
		for (int i = 0; i < v.size(); i++)seg[i + SIZE] = v[i];
		for (int i = v.size(); i < SIZE; i++)seg[i + SIZE] = 1000000000;
		for (int i = 0; i < SIZE; i++)idx[i + SIZE] = i;
		for (int i = SIZE - 1; i >= 1; i--)
		{
			seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
			if (seg[i * 2] < seg[i * 2 + 1])idx[i] = idx[i * 2];
			else idx[i] = idx[i * 2 + 1];
		}
	}
	pii get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return make_pair(1000000000, -1);
		if (beg <= lb&&ub <= end)
		{
			return make_pair(seg[node], idx[node]);
		}
		return min(get(beg, end, node * 2, lb, (lb + ub) / 2), get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
class segtree2
{
public:
	int seg[SIZE * 2];
	void update(int beg, int end, int node, int lb, int ub, int num)
	{
		if (ub < beg || end < lb)return;
		if (beg <= lb&&ub <= end)
		{
			seg[node] += num;
			return;
		}
		update(beg, end, node * 2, lb, (lb + ub) / 2, num);
		update(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub, num);
	}
	int get(int pl, int node, int lb, int ub)
	{
		if (lb == ub)return seg[node];
		if (pl <= (lb + ub) / 2)return seg[node] + get(pl, node * 2, lb, (lb + ub) / 2);
		else return seg[node] + get(pl, node * 2 + 1, (lb + ub) / 2 + 1, ub);
	}
};
segtree tree;
segtree2 tree2;
int main()
{
	int len, gen, num;
	scanf("%d%d%d", &len, &gen, &num);
	vector<pii>vec;
	vec.push_back(make_pair(0, 0));
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		vec.push_back(make_pair(za, zb));
	}
	sort(vec.begin(), vec.end());
	vec.push_back(make_pair(len, 0));
	vector<int>zv;
	for (int i = 0; i < vec.size(); i++)zv.push_back(vec[i].second);
	tree.init(zv);
	for (int i = 0; i < vec.size(); i++)tree2.update(i, i, 1, 0, SIZE - 1, gen - vec[i].first);
	int lb = 0;
	ll sum = 0;
	int now = gen;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		//printf("%d %d %d\n", vec[i].first, vec[i].second, now);
		if (vec[i + 1].first - vec[i].first>gen)
		{
			printf("-1\n");
			return 0;
		}
		for (;;)
		{
			if (now < (vec[i + 1].first - vec[i].first))
			{
				pii z = tree.get(lb, i, 1, 0, SIZE - 1);
				int t = min(vec[i + 1].first - vec[i].first - now, gen - tree2.get(z.second, 1, 0, SIZE - 1));
				if (t == 0)lb++;
				else
				{
					sum += (ll)z.first*(ll)t;
					tree2.update(z.second, SIZE - 1, 1, 0, SIZE - 1, t);
					now += t;
					//printf("aaa%d %d %d\n",z.first, z.second, t);
				}
			}
			else break;
		}
		now -= vec[i + 1].first - vec[i].first;
	}
	printf("%I64d\n", sum);
}