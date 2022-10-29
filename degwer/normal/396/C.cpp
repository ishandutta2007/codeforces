#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define S 300000//_
#define SIZE 1048576
typedef long long ll;
ll mod = 1000000007;
class segtree
{
public:
	ll seg[SIZE * 2];
	ll flag[SIZE * 2];
	ll cnt[SIZE * 2];
	void init(vector<bool>v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i])cnt[i + SIZE] = 1;
			else cnt[i + SIZE] = mod - 1;
		}
		for (int i = SIZE - 1; i >= 1; i--)cnt[i] = (cnt[i * 2] + cnt[i * 2 + 1]) % mod;
	}
	void update(int beg, int end, int node, int lb, int ub, ll num)
	{
		if (ub<beg || end<lb)return;
		if (beg <= lb&&ub <= end)
		{
			seg[node] += num * cnt[node];
			seg[node] %= mod;
			flag[node] += num;
			flag[node] %= mod;
			return;
		}
		if (flag[node])
		{
			seg[node * 2] += flag[node] * cnt[node * 2];
			seg[node * 2 + 1] += flag[node] * cnt[node * 2 + 1];
			seg[node * 2] %= mod;
			seg[node * 2 + 1] %= mod;
			flag[node * 2] += flag[node];
			flag[node * 2 + 1] += flag[node];
			flag[node * 2] %= mod;
			flag[node * 2 + 1] %= mod;
			flag[node] = 0;
		}
		update(beg, end, node * 2, lb, (lb + ub) / 2, num);
		update(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub, num);
		seg[node] = (seg[node * 2] + seg[node * 2 + 1]) % mod;
	}
	ll get(int beg, int end, int node, int lb, int ub)
	{
		if (ub<beg || end<lb)return 0;
		if (beg <= lb&&ub <= end)
		{
			return seg[node];
		}
		if (flag[node])
		{
			seg[node * 2] += flag[node] * cnt[node * 2];
			seg[node * 2 + 1] += flag[node] * cnt[node * 2 + 1];
			seg[node * 2] %= mod;
			seg[node * 2 + 1] %= mod;
			flag[node * 2] += flag[node];
			flag[node * 2 + 1] += flag[node];
			flag[node * 2] %= mod;
			flag[node * 2 + 1] %= mod;
			flag[node] = 0;
		}
		return (get(beg, end, node * 2, lb, (lb + ub) / 2) + get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub)) % mod;
	}
};
class FOREST
{
public:
	int num;//_
	vector<int>pat[S];
	vector<int>ko[S];
	int depth[S];//[
	int ord[S * 2];//ord
	int fin[S * 2];//fin 
	int rord[S * 2];//ordtz
	bool flag[S];
	int subsiz[S];//TCY
	int par[S];
	bool isroot[S];
	void adde(int s, int t)//s-t
	{
		pat[s].push_back(t);
		pat[t].push_back(s);
	}
	vector<bool>vd, vu;
	void initdfs(int node, int d)
	{
		if (flag[node])return;
		flag[node] = true;
		subsiz[node] = 1;
		rord[vd.size()] = node;
		ord[node] = vd.size();
		vd.push_back(true);
		vu.push_back(false);
		depth[node] = d;
		for (int i = 0; i < pat[node].size(); i++)
		{
			if (!flag[pat[node][i]])
			{
				initdfs(pat[node][i], d + 1);
				ko[node].push_back(pat[node][i]);
				subsiz[node] += subsiz[pat[node][i]];
				par[pat[node][i]] = node;
			}
		}
		fin[node] = vd.size();
		vu.push_back(true);
		vd.push_back(false);
	}
};
FOREST tree;
segtree t1;
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 1; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		tree.adde(i, z);
	}
	tree.initdfs(0, 0);
	t1.init(tree.vd);
	//for (int i = 0; i < num; i++)printf("%d %d\n", tree.ord[i],tree.fin[i]);
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		int za;
		scanf("%d", &za);
		if (za == 1)
		{
			int zb, zc, zd;
			scanf("%d%d%d", &zb, &zc, &zd);
			zb--;
			t1.update(tree.ord[zb], tree.ord[zb], 1, 0, SIZE - 1, zc);
			t1.update(tree.fin[zb], tree.fin[zb], 1, 0, SIZE - 1, zc);
			t1.update(tree.ord[zb] + 1, tree.fin[zb] - 1, 1, 0, SIZE - 1, mod - zd);
			//printf("%d %d\n", tree.ord[zb], tree.fin[zb]);
		}
		else
		{
			int z;
			scanf("%d", &z);
			z--;
			ll a = t1.get(0, tree.ord[z], 1, 0, SIZE - 1);
			printf("%I64d\n", a);
		}
	}
}