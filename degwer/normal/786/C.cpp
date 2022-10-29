#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
#define SIZE (1<<21)
class segtree
{
public:
	int seg[SIZE * 2];
	int flag[SIZE * 2];
	int idx[SIZE * 2];
	void init()
	{
		fill(seg + 1, seg + SIZE * 2, 1000000000);
		for (int i = 0; i < SIZE; i++)idx[SIZE + i] = i;
	}
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
		if (seg[node * 2] < seg[node * 2 + 1])idx[node] = idx[node * 2];
		else idx[node] = idx[node * 2 + 1];
	}
	pii get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return make_pair(1000000000, 1000000000);
		if (beg <= lb&&ub <= end)
		{
			return make_pair(seg[node], idx[node]);
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
int dat[100000];
int ans[100001];
int to[1 << 21];
int beg[1 << 21];
int bef[100000];
int now[100000];
int st[100000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d", &dat[i]), dat[i]--;
	tree.init();
	fill(now, now + num, -1);
	for (int i = 0; i < num; i++)
	{
		bef[i] = now[dat[i]];
		now[dat[i]] = i;
	}
	int pt = 0;
	for (int i = 1; i <= num; i++)tree.update(pt, pt, 1, 0, SIZE - 1, -tree.get(pt, pt, 1, 0, SIZE - 1).first + i - 1), beg[pt] = 0, ans[i]++, to[pt] = i, pt++;
	st[0] = 0;
	for (int i = 1; i < num; i++)
	{
		st[i] = pt;
		tree.update(st[bef[i] + 1], SIZE - 1, 1, 0, SIZE - 1, -1);
		//for (int j = 0; j < pt; j++)printf("%d ", tree.get(j, j, 1, 0, SIZE - 1).first); printf("\n");
		for (;;)
		{
			pii z = tree.get(0, SIZE - 1, 1, 0, SIZE - 1);
			//printf("%d %d %d\n", i, z.first, z.second);
			if (z.first >= 0)break;
			ans[to[z.second]]++;
			tree.update(z.second, z.second, 1, 0, SIZE - 1, 1000000000);
			beg[pt] = i;
			to[pt] = to[z.second];
			tree.update(pt, pt, 1, 0, SIZE - 1, -tree.get(pt, pt, 1, 0, SIZE - 1).first + to[z.second] - 1);
			pt++;
		}
	}
	for (int i = 1; i <= num; i++)printf("%d ", ans[i]); printf("\n");
}