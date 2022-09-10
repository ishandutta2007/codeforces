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

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL mod = 1000000007;
const ULL MOD = 100055128505716009;
const LL INF = 1e9;
const LL LINF = 1e18 + 10;
const ULL MAX = -1;
const ULL PHI = (1ULL << 63);

ULL power(ULL x, ULL y)
{
	ULL res = 1;
	while (y)
	{
		if (y & 1)
			res *= x;

		x *= x;
		y >>= 1;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	int n, m, p;
	cin >> n >> m >> p;
	vector<ULL> a(n), b(m);
	FOR(i, 0, n)
		cin >> a[i];
	FOR(i, 0, m)
		cin >> b[i];

	ULL hashed = 1;
	for (auto i : b)
		hashed *= (2LL*i + mod);

	VI ans;
	FOR(rem, 0, p)
	{
		ULL now = 1;
		int cnt = 0;
		int last = rem;
		int first = rem;
		for (int i = rem; i < n; i += p)
		{
			++cnt;
			last = i;
			now *= (a[i] * 2LL + mod);
			if (cnt == m)
				break;
		}

		if (cnt == m)
		{
			if (now == hashed)
				ans.push_back(first);

			while (last + p < n)
			{
				last += p;
				now *= power(a[first] * 2LL + mod, PHI - 1);
				first += p;
				now *= (a[last]* 2LL + mod);

				if (now == hashed)
					ans.push_back(first);
			}
		}
		else
			continue;
	}


	sort(ALL(ans));
	cout << SZ(ans) << endl;
	for (auto i : ans)
		cout << i + 1 << " ";

	cin >> n;
	return 0;
}