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
typedef  long long LL;
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
#define SZ(a) (LL)((a).size())

const LD PI = acos(-1.0);
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 1e19;
const LL MAX = 2e5 + 7;
const LL MAXN = 5e5;
const LL MAXA = 1e6 + 1;
const LD EPS = 1e-9;

int cmp(pair<PII, int> x, pair<PII, int> y)
{
	if (x.X.X == y.X.X)
		return x.Y < y.Y;
	return x.X.X < y.X.X;
}

void solve()
{
	int n;
	cin >> n;
	vector<pair<PII, int>> a(n);
	FOR(i, 0, n)
		cin >> a[i].X.X >> a[i].X.Y, a[i].Y = i;

	sort(ALL(a), cmp);
	VI ans(n, 0);

	int curr = 0;
	int ye = 0;
	int lastTime = 0;

	FOR(i, 0, n)
	{
		if (!ye)
			ans[a[i].Y] = a[i].X.X;
		else
		{
			if (ye + a[i].X.X <= a[i].X.Y)
				ans[a[i].Y] = a[i].X.X + ye;
		}
	}


	FOR(i, 0, n)
		cout << ans[i] << "  ";

	cout << endl;
}

int n;
VI a;
string s;
VCH used;
VI comp;

void dfs(int v, int color)
{
	comp[v] = color;
	if (v < SZ(s) && s[v] == '1')
		dfs(v + 1, color);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	int n;
	cin >> n;
	VI a(n);
	FOR(i, 0, n)
		cin >> a[i];

	cin >> s;
	comp.assign(n, 0);
	int cl = 1;
	FOR(i, 0, n)
		if (!comp[i])
			dfs(i, cl), cl++;
	
	VPII b(n);
	FOR(i, 0, n)
		b[i] = MP(a[i], i);

	sort(ALL(b));
	FOR(i, 0, n - 1)
		if (b[i].Y > b[i + 1].Y && comp[b[i].Y] != comp[b[i + 1].Y])
		{
			cout << "NO";
			return 0;
		}

	cout << "YES";
	cin >> n;	
	return 0;
}