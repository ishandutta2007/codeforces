#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define SIZE 262144
typedef long long ll;
ll INF = 1000000000000000000LL;
class segtree
{
public:
	ll seg[SIZE * 2];
	ll flag[SIZE * 2];
	void init()
	{
		fill(seg, seg + SIZE * 2, INF);
	}
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
	ll get(int beg, int end, int node, int lb, int ub)
	{
		if (ub<beg || end<lb)return INF;
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
class BIT
{
public:
	int bit[SIZE + 1];
	void add(int a, int b)
	{
		a++;
		for (;;)
		{
			bit[a] += b;
			a += a&-a;
			if (a > SIZE)return;
		}
	}
	int get(int a)
	{
		a++;
		int ret = 0;
		for (;;)
		{
			ret += bit[a];
			a -= a&-a;
			if (a == 0)return ret;
		}
	}
};
segtree tree;
ll da[150000], db[150000];
int gen[150000];
typedef pair<ll, ll>pii;
BIT bi;
void add(int i)
{
	tree.update(da[i], SIZE - 1, 1, 0, SIZE - 1, -1);
	ll z = tree.get(da[i], da[i], 1, 0, SIZE - 1);
	int c = bi.get(da[i]);
	tree.update(da[i], da[i], 1, 0, SIZE - 1, -z + gen[i] - c);
	bi.add(da[i], 1);
}
void del(int i)
{
	tree.update(da[i], SIZE - 1, 1, 0, SIZE - 1, 1);
	ll z = tree.get(da[i], da[i], 1, 0, SIZE - 1);
	tree.update(da[i], da[i], 1, 0, SIZE - 1, -z + INF);
	bi.add(da[i], -1);
}
int main()
{
	int na, nb;
	ll hhh;
	scanf("%d%d%I64d", &na, &nb, &hhh);
	for (int i = 0; i < nb; i++)scanf("%I64d", &db[i]), db[i] = hhh - db[i];
	vector<pii>zat;
	for (int i = 0; i < na; i++)scanf("%I64d", &da[i]), zat.push_back(make_pair(da[i], i));
	sort(db, db + nb);
	sort(zat.begin(), zat.end());
	for (int i = 0; i < na; i++)
	{
		int low = lower_bound(zat.begin(), zat.end(), make_pair(da[i], (ll)i)) - zat.begin();
		gen[i] = upper_bound(db, db + nb, da[i]) - db - 1;
		da[i] = low;
	}
	tree.init();
	int ans = 0;
	for (int i = 0; i < nb; i++)add(i);
	for (int i = nb; i <= na; i++)
	{
		if (tree.get(0, SIZE - 1, 1, 0, SIZE - 1) >= 0)ans++;
		if (i != na)
		{
			add(i);
			del(i - nb);
		}
	}
	printf("%d\n", ans);
}