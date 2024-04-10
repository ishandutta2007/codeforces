#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <unordered_map>
#include <complex>
#include <stdio.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PDD> VPDD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LD PI = acos(-1.0);
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL MAX = 2e5 + 7;
const LL MAXN = 1007;
const LL MAXM = 1e5;
const LD EPS = 1e-9;

int n;
int m;
string a[MAXN];
string ans[MAXN];
int used[MAXN][MAXN];
string memo[MAXN];
PII comp[MAXN * MAXN];
int counter = 0;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

inline bool check(PII& x)
{
	return (x.X >= 0 && x.X < n && x.Y >= 0 && x.Y < m && a[x.X][x.Y] == '.');
}

int color = 1;
stack<PII> s;
PII to;

inline void dfs(PII v)
{
	counter = 0;
	comp[counter++] = v;
	used[v.X][v.Y] = color;
	s.push(v);
	while (!s.empty())
	{
		v = s.top();
		s.pop();
		FOR(i, 0, 4)
		{
			to = MP(v.X + dx[i], v.Y + dy[i]);
			if (!check(to))
				continue;

			if (used[to.X][to.Y] == 0)
			{
				s.push(to);
				comp[counter++] = to;
				used[to.X][to.Y] = color;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	FOR(i, 0, n)
		cin >> a[i];

	FOR(i, 0, n)
		ans[i] = a[i];

	FOR(i, 0, n)
		memo[i].assign(m, '-');

	set<int> colors;
	PII cell, next;
	FOR(i,0,n)
		FOR(j,0,m)
		if (a[i][j] == '*')
		{
			ans[i][j] = 1;
			colors.clear();

			FOR(k, 0, 4)
			{
				next = MP(i + dx[k], j + dy[k]);
				if (!check(next) || colors.count(used[next.X][next.Y]))
					continue;

				if (memo[next.X][next.Y] == '-')
				{
					dfs(next);
					++color;
					ans[i][j] += counter % 10;
					
					FOR(i, 0, counter)
					{
						cell = comp[i];
						memo[cell.X][cell.Y] = counter % 10;
					}
				}
				else
					ans[i][j] += memo[next.X][next.Y];

				colors.insert(used[next.X][next.Y]);
			}

			ans[i][j] %= 10;
			ans[i][j] += '0';
		}

	FOR(i, 0, n)
		cout << ans[i] << endl;

	return 0;
}