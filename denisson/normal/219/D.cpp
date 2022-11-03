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
//
#define read(x) scanf("%d", &x)
#define write(x) printf("%d", x)
#define writeln(x) printf("%d\n", x)
#define wp(x) cout << x.first << ' ' << x.second << '\n';
#define wm(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' '; cout << LN;
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
const int P1 = 239017;
const int P2 = 353251;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const int l = 20;

int n, ans, ansnow;
vec <int> d;
vec < pair<int, bool> > g[200007];

int dfs(int v, int pred){
	int now = 0;
	forn(i, g[v].size()){
		int to = g[v][i].XX;
		int type = g[v][i].YY;
		if (to != pred){
			if (type == 1)
				now++;
			now += dfs(to, v);
		}
	}
	re now;
}
//k1 v
void dfs2(int v, int pred, int k1, int k2){
	if (ans + k1 - k2 < ansnow){
		ansnow = ans + k1 - k2;
		d.clear();
		d.pb(v);
	} else if (ans + k1 - k2 == ansnow)
		d.pb(v);
	forn(i, g[v].size()){
		int to = g[v][i].XX;
		int type = g[v][i].YY;
		if (pred != to){
			if (type)
				dfs2(to, v, k1, k2 + 1);
			else
				dfs2(to, v, k1 + 1, k2);
		}
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
	}
	cin >> n;
	forn(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(mp(b, 0));
		g[b].pb(mp(a, 1));
	}
	ans = dfs(0, -1);
	ansnow = ans;
	dfs2(0, -1, 0, 0);
	cout << ansnow << LN;
	sort(all(d));
	forn(i, d.size())
		cout << d[i] + 1 << ' ';
	if (is_testing){
		cout << LN << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}