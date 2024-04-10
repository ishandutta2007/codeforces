#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define SIZE 32768
int mod;
int fib[100000];
int rfib[100000];
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
class segtree
{
public:
	int seg[SIZE * 2];
	int pl[SIZE * 2];
	int flag[SIZE * 2];
	void update(int beg, int end, int node, int lb, int ub, int n)
	{
		if (ub < beg || end < lb)return;
		if (beg <= lb&&ub <= end)
		{
			if (n == 1)
			{
				int t = pl[node];
				pl[node] = seg[node];
				seg[node] = (seg[node] + t) % mod;
				flag[node]++;
			}
			else
			{
				int t = seg[node];
				seg[node] = pl[node];
				pl[node] = (t + mod - pl[node]) % mod;
				flag[node]--;
			}
			return;
		}
		if (flag[node])
		{
			if (flag[node] > 0)
			{
				int a = seg[node * 2], b = pl[node * 2];
				seg[node * 2] = (a*fib[flag[node] + 1] + b*fib[flag[node]]) % mod;
				pl[node * 2] = (a*fib[flag[node]] + b*fib[flag[node] - 1]) % mod;
				a = seg[node * 2 + 1], b = pl[node * 2 + 1];
				seg[node * 2 + 1] = (a*fib[flag[node] + 1] + b*fib[flag[node]]) % mod;
				pl[node * 2 + 1] = (a*fib[flag[node]] + b*fib[flag[node] - 1]) % mod;
			}
			else
			{
				int a = seg[node * 2], b = pl[node * 2];
				seg[node * 2] = (a*rfib[-flag[node] - 1] + b*rfib[-flag[node]]) % mod;
				pl[node * 2] = (a*rfib[-flag[node]] + b*rfib[-flag[node] + 1]) % mod;
				a = seg[node * 2 + 1], b = pl[node * 2 + 1];
				seg[node * 2 + 1] = (a*rfib[-flag[node] - 1] + b*rfib[-flag[node]]) % mod;
				pl[node * 2 + 1] = (a*rfib[-flag[node]] + b*rfib[-flag[node] + 1]) % mod;
			}
			flag[node * 2] += flag[node];
			flag[node * 2 + 1] += flag[node];
			flag[node] = 0;
		}
		update(beg, end, node * 2, lb, (lb + ub) / 2, n);
		update(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub, n);
		seg[node] = (seg[node * 2] + seg[node * 2 + 1])%mod;
		pl[node] = (pl[node * 2] + pl[node * 2 + 1])%mod;
	}
	void add(int p, int node, int lb, int ub, int t1, int t2)
	{
		if (ub < p || p < lb)return;
		if (lb == ub)
		{
			seg[node] += t1;
			pl[node] += t2;
			seg[node] %= mod;
			pl[node] %= mod;
		//	printf("add %d %d %d\n", lb, t1, t2);
			return;
		}
		if (flag[node])
		{
			if (flag[node] > 0)
			{
				int a = seg[node * 2], b = pl[node * 2];
				seg[node * 2] = (a*fib[flag[node] + 1] + b*fib[flag[node]]) % mod;
				pl[node * 2] = (a*fib[flag[node]] + b*fib[flag[node] - 1]) % mod;
				a = seg[node * 2 + 1], b = pl[node * 2 + 1];
				seg[node * 2 + 1] = (a*fib[flag[node] + 1] + b*fib[flag[node]]) % mod;
				pl[node * 2 + 1] = (a*fib[flag[node]] + b*fib[flag[node] - 1]) % mod;
			}
			else
			{
				int a = seg[node * 2], b = pl[node * 2];
				seg[node * 2] = (a*rfib[-flag[node] - 1] + b*rfib[-flag[node]]) % mod;
				pl[node * 2] = (a*rfib[-flag[node]] + b*rfib[-flag[node] + 1]) % mod;
				a = seg[node * 2 + 1], b = pl[node * 2 + 1];
				seg[node * 2 + 1] = (a*rfib[-flag[node] - 1] + b*rfib[-flag[node]]) % mod;
				pl[node * 2 + 1] = (a*rfib[-flag[node]] + b*rfib[-flag[node] + 1]) % mod;
			}
			flag[node * 2] += flag[node];
			flag[node * 2 + 1] += flag[node];
			flag[node] = 0;
		}
		add(p, node * 2, lb, (lb + ub) / 2, t1, t2);
		add(p, node * 2 + 1, (lb + ub) / 2 + 1, ub, t1, t2);
		seg[node] = (seg[node * 2] + seg[node * 2 + 1]) % mod;
		pl[node] = (pl[node * 2] + pl[node * 2 + 1]) % mod;
		//printf("node: %d %d %d\n", node, seg[node], pl[node]);
	}
};
#define B 300
segtree tree;
BIT bi;
typedef pair<int, int>pii;
typedef pair<pii, pii>pi4;
int ans[30000];
int cnt[30000];
int main()
{
	int num;
	scanf("%d%d", &num, &mod);
	vector<int>vec;
	vector<int>zat;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
		zat.push_back(z);
	}
	sort(zat.begin(), zat.end());
	int query;
	scanf("%d", &query);
	vector<pi4>dat;
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		dat.push_back(make_pair(make_pair(zb / B, za), make_pair(zb, i)));
	}
	fib[1] = rfib[1] = 1;
	for (int i = 2; i < 50000; i++)
	{
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
		rfib[i] = (rfib[i - 2] + mod - rfib[i - 1]) % mod;
	}
	sort(dat.begin(), dat.end());
	int nl = 0, nr = -1;
	for (int i = 0; i < query; i++)
	{
		int beg = dat[i].first.second, end = dat[i].second.first, idx = dat[i].second.second;
		for (int p=0;;p++)
		{
			//printf("%d %d %d\n", nl, nr, tree.seg[1]);
			if (nl > beg)
			{
				nl--;
				int low = lower_bound(zat.begin(), zat.end(), vec[nl]) - zat.begin();
				if (cnt[low] == 0)
				{
					int t = bi.get(low);
					tree.add(low, 1, 0, SIZE - 1, vec[nl] % mod*fib[t + 1] % mod, vec[nl] % mod*fib[t] % mod);
					tree.update(low + 1, SIZE - 1, 1, 0, SIZE - 1, 1);
					bi.add(low, 1);
				}
				cnt[low]++;
			}
			else if (nr < end)
			{
				nr++;
				int low = lower_bound(zat.begin(), zat.end(), vec[nr]) - zat.begin();
				if (cnt[low] == 0)
				{
					int t = bi.get(low);
					tree.add(low, 1, 0, SIZE - 1, vec[nr] % mod*fib[t + 1] % mod, vec[nr] % mod*fib[t] % mod);
					tree.update(low + 1, SIZE - 1, 1, 0, SIZE - 1, 1);
					bi.add(low, 1);
				}
				cnt[low]++;
			}
			else if (nl < beg)
			{
				int low = lower_bound(zat.begin(), zat.end(), vec[nl]) - zat.begin();
				if (cnt[low] == 1)
				{
					int t = bi.get(low - 1);
					tree.add(low, 1, 0, SIZE - 1, (mod - vec[nl] % mod*fib[t + 1] % mod) % mod, (mod - vec[nl] % mod*fib[t] % mod) % mod);
					tree.update(low + 1, SIZE - 1, 1, 0, SIZE - 1, -1);
					bi.add(low, -1);
				}
				nl++;
				cnt[low]--;
			}
			else if (nr > end)
			{
				int low = lower_bound(zat.begin(), zat.end(), vec[nr]) - zat.begin();
				if (cnt[low] == 1)
				{
					int t = bi.get(low - 1);
					tree.add(low, 1, 0, SIZE - 1, (mod - vec[nr] % mod*fib[t + 1] % mod) % mod, (mod - vec[nr] % mod*fib[t] % mod) % mod);
					tree.update(low + 1, SIZE - 1, 1, 0, SIZE - 1, -1);
					bi.add(low, -1);
				}
				nr--;
				cnt[low]--;
			}
			else break;
		}
		ans[idx] = tree.seg[1];
	}
	for (int i = 0; i < query; i++)printf("%d\n", ans[i]);
}