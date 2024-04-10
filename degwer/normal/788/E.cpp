#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 1000000000
#define SIZE 524288
typedef long long ll;
ll mod = 1000000007;
class segtree
{
public:
	int seg[SIZE * 2][6][6];
	ll e[6][6];//P
	ll now[6];
	void tim(int node)
	{
		ll x[6];
		fill(x, x + 6, 0);
		for (int i = 0; i < 6; i++)for (int j = i; j < 6; j++)x[j] += now[i] * seg[node][i][j];
		for (int i = 0; i < 6; i++)now[i] = x[i]%mod;
	}
	void merge(int node)
	{
		ll x[6][6];
		for (int i = 0; i < 6; i++)for (int j = 0; j < 6; j++)x[i][j] = 0;
		for (int i = 0; i < 6; i++)for (int j = i; j < 6; j++)for (int k = j; k < 6; k++)x[i][k] += (ll)seg[node * 2][i][j] * (ll)seg[node * 2 + 1][j][k];
		for (int i = 0; i < 6; i++)for (int j = i; j < 6; j++)seg[node][i][j] = x[i][j] % mod;
	}
	void initv(int node, int t)//m[h
	{
		for (int i = 0; i < 6; i++)for (int j = 0; j < 6; j++)seg[node][i][j] = e[i][j];
		if (t >= 0)seg[node][0][1] = seg[node][4][5] = t;
		else for (int i = 0; i < 5; i++)seg[node][i][i + 1]++;
	}
	void init(vector<ll>vec)
	{
		for (int i = 0; i < 6; i++)for (int j = 0; j < 6; j++)e[i][j] = (i == j);
		for (int i = 0; i < vec.size(); i++)initv(i + SIZE, vec[i]);
		for (int i = vec.size(); i < SIZE; i++)initv(i + SIZE, 0);
		for (int i = SIZE - 1; i >= 1; i--)merge(i);
	}
	void update(int a, int b)
	{
		a += SIZE;
		initv(a, b);
		for (;;)
		{
			a >>= 1;
			merge(a);
			if (a == 1)break;
		}
	}
	void get(int beg, int end, int node, int lb, int ub)
	{
		if (beg <= lb&&ub <= end)
		{
			tim(node);
			return;
		}
		if (beg <= (lb + ub) / 2)get(beg, end, node * 2, lb, (lb + ub) / 2);
		if ((lb + ub) / 2 + 1 <= end)get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub);
	}
	ll q(int beg, int end)
	{
		fill(now, now + 6, 0);
		now[0] = 1;
		get(beg, end, 1, 0, SIZE - 1);
		return now[5];
	}
};
segtree tree;
class BIT
{
public:
	int bit[SIZE + 1];
	void add(int a, int b)
	{
		a += 5;
		for (;;)
		{
			bit[a] += b;
			a += a&-a;
			if (a > SIZE)return;
		}
	}
	int get(int a)
	{
		a += 5;
		int ret = 0;
		for (;;)
		{
			ret += bit[a];
			a -= a&-a;
			if (a == 0)return ret;
		}
	}
};
BIT bi;
int dat[100000];
int zat[100000];
vector<int>now[100000];
int lb[100000];
int ub[100000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d", &dat[i]), zat[i] = dat[i];
	sort(zat, zat + num);
	for (int i = 0; i < num; i++)now[lower_bound(zat, zat + num, dat[i]) - zat].push_back(i);
	vector<ll>ret;
	for (int i = 0; i < num; i++)
	{
		lb[i] = ret.size();
		int bef = -1;
		for (int j = 0; j < now[i].size(); j++)
		{
			ret.push_back(bi.get(now[i][j]) - bi.get(bef));
			bef = now[i][j];
			ret.push_back(-1);
		}
		ret.push_back(bi.get(num) - bi.get(bef));
		for (int j = 0; j < now[i].size(); j++)bi.add(now[i][j], 1);
		ub[i] = int(ret.size()) - 1;
	}
	tree.init(ret);
	ll ans = 0;
	for (int i = 0; i < num; i++)ans += tree.q(lb[i], ub[i]);
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		zb--;
		int low = lower_bound(zat, zat + num, dat[zb]) - zat;
		int idx = lower_bound(now[low].begin(), now[low].end(), zb) - now[low].begin();
		ans -= tree.q(lb[low], ub[low]);
		if (za == 1)tree.update(lb[low] + idx * 2 + 1, 1);
		else tree.update(lb[low] + idx * 2 + 1, -1);
		ans += tree.q(lb[low], ub[low]);
		printf("%I64d\n", ans%mod);
	}
}