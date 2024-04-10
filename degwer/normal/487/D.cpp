#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#define SIZE 131072
class segtree
{
public:
	int seg[SIZE * 2][10];
	int e[4][4];//P
	int wid;
	void merge(int node)
	{
		for (int i = 0; i < wid; i++)
		{
			if (seg[node * 2 + 1][i] >= 0)seg[node][i] = seg[node * 2][seg[node * 2 + 1][i]];
			else seg[node][i] = seg[node * 2 + 1][i];
		}
	}
	void initv(int node, string s)//m[h
	{
		for (int i = 0; i < wid; i++)
		{
			int now = i;
			for (int t=0;;t++)
			{
				if (now < 0)
				{
					seg[node][i] = -node;
					break;
				}
				else if (now >= wid)
				{
					seg[node][i] = -node - SIZE;
					break;
				}
				else if (s[now] == '^')
				{
					seg[node][i] = now;
					break;
				}
				else if (s[now] == '<')now--;
				else now++;
				if (t > wid + 2)
				{
					seg[node][i] = -1;
					break;
				}
			}
		}
	}
	void init(vector<string>vec, int w)
	{
		wid = w;
		for (int i = 0; i < vec.size(); i++)initv(i + SIZE, vec[i]);
		string s;
		for (int i = 0; i < w; i++)s.push_back('^');
		for (int i = vec.size(); i < SIZE; i++)initv(i + SIZE, s);
		for (int i = SIZE - 1; i >= 1; i--)merge(i);
	}
	void update(int a, string s)
	{
		a += SIZE;
		initv(a, s);
		for (;;)
		{
			a >>= 1;
			merge(a);
			if (a == 1)break;
		}
	}
	int get(int beg, int end, int node, int lb, int ub, int now)
	{
		if (beg <= lb&&ub <= end)
		{
			if (now < 0)return now;
			else return seg[node][now];
		}
		if (end >= (lb + ub) / 2 + 1)
		{
			now = get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub, now);
		}
		if (beg <= (lb + ub) / 2)
		{
			now = get(beg, end, node * 2, lb, (lb + ub) / 2, now);
		}
		return now;
	}
};
segtree tree;
int main()
{
	int num, wid, query;
	scanf("%d%d%d", &num, &wid, &query);
	vector<string>vec;
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		vec.push_back(s);
	}
	tree.init(vec, wid);
	for (int p = 0; p < query; p++)
	{
		char za;
		scanf(" %c", &za);
		if (za == 'C')
		{
			int zb, zc;
			char zd;
			scanf("%d%d %c", &zb, &zc, &zd);
			zb--, zc--;
			vec[zb][zc] = zd;
			tree.update(zb, vec[zb]);
		}
		else
		{
			int zb, zc;
			scanf("%d%d", &zb, &zc);
			zb--, zc--;
			int r = tree.get(0, zb, 1, 0, SIZE - 1, zc);
			if (r >= 0)printf("0 %d\n", r + 1);
			else if (r == -1)printf("-1 -1\n");
			else if (-r < SIZE + SIZE)printf("%d 0\n", -r - SIZE + 1);
			else printf("%d %d\n", -r - SIZE - SIZE + 1, wid + 1);
		}
	}
}