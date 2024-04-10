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
#include <bitset>
#include <unordered_map>
#include <math.h>

using namespace std;

#define N 100500
#define M 20
#define F 450
mt19937 gen(time(NULL));
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornv(i, n) for (int i = n - 1; i >= 0; i--)
#define pii pair<int, int>
#define forlr(i, l, r) for (int i = l; i <= r; i++)
#define forlrv(i, l, r) for (int i = r; i >= l; i--)
#define read(x) scanf("%d", &x)
#define print(x) printf("%d ", x)
#define printl(x) printf("%d\n", x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
const long double eps = 1e-9;
const int inf = 1e9;
const int mod = 1e9 + 7;
const ll infinity = 2 * 1e18;
#define p p2
#define endl '\n'

int n, m;
int color[N];
vector<int> g[N];

map<int, int> mx[N];
map<int, int> f[N];
vector<pii> q[N];
int ans[N];

void upd(int j, int x, int val)
{
	for (int i = x; i <= n; i |= (i + 1))
		f[j][i] += val;
}

int get(int j, int x)
{
	int sum = 0;
	for (int i = min(n, x - 1); i >= 0; i = (i & (i + 1)) - 1)
		if (f[j].count(i))
			sum -= f[j][i];

	for (int i = n; i >= 0; i = (i & (i + 1)) - 1)
		if (f[j].count(i))
			sum += f[j][i];
	return sum;
}

int dfs(int u, int e)
{
	mx[u][color[u]]++;
	upd(u, 1, 1);
	vector<int> ret;
	ret.push_back(u);

	for (auto v : g[u])
		if (v != e)
			ret.push_back(dfs(v, u));

	int j = 0;
	for (auto v : ret)
		if (mx[v].size() >= mx[j].size())
			j = v;

	for (auto v : ret)
	{
		if (v == j) continue;
		for (auto x : mx[v])
		{
			if (mx[j][x.first] > 0)
				upd(j, mx[j][x.first], -1);
			mx[j][x.first] += x.second;
			upd(j, mx[j][x.first], 1);
		}
	}

	for (auto v : q[u])
		ans[v.second] = get(j, v.first);

	return j;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	cin >> n >> m;
	int u, v;
	forlr(i, 1, n) cin >> color[i];

	forn(i, n - 1)
	{
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}

	forn(i, m)
	{
		cin >> u >> v;
		q[u].push_back(mp(v, i));
	}

	dfs(1, 0);

	forn(i, m)
		cout << ans[i] << endl;
}