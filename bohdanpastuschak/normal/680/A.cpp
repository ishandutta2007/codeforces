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

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define endl '\n'

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PDD> VPDD;

const LD PI = acos(-1.0);
const LL mod = 1000000007;
const LL INF = 1e18;
const LL MAXN = 100001;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	VI a(5);
	FOR(i, 0, 5)
		cin >> a[i];

	map<int, int> m;
	FOR(i, 0, 5)
		m[a[i]]++;

	int s = 0;
	FOR(i, 0, 5)
		s += a[i];


	int ans = s;
	for (auto i : m)
	{
		if (i.second >= 2)
		{
			ans = min(ans, s - 2 * i.first);
		}

		if (i.second >= 3)
			ans = min(ans, s - 3 * i.first);
	}
	cout << ans;

	return 0;
}