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

#define FOR(i, a, b) for(LL i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const ULL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1007;

set<LL> ok1;
VLL ok;

LL get_root(LL n, int pw)
{
	LL x = pow(n, 1.0 / (pw + 0.0)) + 1;
	LL val = 1;
	REP(i, pw)
		val *= x;

	if (val <= n)
		return x;

	while (1)
	{
		--x;
		val = 1;
		REP(i, pw)
			val *= x;

		if (val <= n)
			return x;
	}
	throw - 1;
}

bool is(int n)
{
	for (int i = 2; i*i <= n; ++i)
		if (n%i == 0)
			return 0;
	return 1;
}

void generator()
{
	FOR(pw, 5, 63)
	{
		if (!is(pw))
			continue;
	
		LL val;
		int cnt = 0;
		int i = 1;
		while(1)
		{
			++i;
			val = 1;
			LL prev;
			cnt = 0;
			while (cnt < pw)
			{
				cnt++;
				prev = val;
				val *= i;
				if (val > LINF || val < prev || val < 0)
					break;				
			}

			if (val > LINF || val < prev || val < 0)
				break;
			
			LL sq = get_root(val, 2); 
			if (sq*sq == val)
				continue;
			
			sq = get_root(val, 3);
			if (sq*sq*sq == val)
				continue;

			ok1.insert(val);
		}
	}
}

int gcd(int x, int y)
{
	if (!y)
		return x;
	return gcd(y, x%y);
}

bool check(LL x)
{
	VI pw;
	for (LL i = 2; i*i <= x; ++i)
		if (x%i == 0)
		{
			int cnt = 0;
			while (x%i == 0)
				x /= i, ++cnt;
			pw.push_back(cnt);
		}

	if (SZ(pw) == 0)
		return 0;

	int g = pw[0];
	for (auto i : pw)
		g = gcd(g, i);

	return g > 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	/*LL x;
	while (cin >> x)
	{
		if (!check(x))
		{
			check(x);
			cout << "SUKA" << endl;
		}
	}
	return 0;*/
	generator();
	
	for (auto i : ok1)
	{
		//cout << i << endl;
		ok.push_back(i);
	}
	//return 0;
	//cout << SZ(ok) << endl;
	int q;
	cin >> q;
	LL l, r, ans;
	REP(Q, q)
	{
		ans = 0;
		cin >> l >> r;
		if (l == 1)
		{
			ans = 1;
			++l;
		}

		if (l > r)
		{
			cout << ans << endl;
			continue;
		}

		LL sq, sq2;
		sq = get_root(l, 2);
		if (sq*sq < l)
			++sq;
		sq2 = get_root(r, 2);
		ans += max(0LL, sq2 - sq + 1);
		
		sq = get_root(l, 3);
		if (sq*sq*sq < l)
			++sq;
		sq2 = get_root(r, 3);
		ans += max(0LL, sq2 - sq + 1);

		sq = get_root(l, 6);
		if (sq*sq*sq*sq*sq*sq < l)
			++sq;
		sq2 = get_root(r, 6);
		ans -= max(0LL, sq2 - sq + 1);

		auto it1 = lower_bound(ALL(ok), l);
		auto it2 = upper_bound(ALL(ok), r);
		
		if (it1 != it2)
			ans += abs(distance(it1, it2));

		cout << ans << endl;
	}

	return 0;
}