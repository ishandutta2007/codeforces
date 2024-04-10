#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//
#define read(x) scanf("%d", &x)
#define write(x) printf("%d", &x)
#define read2(x, y) scanf("%d %d", &x, &y)
//
#define sqr(x) x*x
#define clr(a, x) memset(a, x, sizeof(a));
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const int MAXN = 60007;
const ll MOD = 1e9 + 7;

int n, m;
bool  wascolor[100007], was[100007];
int color[100007], mycolor[100007];
vec < vec<int> > g;
vec <int> ans;
vec <int> t;

void dfs(int v)
{
	was[v] = true;
	forn(i, g[v].size())
		if (!was[g[v][i]])
			dfs(g[v][i]);
	t.pb(v);
}

void dfs2(int v, int color)
{
	mycolor[v] = color;
	forn(i, g[v].size())
		if (mycolor[g[v][i]] == -1)
			dfs2(g[v][i], color);
}

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n >> m;
	g.resize(n);
	forn(i, m)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(b);
	}
	forn(i, n)
	{
		cin >> color[i];
		color[i]--;
		wascolor[color[i]] = true;
	}
	forn(i, n)
		if (!was[i])
			dfs(i);
	forn(i, n)
		mycolor[i] = -1;
	forn(i, n)
		if (wascolor[t[i]])
		{
			dfs2(t[i], t[i]);
			ans.pb(t[i]);
		}
	forn(i, n)
		if (mycolor[i] != color[i])
		{
			cout << -1;
			exit(0);
		}
	cout << ans.size() << LN;
	forn(i, ans.size())
		cout << ans[i] + 1 << LN;
}