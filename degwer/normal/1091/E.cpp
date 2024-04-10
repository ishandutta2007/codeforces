#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 524288
typedef long long ll;
class segtree
{
public:
	ll seg[SIZE * 2];
	ll flag[SIZE * 2];
	void update(int beg, int end, int node, int lb, int ub, ll num)
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
	ll get()
	{
		return seg[1];
	}
};
segtree tree;
int d[505050];
ll imo1[505050], imo2[505050];
int main()
{
	int num;
	scanf("%d", &num);
	ll s = 0;
	for (int i = 0; i < num; i++)scanf("%d", &d[i + 2]), s += d[i + 2];
	num++;
	sort(d + 1, d + num + 1);
	reverse(d + 1, d + num + 1);
	for (int i = 1; i <= num; i++)
	{
		if (d[i] <= i - 1)imo1[d[i] + 1]++, imo2[i] += d[i];
		else imo1[i]++, imo2[i] += i - 1;
	}
	vector<ll>v;
	ll now = 0, pl = num;
	for (int i = 1; i <= num; i++)
	{
		pl -= imo1[i];
		now += pl;
		now -= imo2[i] + d[i];
		tree.update(i, i, 1, 0, SIZE - 1, (ll)i*(ll)(i - 1) + now);
		//printf(" %I64d\n", now + i*(i - 1));
	}
	int pt = num;
	d[0] = 1000000000;
	vector<ll>ans;
	for (int i = 0; i <= num; i++)
	{
		if (tree.get() >= 0 && (s + i) % 2 == 0)ans.push_back(i);
		for (;;)
		{
			if (d[pt] == d[pt - 1])pt--;
			else break;
		}
		tree.update(pt, num, 1, 0, SIZE - 1, -1);
		if (d[pt] < pt)tree.update(d[pt] + 1, pt - 1, 1, 0, SIZE - 1, 1);
		d[pt]++;
	}
	if (ans.empty())printf("-1\n");
	for (int i = 0; i < ans.size(); i++)printf("%I64d\n", ans[i]);
}