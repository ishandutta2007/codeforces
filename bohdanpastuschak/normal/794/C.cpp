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
const LL MAXN = 8e4 + 1;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s, t;
	cin >> s >> t;
	int n = SZ(s);

	sort(ALL(s));
	sort(ALL(t));
	reverse(ALL(t));
	s.resize((n + 1) / 2);
	t.resize(n / 2);

	multiset<char> S(ALL(s));
	multiset<char> T(ALL(t));

	string ans(n, '0');
	int last = n - 1;
	int first = 0;
	int p1 = 0, p2 = 0;
	FOR(i, 0, n)
	{
		if (i & 1)
		{
			char sm = *S.begin();
			char lg = *T.rbegin();
			if (sm < lg)
			{
				ans[first++] = lg;
				T.erase(T.find(lg));
			}
			else
			{
				lg = *T.begin();
				T.erase(T.find(lg));
				ans[last--] = lg;
			}
		}
		else
		{
			if (!SZ(T))
			{
				ans[first++] = *S.begin();
				break;
			}

			char sm = *S.begin();
			char lg = *T.rbegin();
			if (sm < lg)
			{
				ans[first++] = sm;
				S.erase(S.find(sm));
			}
			else
			{
				sm = *S.rbegin();
				S.erase(S.find(sm));
				ans[last--] = sm;
			}
		}
	}

	cout << ans;
	cin >> n;
	return 0;
}