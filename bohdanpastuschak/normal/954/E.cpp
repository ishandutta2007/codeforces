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
LL t;
PLL a[MAX];

int compar(PLL x, PLL y)
{
	return x.Y < y.Y;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> n >> t;
	FOR(i, 0, n)
		cin >> a[i].X;
	FOR(i, 0, n)
		cin >> a[i].Y;

	LD ans = 0;
	sort(a, a + n, compar);
	if (t < a[0].Y || t > a[n - 1].Y)
	{
		cout << fixed << setprecision(12) << ans << endl;
		cin >> n;
		return 0;
	}

	LL balance = 0;
	LD curr = 0;
	LL prev;

	FOR(i, 0, n)
	{
		balance += (t - a[i].Y) * a[i].X;
		if (balance >= 0)
		{
			curr += a[i].X;
			if (i == n - 1 && balance)
				curr = 0;

			continue;
		}

		prev = balance - (t - a[i].Y) *a[i].X;
		curr += (prev + 0.0) / (a[i].Y - t);
		break;
	}

	ans = max(ans, curr);
	curr = 0;
	balance = 0;
	prev = 0;

	RFOR(i, n, 0)
	{
		balance += (a[i].Y - t)*a[i].X;
		if (balance >= 0)
		{
			curr += a[i].X;
			if (i == 0 && balance)
				curr = 0;

			continue;
		}

		prev = balance - (a[i].Y - t) * a[i].X;
		curr += (prev + 0.0) / (t - a[i].Y);
		break;
	}

	ans = max(ans, curr);
	cout << fixed << setprecision(12) << ans << endl;
	cin >> n;
	return 0;

}