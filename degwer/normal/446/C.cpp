#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000009;
#define SIZE 524288
ll fib[SIZE + 10];
ll rfib[SIZE + 10];
class segtree
{
public:
	ll seg[SIZE * 2];
	ll flag1[SIZE * 2];
	ll flag2[SIZE * 2];
	void init(vector<ll>v)
	{
		for (int i = 0; i < v.size(); i++)seg[i + SIZE] = v[i];
		for (int i = SIZE - 1; i >= 1; i--)seg[i] = (seg[i * 2] + seg[i * 2 + 1]) % mod;
	}
	void update(int beg, int end, int node, int lb, int ub, int n)
	{
		if (end < lb || ub < beg)return;
		if (beg <= lb&&ub <= end)
		{
			seg[node] += rfib[n + ub - lb + 1] - rfib[n] + mod;
			flag1[node] += fib[n];
			flag2[node] += fib[n + 1];
			seg[node] %= mod;
			flag1[node] %= mod;
			flag2[node] %= mod;
			return;
		}
		if (flag1[node] != 0 || flag2[node] != 0)
		{
			int t = (ub - lb + 1) / 2;
			ll a = flag1[node], b = flag2[node];
			seg[node * 2] += a*(rfib[t - 1] + 1) + b*(rfib[t]);
			seg[node * 2 + 1] += a*(rfib[t + t - 1] - rfib[t - 1] + mod) + b*(rfib[t + t] - rfib[t] + mod);
			flag1[node * 2] += a;
			flag2[node * 2] += b;
			flag1[node * 2 + 1] += a*fib[t - 1] + b*fib[t];
			flag2[node * 2 + 1] += a*fib[t] + b*fib[t + 1];
			seg[node * 2] %= mod;
			seg[node * 2 + 1] %= mod;
			flag1[node * 2] %= mod;
			flag1[node * 2 + 1] %= mod;
			flag2[node * 2] %= mod;
			flag2[node * 2 + 1] %= mod;
			flag1[node] = flag2[node] = 0;
		}
		update(beg, end, node * 2, lb, (lb + ub) / 2, n);
		update(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub, n + (ub - lb + 1) / 2);
		seg[node] = (seg[node * 2] + seg[node * 2 + 1]) % mod;
	}
	ll get(int beg, int end, int node, int lb, int ub)
	{
		if (end < lb || ub < beg)return 0LL;
		if (beg <= lb&&ub <= end)
		{
			return seg[node];
		}
		if (flag1[node] != 0 || flag2[node] != 0)
		{
			int t = (ub - lb + 1) / 2;
			ll a = flag1[node], b = flag2[node];
			seg[node * 2] += a*(rfib[t - 1] + 1) + b*(rfib[t]);
			seg[node * 2 + 1] += a*(rfib[t + t - 1] - rfib[t - 1] + mod) + b*(rfib[t + t] - rfib[t] + mod);
			flag1[node * 2] += a;
			flag2[node * 2] += b;
			flag1[node * 2 + 1] += a*fib[t - 1] + b*fib[t];
			flag2[node * 2 + 1] += a*fib[t] + b*fib[t + 1];
			seg[node * 2] %= mod;
			seg[node * 2 + 1] %= mod;
			flag1[node * 2] %= mod;
			flag1[node * 2 + 1] %= mod;
			flag2[node * 2] %= mod;
			flag2[node * 2 + 1] %= mod;
			flag1[node] = flag2[node] = 0;
		}
		return (get(beg, end, node * 2, lb, (lb + ub) / 2) + get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub)) % mod;
	}
};
segtree tree;
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	vector<ll>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	tree.init(v);
	fib[1] = 1;
	for (int i = 2; i < SIZE + 10; i++)fib[i] = (fib[i - 2] + fib[i - 1]) % mod;
	for (int i = 1; i < SIZE + 10; i++)rfib[i] = (rfib[i - 1] + fib[i - 1]) % mod;
	for (int p = 0; p < query; p++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		zb--;
		zc--;
		if (za == 1)
		{
			tree.update(zb, zc, 1, 0, SIZE - 1, -zb + 1);
		}
		else
		{
			printf("%I64d\n", tree.get(zb, zc, 1, 0, SIZE - 1));
		}
	}
}