#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <cstdio>
#include <functional>
#include <random>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <math.h>

using namespace std;

#define N 101500
#define M 12
mt19937 gen(time(NULL));
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornv(i, n) for (int i = n - 1; i >= 0; i--)
#define piii pair<int, pair<int, int>>
#define pii pair<int, int>
#define forlr(i, l, r) for (int i = l; i <= r; i++)
#define forlrv(i, l, r) for (int i = r; i >= l; i--)
#define bitupd(i, x, n) for (int i = x; i < n; i |= (i + 1))
#define bitsum(i, x) for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
#define mid(l, r) ((l + r) / 2)
#define stdsync() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define stdsort(a) sort(a.begin(), a.end())
#define read(x) scanf("%d", &x)
#define print(x) printf("%I64d ", x)
#define printl(x) printf("%d\n", x)
#define x(p) p.first
#define y(p) p.second
#define mp make_pair
#define mpp(a, b, c) mp(a, mp(b, c))
typedef long long ll;
typedef unsigned long long ull;
#define pll pair<ll, ll>
const double eps = 1e-9;
const int inf = 1e9;
const int mod = 1e9 + 7;
ull bit[N][M];
#define p p2
#define endl '\n'

int n, k;
int w[N];

map<int, int> st[N];
vector<int> g[N];
int cl[N];

ll ans[N];

pll dfs(int u, int e, int &t)
{
	vector<int> links;
	vector<pll> data;

	st[u][cl[u]]++;

	links.push_back(u);
	data.push_back(mp(cl[u], 1));

	for (auto v : g[u])
		if (v != e)
		{
			int x;
			data.push_back(dfs(v, u, x));
			links.push_back(x);
		}

	int j = 0;
	forn(i, links.size())
		if (st[links[i]].size() > st[links[j]].size())
			j = i;

	ll u_max = y(data[j]), u_sum = x(data[j]);

	forn(i, links.size())
	{
		if (i == j) continue;
		for (auto v : st[links[i]])
		{
			st[links[j]][v.first] += v.second;
			if (u_max == st[links[j]][v.first])
				u_sum += v.first;
			else if (u_max < st[links[j]][v.first])
				u_sum = v.first, u_max = st[links[j]][v.first];
		}
	}

	t = links[j];

	ans[u] = u_sum;

	return mp(u_sum, u_max);
}

int main()
{
	stdsync();
	cin >> n;
	forlr(i, 1, n) cin >> cl[i];
	int u, v;
	forn(i, n - 1)
	{
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}

	int x;
	dfs(1, 0, x);

	forlr(i, 1, n)
		print(ans[i]);
}