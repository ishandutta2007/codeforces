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

int n, q;
int color[100007];
bool prime[2*1000007];
int ans[100007];
vec < vec<int> > g;
vec <int> pr;
stack < pair<int, int> > st[2*1000007];

void getprime()
{
	prime[1] = true;
	form(i, 2, 2*1000007)
	{
		if (!prime[i])
		{
			pr.pb(i);
			for(ll j = (ll)2 * i; j <= (ll)2*1000007; j += (ll)i)
				prime[j] = true;
		}
	}
}

void dfs(int v, int pred, int h)
{
	vec <int> del;
	int val = color[v];
	int uk = 0;
	pair<int, int> ansv = mp(-1, -1);
	do
	{
		if (val == 1)
			break;
		if (!prime[val])
		{
			if (!st[val].empty())
			{
				if (ansv == mp(-1, -1))
					ansv = st[val].top();
				else
				{
					pair<int, int> q = st[val].top();
					if (h - ansv.YY > h - q.YY)
						ansv = q;
				}
			}
			st[val].push(mp(v, h));
			del.pb(val);
			break;
		}
		bool f = false;
		while (val % pr[uk] == 0)
		{
			int t = pr[uk];
			val /= t;
			if (!f)
			{
				f = true;
				if (!st[t].empty())
				{
					if (ansv == mp(-1, -1))
						ansv = st[t].top();
					else
					{
						pair<int, int> q = st[t].top();
						if (h - ansv.YY > h - q.YY)
							ansv = q;
					}
				}
				st[t].push(mp(v, h));
				del.pb(t);
			}
		}
		uk++;
	} while(1);
	ans[v] = ansv.XX;
	forn(i, g[v].size())
		if (g[v][i] != pred)
			dfs(g[v][i], v, h + 1);

	forn(i, del.size())
		st[del[i]].pop();
}

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	getprime();
	cin >> n >> q;
	g.resize(n);
	forn(i, n)
		cin >> color[i];
	forn(i, n - 1)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0, -1, 1);
	forn(i, q)
	{
		int x;
		cin >> x;
		if (x == 1)
		{
			int v;
			cin >> v;
			v--;
			if (ans[v] == -1)
			    cout << -1 << LN;
			else
		    	cout << ans[v] + 1 << LN;
		}
		else
		{
			int v, val;
			cin >> v >> val;
			v--;
			color[v] = val;
        	dfs(0, -1, 1);
		}
	}
}