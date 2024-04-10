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

typedef double LD;
typedef long long LL;
typedef unsigned long long ULL;
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
const LD EPS = 1e-9;
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 1e18 + 10;
const LL MAX = 1501;
const int MAGIC = 1e6;

int n;
int m;
VS a;
PII s;
PII used[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	clock_t start = clock();
	cin >> n >> m;
	a.resize(n);
	FOR(i, 0, n)
		cin >> a[i];
	
	FOR(i, 0, n)
		FOR(j, 0, m)
		if (a[i][j] == 'S')
			s = MP(i, j);

	FOR(i, 0, n)
		FOR(j, 0, m)
		used[i][j] = MP(-1, -1);

	queue<PII> q;
	q.push(s);
	used[s.X][s.Y] = MP(s.X, s.Y);
	PII t, to;
	while (!q.empty())
	{
		to = q.front();
		q.pop();
		FOR(i, 0, 4)
		{
			t = MP(to.X + dx[i], to.Y + dy[i]);
			if (a[(t.X%n + n) % n][(t.Y% m + m)%m] == '#')
				continue;

			if (used[(t.X%n + n) % n][(t.Y% m + m) % m] == MP(t.X, t.Y))
				continue;

			if (used[(t.X%n + n) % n][(t.Y% m + m) % m] != MP(-1, -1))
			{
				cout << "Yes";
				return 0;
			}


			used[(t.X%n + n) % n][(t.Y% m + m) % m] = MP(t.X, t.Y);
			q.push(t);
		}
	}

	cout << "No";
	cin >> n;
	return 0;
}