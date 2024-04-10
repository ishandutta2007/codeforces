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
#include <complex>
#include <stdio.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
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
const LL LINF = 4e18;
const LL MAXN = 2e5 + 1;

VI dx = { 1, 0, 0, -1 };
VI dy = { 0, -1, 1, 0 };
int n, m, k;
VVCH a;
PII s;
VVI d;
VVCH used;
VI res;
int ye = 0;

void bfs()
{
	queue<PII> q;
	q.push(s);
	used[s.X][s.Y] = 1;
	d[s.X][s.Y] = 0;
	while (!q.empty())
	{
		PII t = q.front();
		q.pop();
		FOR(i,0,4)
			if (a[t.X + dx[i]][t.Y + dy[i]] != '*' && used[t.X + dx[i]][t.Y + dy[i]] == 0)
			{
				used[t.X + dx[i]][t.Y + dy[i]] = 1;
				q.push(MP(t.X + dx[i], t.Y + dy[i]));
				d[t.X + dx[i]][t.Y + dy[i]] = 1 + d[t.X][t.Y];
			}
	}
}

inline void solve(PII curr)
{
	int nazad = k - ye;
	if (nazad == 0)
		return;

	FOR(i,0,4)
		if (a[curr.X + dx[i]][curr.Y + dy[i]] != '*' && d[curr.X + dx[i]][curr.Y + dy[i]] <= nazad)
		{
			curr.X += dx[i];
			curr.Y += dy[i];
			res[ye] = i;
			++ye;
			solve(curr);
			return;
		}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n >> m >> k;
	a.assign(n + 2, VCH(m + 2, '*'));
	FOR(i, 0, n)
		FOR(j, 0, m)
		cin >> a[i + 1][j + 1];	
	FOR(i, 0, n)
		FOR(j, 0, m)
		if (a[i + 1][j + 1] == 'X')
			s = MP(i + 1, j + 1);

	res.assign(k, 0);
	d.assign(n + 2, VI(m + 2, INF));
	used.assign(n + 2, VCH(m + 2, 0));

	bfs();
	bool ok = 0;
	FOR(i,1, n + 1)
		FOR(j, 1, m + 1)
		if (d[i][j] < INF && d[i][j])
		{
			ok = 1;
			break;
		}

	if ((k & 1) || !ok)
	{
		cout << "IMPOSSIBLE";
		return 0;
	}
	solve(s);

	FOR(i, 0, SZ(res))
		if (res[i] == 0)
			cout << 'D';
		else
			if (res[i] == 1)
				cout << 'L';
			else
				if (res[i] == 2)
					cout << 'R';
				else
					cout << 'U';
	cin >> n;
	return 0;
}