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
#include <bitset>
#include <complex>
#include <cassert>
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
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL LINF = 1e13;
const LL mod = 1e9 + 7;
const LL MAX = 3e5 + 47;

LL n;
PLL c[MAX];
LL x1, x2;
LL mc[MAX];
LL suf_max[MAX];

void check1()
{
	FOR(i, 0, n)
	{
		LL treba = (x1 + c[i].X - 1) / c[i].X;
		LL from = i + treba;
		if (from >= n)
			continue;

		if (suf_max[from] < x2)
			continue;

		cout << "Yes" << endl;
		VI r1, r2;
		FOR(j, i, from)
			r1.push_back(c[j].Y);
		
		int fr = -1;
		FOR(j, from, n)
		{
			if (mc[j] < x2)
				continue;

			fr = j;
			break;
		}

		FOR(j, fr, n)
			r2.push_back(c[j].Y);

		cout << SZ(r1) << " " << SZ(r2) << endl;
		FOR(j, 0, SZ(r1))
		{
			if (j)
				cout << " ";
			cout << r1[j];
		}
		cout << endl;
		
		FOR(j, 0, SZ(r2))
		{
			if (j)
				cout << " ";
			cout << r2[j];
		}
		cout << endl;
		exit(0);
	}
}

void check2()
{
	FOR(i, 0, n)
	{
		LL treba = (x2 + c[i].X - 1) / c[i].X;
		LL from = i + treba;
		if (from >= n)
			continue;

		if (suf_max[from] < x1)
			continue;

		cout << "Yes" << endl;
		VI r1, r2;
		FOR(j, i, from)
			r1.push_back(c[j].Y);

		int fr = -1;
		FOR(j, from, n)
		{
			if (mc[j] < x1)
				continue;

			fr = j;
			break;
		}

		FOR(j, fr, n)
			r2.push_back(c[j].Y);

		cout << SZ(r2) << " " << SZ(r1) << endl;
		FOR(j, 0, SZ(r2))
		{
			if (j)
				cout << " ";
			cout << r2[j];
		}
		cout << endl;

		FOR(j, 0, SZ(r1))
		{
			if (j)
				cout << " ";
			cout << r1[j];
		}
		cout << endl;
		exit(0);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> x1 >> x2;
	FOR(i, 0, n)
		cin >> c[i].X, c[i].Y = i + 1;

	sort(c, c + n);
	FOR(i, 0, n)
		mc[i] = c[i].X * (n - i);
	
	suf_max[n - 1] = mc[n - 1];
	RFOR(i, n - 1, 0)
		suf_max[i] = max(suf_max[i + 1], mc[i]);

	check1();
	check2();
	cout << "No" << endl;	
	cin >> n;
	return 0;
}