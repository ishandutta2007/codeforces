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
#include <unordered_set>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const LL INF = 1e6;
const LL LINF = 1e12;
const LL MAXN = 2e5 + 1;
const LD EPS = 1e-6;

int n;
int k;
VI a;

void bad()
{
	cout << "NO";
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> k >> n;
	a.resize(n);
	FOR(i, 0, n)
		cin >> a[i];

	int f = k, t = k * 2, o = 0;
	FOR(i,0,n)
		while (a[i] > 3 && f)
		{
			a[i] -= 4;
			--f;
		}

	FOR(i,0,n)
		while (a[i] > 3 && t)
		{
			t -= 2;
			a[i] -= 4;
		}

	int three = 0, two = 0, one = 0;
	FOR(i, 0, n)
	{
		if (a[i] > 3)
			bad();
		else
			if (a[i] == 3)
				++three;
			else
				if (a[i] == 2)
					++two;
				else
					if (a[i])
						++one;
	}

	if (f >= three)
	{
		f -= three;
		three = 0;		
	}
	else
	{
		three -= f;
		f = 0;
	}

	if (three)
	{
		if (t < three*2)
			bad();
		t -= three * 2;
	}

	if (t >= two)
	{
		t -= two;
		two = 0;
	}
	else
	{
		two -= t;
		t = 0;
	}

	if (f >= two)
	{
		f -= two;
		o += two;
		two = 0;
	}
	else
	{
		two -= f;
		o += f;
		f = 0;
	}

	if (two > 2 * o)
		bad();
	else
		o -= 2 * two;

	one -= 2 * f;
	one -= t;
	one -= o;
	if (one > 0)
		bad();
	else
		cout << "YES";

	cin >> n;
	return 0;
}