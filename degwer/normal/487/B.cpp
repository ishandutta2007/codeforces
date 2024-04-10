#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 262144
#define INF 2100000000000
typedef long long ll;
class segtree1
{
public:
	ll seg[SIZE * 2];
	void update(int a, ll b)
	{
		a += SIZE;
		seg[a] = b;
		for (;;)
		{
			a /= 2;
			if (a == 0)break;
			seg[a] = max(seg[a * 2], seg[a * 2 + 1]);
		}
	}
	ll get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return -INF;
		if (beg <= lb&&ub <= end)return seg[node];
		return max(get(beg, end, node * 2, lb, (lb + ub) / 2), get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
segtree1 mx;
class segtree2
{
public:
	ll seg[SIZE * 2];
	void update(int a, ll b)
	{
		a += SIZE;
		seg[a] = b;
		for (;;)
		{
			a /= 2;
			if (a == 0)break;
			seg[a] = min(seg[a * 2], seg[a * 2 + 1]);
		}
	}
	ll get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return INF;
		if (beg <= lb&&ub <= end)return seg[node];
		return min(get(beg, end, node * 2, lb, (lb + ub) / 2), get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
segtree2 mi;
segtree2 dp;
int main()
{
	int num, len;
	ll gen;
	scanf("%d%I64d%d", &num, &gen, &len);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		mx.update(i, z);
		mi.update(i, z);
	}
	int pt = 0;
	dp.update(0, 0);
	for (int i = 0; i < num; i++)
	{
		for (;;)
		{
			if (mx.get(pt, i, 1, 0, SIZE - 1) - mi.get(pt, i, 1, 0, SIZE - 1)>gen)pt++;
			else break;
		}
		ll t = dp.get(pt, i - len + 1, 1, 0, SIZE - 1);
		dp.update(i + 1, t + 1);
	}
	if (dp.get(num, num, 1, 0, SIZE - 1)>1000000000LL)printf("-1\n");
	else printf("%lld\n", dp.get(num, num, 1, 0, SIZE - 1));
}