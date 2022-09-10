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
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<LL> VI;
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
const LL MAXN = 1e6 + 1;

int n;
int m;
VVCH f;
string s;
PII start;
PII finish;

bool check(PII& now, char d)
{
	if (d == 'L')
	{
		if (now.Y == 0)
			return 0;
		else
			now.Y--;
	}
	else
	{
		if (d == 'R')
		{
			if (now.Y == m - 1)
				return 0;
			else
				now.Y++;
		}
		else
		{
			if (d == 'U')
			{
				if (now.X == 0)
					return 0;
				else
					now.X--;
			}
			else
			{
				if (now.X == n - 1)
					return 0;
				else
					now.X++;				
			}
		}
	}

	if (f[now.X][now.Y] == '#')
		return 0;
	else
		return 1;
}

bool ok(string way)
{
	PII curr = start;
	FOR(i, 0, SZ(way))
	{
		if (!check(curr, way[i]))
			return 0;

		if (curr == finish)
			return 1;
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n >> m;
	f.assign(n, VCH(m));
	FOR(i, 0, n)
		FOR(j, 0, m)
		cin >> f[i][j];

	cin >> s;
	FOR(i, 0, n)
		FOR(j, 0, m)
		if (f[i][j] == 'E')
			finish = MP(i, j);

	FOR(i, 0, n)
		FOR(j, 0, m)
		if (f[i][j] == 'S')
			start = MP(i, j);

	int ans = 0;

	VCH vec = { 'L', 'R', 'U', 'D' };

	string way;
	FOR(i, 0, 24)
	{
		way.assign(SZ(s), 0);
		FOR(i, 0, SZ(s))
			way[i] = vec[s[i] - '0'];

		if (ok(way))
			++ans;// cout << way << endl;

		next_permutation(ALL(vec));
	}
		
	cout << ans;
	cin >> n;
	return 0;
}