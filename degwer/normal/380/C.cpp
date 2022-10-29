#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#define SIZE 1048576
typedef pair<int, int>pii;
class segtree
{
public:
	int seg[SIZE * 2], low[SIZE * 2];
	void init(string s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')seg[i + SIZE] = 1, low[i + SIZE] = 0;
			else seg[i + SIZE] = -1, low[i + SIZE] = -1;
		}
		for (int i = SIZE - 1; i >= 1; i--)
		{
			seg[i] = seg[i * 2] + seg[i * 2 + 1];
			low[i] = min(low[i * 2], seg[i * 2] + low[i * 2 + 1]);
		}
	}
	pii get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return make_pair(0, 0);
		if (beg <= lb&&ub <= end)return make_pair(seg[node], low[node]);
		pii a = get(beg, end, node * 2, lb, (lb + ub) / 2);
		pii b = get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub);
		return make_pair(a.first + b.first, min(a.second, a.first + b.second));
	}
};
segtree tree;
int main()
{
	string s;
	cin >> s;
	tree.init(s);
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pii z = tree.get(za, zb, 1, 0, SIZE - 1);
		int las = z.first - z.second;
		if (las < 0)printf("%d\n", zb - za + 1 + z.second + las);
		else printf("%d\n", zb - za + 1 + z.second - las);
	}
}