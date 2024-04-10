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

#define LD double
#define LL long long
#define PII pair<int, int>
#define PDD pair<LD, LD>
#define PLL pair<LL, LL>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define endl '\n'

#define FOR(i,a,b) for(LL i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(LL i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (LL)((a).size())

#define VI vector<int>
#define VLL vector<LL>
#define VCH vector<char>
#define VVI vector<VI>
#define VVLL vector<VLL>
#define VVCH vector<VCH>
#define VPII vector<PII>
#define VPLL vector<PLL>
#define VPDD vector<PDD>

const double PI = acos(-1.0);

const LL INF = 1e18;
const LL MAXN = 100000;

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

int main()
{
	int q;
	while (cin>>q)
	{
		vector<uint32_t> pos(100000), neg(100000);
		int L, R, k, t;
		REP(ii, q)
		{
			cin >> t;
			if (t == 1) {
				cin >> L >> R >> k;
				--L, --R;
				uint32_t *data = k > 0 ? pos.data() : neg.data();
				uint32_t b = abs(k) - 1;
				FOR(x, L, R)
				{
					auto a = data[x] - 1;
					data[x] = (a < b ? a : b) + 1;
				}
			}
			else if (t == 2) 
			{
				cin >> L >> R;
				--L, --R;
				LL ans = 0;
				FOR(x, L, R)
				{
					ans += (pos[x] + neg[x]) & ~(
						((int32_t)(pos[x] - 1) >> 31) |
						((int32_t)(neg[x] - 1) >> 31));
				}
				cout << ans << endl;
			}
			else return 0;
		}
	}
	return 0;
}