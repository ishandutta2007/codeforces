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
using namespace std;
typedef unsigned long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define clr(a, n) memset(a, n, sizeof(a));
#define sqr(x) x*x
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 dsfgsdfgsdfgsdfgsdfgsdfg1
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;

const bool is_testing = 0;
//const int p = 997;
const int MOD = (int)1e9;
const int MOD2 = (int)1e9 + 11;
const int MAXN = (int)2e5 + 7;

int n, m;
vec < vec<int> > g;
bool f = false;
int color[100007];
bool was[100007];

void dfs(int v, int pred)
{
	if (was[v])
		return;
	color[v] = 1;
	was[v] = true;
	forn(i, g[v].size())
	{
		int to = g[v][i];
		if (color[to] == 1)
		{
			if (to != pred)
				f = true;
		}
		dfs(to, v);
	}
	color[v] = 2;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	//freopen("st2d.in", "r", stdin);
	//freopen("st2d.out", "w", stdout);
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n >> m;
	g.resize(n);
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	int ans = 0;
	forn(i, n)
		if (!was[i])
		{
			f = false;
			dfs(i, -1);
			if (!f)
				ans++;
		}
	cout << ans;
	//system("pause");			
	return 0;
}