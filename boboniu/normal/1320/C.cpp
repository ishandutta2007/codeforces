#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
mt19937 rnd(random_device{}());

const int maxN = 1111111;
const int maxW = 1000001;
int n, m, q;

i64 costA[maxN], costB[maxN];
vector<array<int, 2>> monster[maxN];

i64 val[4 * maxN], tag[4 * maxN];

void update(int p)
{
	tag[p + p] += tag[p];
	val[p + p] += tag[p];
	tag[p + p + 1] += tag[p];
	val[p + p + 1] += tag[p];
	tag[p] = 0;
}

void build(int p, int l, int r)
{
	if (l == r)
		val[p] = -costB[l];
	else
	{
		int md = (l + r) >> 1;
		build(p * 2, l, md);
		build(p * 2 + 1, md + 1, r);
		val[p] = max(val[p + p], val[p + p + 1]);
	}
}

void add(int p, int l, int r, int x, int y, i64 v)
{
	if (y < l || x > r)
		return;
	if (x <= l && y >= r)
	{
		tag[p] += v;
		val[p] += v;
		return;
	}
	update(p);
	int mid = (l + r) / 2;
	add(p * 2, l, mid, x, y, v);
	add(p * 2 + 1, mid + 1, r, x, y, v);
	val[p] = max(val[p + p], val[p + p + 1]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= maxW; i++)
	{
		costA[i] = (1ll << 60);
		costB[i] = (1ll << 60);
	}
	for (int i = 0; i < n; i++)
	{
		i64 a, b;
		cin >> a >> b;
		costA[a] = min(costA[a], b);
	}
	for (int i = 0; i < m; i++)
	{
		i64 a, b;
		cin >> a >> b;
		costB[a] = min(costB[a], b);
	}
	build(1, 1, maxW);
	for (int i = 0; i < q; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		++a;
		++b;
		monster[a].push_back({b, c});
	}
	i64 ans = -(1ll << 60);
	for (int i = 1; i <= maxW; i++)
	{
		for (auto monst : monster[i])
		{
			add(1, 1, maxW, monst[0], maxW, monst[1]);
		}
		if (costA[i] != (1ll << 60))
		{
			ans = max(ans, val[1] - costA[i]);
		}
	}
	cout << ans << "\n";
}