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
const LL MAXN = 4e6 + 1;
const LL MAXS = 100 + 1;
const LL MAXT = 100 + 1;

bool comp(string x, string y)
{
	FOR(i, 0, SZ(x))
		if (x[i] > y[i])
			return 0;
		else
			if (x[i] < y[i])
				return 1;

	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	LL a, b;
	cin >> a >> b;

	string s, t;
	while (a)
	{
		s.push_back('0' + a % 10);
		a /= 10;
	}

	while (b)
	{
		t.push_back('0' + b % 10);
		b /= 10;
	}

	reverse(ALL(t));
	sort(ALL(s));
	reverse(ALL(s));

	if (SZ(s) < SZ(t))
	{
		for (auto i : s)
			cout << i;
		return 0;
	}

	multiset<char> ms(ALL(s));
	bool flag = 0;
	REP(q, SZ(s))
	{
		VCH all(ALL(ms));
		sort(ALL(all));
		reverse(ALL(all));
		if (flag)
		{
			for (auto i : all)
				cout << i;
			return 0;
		}

		FOR(i, 0, SZ(all))
		{
			bool can = 0;

			if (all[i] < t[q])
				can = 1, flag = 1;

			if (all[i] > t[q])
				continue;

			if (all[i] == t[q])
			{
				string x, y;
				FOR(j, 0, SZ(all))
					if (i != j)
						x += all[j];

				FOR(j, q + 1, SZ(t))
					y += t[j];

				sort(ALL(x));
				if (comp(x, y))
					can = 1;
			}

			if (can)
			{
				ms.erase(ms.find(all[i]));
				cout << all[i];
				break;
			}
		}
	}


	cin >> a;
	return 0;
}