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
const LL MAXN = 107;
const LL MAXP = 1e7 + 1;

int n;

VI multiply(VI p)
{
	VI res = { 0 };
	FOR(i, 0, SZ(p))
		res.push_back(p[i]);
	return res;
}

VI add(VI a, VI b)
{
	FOR(i, 0, SZ(b))
		a[i] += b[i];
	return a;
}

VI substr(VI a, VI b)
{
	FOR(i, 0, SZ(b))
		a[i] -= b[i];
	return a;
}

bool check(VI h)
{
	FOR(i, 0, SZ(h))
		if ((h[i] > 1) || (h[i] < -1))
			return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n;
	vector<VI> p(n + 1);
	vector<VI> q(n + 1);

	p[1] = { 0, 1 };
	q[1] = { 1 };

	VI h, w;
	FOR(i, 2, n + 1)
	{
		q[i] = p[i - 1];
		h = multiply(q[i]);
		h = add(h, q[i - 1]);
		if (check(h))
		{
			p[i] = h;
			continue;
		}
		else
		{
			h = substr(h, q[i - 1]);
			h = substr(h, q[i - 1]);

			if (check(h))
			{
				p[i] = h;
				continue;
			}
			else
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << n << endl;
	FOR(i, 0, n + 1)
		cout << p[n][i] << " ";

	cout << endl << n - 1 << endl;
	FOR(i, 0, n)
		cout << q[n][i] << " ";
	//cin >> n;
	return 0;
}