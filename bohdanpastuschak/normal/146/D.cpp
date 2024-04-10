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

typedef long double LD;
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
const LL MAXN = 1e5 + 1;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string ans = "";

	if (c > a || c > b || d > a || d > b || abs(c - d) > 1)
	{
		cout << -1;
		return 0;
	}
	string ans1 = "";
	if (d > c)
	{
		FOR(i, 0, d)
			ans += "74";
	}
	else
	{
		if (c > d)
		{
			FOR(i, 0, c)
				ans += "47";
		}
		else
		{
			FOR(i, 0, c)
				ans += "47";
			ans += '4';

			FOR(i, 0, d)
				ans1 += "74";
			ans1 += '7';
		}
	}

	int ye1 = 0, ye2 = 0;
	FOR(i, 0, SZ(ans))
		if (ans[i] == '7')
			++ye2;
		else
			++ye1;

	a -= ye1;
	b -= ye2;

	if (a < 0 || b < 0)
	{
		a += ye1;
		b += ye2;
		ye1 = ye2 = 0;
		FOR(i, 0, SZ(ans1))
			if (ans1[i] == '4')
				++ye1;
			else
				++ye2;

		a -= ye1;
		b -= ye2;
		if (a < 0 || b < 0)
		{
			cout << -1;
			return 0;
		}
		else
			ans = ans1;
	}

	if (a)
	{
		int first = -1;
		FOR(i,0,SZ(ans))
			if (ans[i] == '4')
			{
				first = i;
				break;
			}

		if (first != -1)
		{
			string res;
			FOR(i, 0, first)
				res += ans[i];
			FOR(i, 0, a)
				res += '4';
			FOR(i, first, SZ(ans))
				res += ans[i];
			ans = res;
		}
		else
			throw - 1;
	}

	if (b)
	{
		int last = -1;
		FOR(i, 0, SZ(ans))
			if (ans[i] == '7')
				last = i;
		if (last == -1)
			throw - 1;
		else
		{
			string res;
			FOR(i, 0, last)
				res += ans[i];
			FOR(i, 0, b)
				res += '7';
			FOR(i, last, SZ(ans))
				res += ans[i];
			ans = res;
		}
	}




	cout << ans;
	cin >> a;
	return 0;
}