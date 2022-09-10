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
#include <cstring>
#include <stdio.h>
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
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

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-6;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 2e5 + 47;

int n;
int a[MAX];

void check(int g)
{
	bool ok = 1;

	int x;
	if (a[0] % g == 0)
		x = g;
	else
		x = a[0] % g;

	FOR(i, 0, n - 1)
	{
		if (abs(a[i] - a[i + 1]) <= 1)
		{
			if (a[i] > a[i + 1])
				--x;
			else
				++x;

			if (x <= 0 || x > g)
			{
				cout << "NO";
				exit(0);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];

	if (n == 1)
	{
		cout << "YES" << endl;
		cout << INF << " " << INF << endl;
		return 0;
	}

	VI diff;
	FOR(i, 0, n - 1)
	{
		if (a[i] == a[i + 1])
		{
			cout << "NO";
			return 0;
		}

		if (abs(a[i] - a[i + 1]) > 1)
			diff.push_back(abs(a[i] - a[i + 1]));
	}

	if (SZ(diff) == 0)
	{
		cout << "YES" << endl;
		cout << INF << " " << INF << endl;
		return 0;
	}

	int g = diff[0];
	FOR(i, 1, SZ(diff))
		if (diff[i] != g)
		{
			cout << "NO" << endl;
			return 0;
		}

	check(g);
	cout << "YES" << endl;
	cout << INF << " " << g << endl;
	cin >> n;
	return 0;
}