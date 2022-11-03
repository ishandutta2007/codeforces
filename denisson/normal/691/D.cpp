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
#include <stack>
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
#define mp make_pair
#define pb push_back
#define XX first
#define YY second
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
#define vec vector
#define all(a) a.begin(), a.end()
const str LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
     
const int MAXN = 60007;
const int P1 = 239017;
const int P2 = 353251;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

int n, m, c = 1;
int a[1000007];
int color[1000007];
int uk[1000007];
bool was[1000007];
vec<int> d[1000007];
vec<int> g[1000007];

void dfs(int v) {
	color[v] = c;
	was[v] = 1;
	forn(i, g[v].size()) {
		int to = g[v][i];
		if (!was[to])
			dfs(to);
	}
}

const bool is_testing = 0;
int main()
{
	srand(time(NULL));
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {

	}
	cin >> n >> m;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, m) {
		int a, b;
		
		cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	forn(i, n)
		if (!was[i])
			dfs(i), c++;	
	forn(i, n)
		d[color[i]].pb(a[i]);
	forn(i, n)
		if (d[i].size() > 1)
			sort(all(d[i])), reverse(all(d[i]));
	forn(i, n)
		printf("%d ", d[color[i]][uk[color[i]]++]);
	if (is_testing) {
		cout << LN << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}