#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 131072
class segtree
{
public:
	int seg[SIZE * 2];
	int flag[SIZE * 2];
	void update(int beg, int end, int node, int lb, int ub, int num)
	{
		if (ub<beg || end<lb)return;
		if (beg <= lb&&ub <= end)
		{
			seg[node] += num;
			flag[node] += num;
			return;
		}
		if (flag[node])
		{
			seg[node * 2] += flag[node];
			seg[node * 2 + 1] += flag[node];
			flag[node * 2] += flag[node];
			flag[node * 2 + 1] += flag[node];
			flag[node] = 0;
		}
		update(beg, end, node * 2, lb, (lb + ub) / 2, num);
		update(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub, num);
		seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
	}
	int get(int beg, int end, int node, int lb, int ub)
	{
		if (ub<beg || end<lb)return -1000000000000000000LL;
		if (beg <= lb&&ub <= end)
		{
			return seg[node];
		}
		if (flag[node])
		{
			seg[node * 2] += flag[node];
			seg[node * 2 + 1] += flag[node];
			flag[node * 2] += flag[node];
			flag[node * 2 + 1] += flag[node];
			flag[node] = 0;
		}
		return min(get(beg, end, node * 2, lb, (lb + ub) / 2), get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
segtree tree;
int dat[200000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int p = 0; p < num; p++)
	{
		int zt, za;
		scanf("%d%d", &zt, &za);
		if (za == 1)
		{
			int x;
			scanf("%d", &x);
			dat[zt] = x;
			tree.update(zt, SIZE - 1, 1, 0, SIZE - 1, 1);
		}
		else tree.update(zt, SIZE - 1, 1, 0, SIZE - 1, -1);
		int t = tree.get(num + 10, num + 10, 1, 0, SIZE - 1);
		if (tree.get(0, num + 10, 1, 0, SIZE - 1) >= t)
		{
			printf("-1\n");
			continue;
		}
		int beg = 0, end = num + 10;
		for (;;)
		{
			if (beg == end)break;
			int med = (beg + end + 1) / 2;
			if (tree.get(med, num + 10, 1, 0, SIZE - 1) < t)beg = med;
			else end = med - 1;
		}
		printf("%d\n", dat[beg + 1]);
	}
}