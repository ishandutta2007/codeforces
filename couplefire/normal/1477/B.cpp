#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 200005
#define ll long long
int n, m, l[N], r[N], flg;
char a[N], b[N];
struct Node
{
	int len, sum;
}S[N << 2];
Node operator + (Node a, Node b)
{
	Node ret;
	ret.sum = a.sum + b.sum;
	ret.len = a.len + b.len;
	return ret;
}
int tag[N << 2];
void Build(int p, int l, int r)
{
	tag[p] = -1;
	if (l == r)
	{
		S[p] = {1, b[l] - '0'};
		return ;
	}
	int mid = (l + r) >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	S[p] = S[p << 1] + S[p << 1 | 1];
}
void Tag(int p, int x)
{
	if (!x)
		S[p].sum = 0;
	else
		S[p].sum = S[p].len;
	tag[p]=x;
}
void Pushdown(int p)
{
	if (~tag[p])
	{
		Tag(p << 1, tag[p]);
		Tag(p << 1 | 1, tag[p]);
		tag[p] = -1;
	}
}
void Modify(int p, int l, int r, int x, int y, int z)
{
	if (x <= l && y >= r)
	{
		Tag(p, z);
		return;
	}
	Pushdown(p);
	int mid = (l + r) >> 1;
	if (x <= mid)
		Modify(p << 1, l, mid, x, y, z);
	if (y > mid)
		Modify(p << 1 | 1, mid + 1, r, x, y, z);
	S[p] = S[p << 1] + S[p << 1 | 1];
}
Node Query(int p, int l, int r, int x, int y)
{
	if (x <= l && y >= r)
		return S[p];
	Pushdown(p);
	int mid = (l + r) >> 1;
	if (y <= mid)
		return Query(p << 1, l, mid, x, y);
	if (x > mid)
		return Query(p << 1 | 1, mid + 1, r, x, y);
	return Query(p << 1, l, mid, x, y) + Query(p << 1 | 1, mid + 1, r, x, y);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%s%s", &n, &m, a + 1, b + 1);
		for (int i = 1; i <= m; i++)
			scanf("%d%d", &l[i], &r[i]);
		Build(1, 1, n);
		flg = 1;
		for (int i = m; i >= 1; i--)
		{
			int s = Query(1, 1, n, l[i], r[i]).sum;
			if (s * 2 == r[i] - l[i] + 1)
			{
				flg = 0;
				break;
			}
			if (s * 2 > r[i] - l[i] + 1)
				Modify(1, 1, n, l[i], r[i], 1);
			else
				Modify(1, 1, n, l[i], r[i], 0);
		}
		for (int i = 1; i <= n; i++)
			if (Query(1, 1, n, i, i).sum != a[i] - '0')
				flg = 0;
		puts(flg ? "YES" : "NO");
	}
}