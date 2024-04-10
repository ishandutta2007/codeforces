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
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <tuple>
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
#define previous fake_previous
#define left fake_left
#define right fake_right

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LD PI = acos(-1.0);
const LL mod = 1000000007;
const LL INF = 1e18;
const LL MAXN = 100001;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n;
	cin >> n;

	VVI a(n, VI(6, 0));
	FOR(i, 0, n)
		FOR(j, 0, 6)
		cin >> a[i][j];

	bool ok = 0;
	FOR(i, 0, n)
		FOR(j, 0, 6)
		if (a[i][j] == 1)
			ok = 1;

	if (!ok)
	{
		cout << 0;
		return 0;
	}

	VVI num(10);
	FOR(i, 0, n)
		FOR(j, 0, 6)
		num[a[i][j]].push_back(i);

	FOR(x, 2, 1001)
	{
		if (x == 1000)
		{
			cout << 999;
			return 0;
		}
		ok = 0;

		VI dig;
		int t = x;
		while (t)
		{
			dig.push_back(t % 10);
			t /= 10;
		}

		if (SZ(dig) == 1)
		{
			if (SZ(num[dig[0]]))
				ok = 1;
		}
		else
		{
			if (SZ(dig) == 2)
			{
				for (auto i : num[dig[0]])
					for (auto j : num[dig[1]])
						if (i != j)
							ok = 1;
			}
			else
			{
				for (auto i : num[dig[0]])
					for (auto j : num[dig[1]])
						for(auto k: num[dig[2]])
						if (i != j && i != k && j != k)
							ok = 1;
			}
		}



		if (!ok)
		{
			cout << x - 1;
			return 0;
		}
	}
	
	return 0;
}