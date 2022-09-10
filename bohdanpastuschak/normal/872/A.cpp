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
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
typedef unsigned long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PDD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<char> VCH;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define X first
#define Y second
#define MP make_pair

#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define FOR(i,a,b)  for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i= (b) - 1; i >= (a); --i)
#define REP(i, N) for(int i = 0; i < (N); ++i)

const LL MAXN = 1000001;
const LL INF = 1e9;
const LL mod = 1000000007;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	VI a(n), b(m);
	FOR(i, 0, n)
		cin >> a[i];
	FOR(i, 0, m)
		cin >> b[i];

	sort(ALL(a));
	sort(ALL(b));

	set<int> s(ALL(a)), t(ALL(b));

	FOR(i, 1, 10)
	{
		if (s.count(i) > 0 && t.count(i) > 0)
		{
			cout << i;
			return 0;
		}
	}

	int x = a[0], y = b[0];

	if (x > y)
		swap(x, y);

	cout << 10 * x + y;
	

	

	return 0;
}