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
#define y0 asdfasdf3rcdt234d5c23xd234dx43
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const int MAXN = 60007;
const ll MOD = 1e9 + 7;

int n, k, ans = 1;
int a[6][1007], pos[6][1007];
int path[1007];
bool was[1007];

vec < vec<int> > g;

void dfs(int v)
{
	was[v] = true;
	forn(i, g[v].size())
	{
		int to = g[v][i];
		if (!was[to])
			dfs(to);
		path[v] = max(path[v], path[to] + 1);
	}
	path[v] = max(path[v], 1);
	ans = max(ans, path[v]);
}

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n >> k;
	g.resize(n + 2);
	forn(i, k)
		forn(j, n)
			scanf("%d", &a[i][j]);
	forn(i, k)
		forn(j, n)
			pos[i][a[i][j]] = j;
	form(i, 1, n)
		form(j, 1, n)
			if (i != j)
			{
				bool f = true;
				forn(t, k)
					if (pos[t][i] > pos[t][j])
						f = false;
				if (f)
					g[i].pb(j);
			}
	/*form(i, 1, n)
	{
		cout << i << ": ";
		forn(j, g[i].size())
			cout << g[i][j] << ' ';
		cout << LN;
	}*/
	form(i, 1, n)
		if (!was[i])
			dfs(i);
	cout << ans;
}