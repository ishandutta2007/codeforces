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
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL mod = 1000000007;
const LL LINF = 1e18 + 10;
const LL MAXN = 5e5 + 7;

int q;
LL a[MAXN];
LD m[MAXN];
LL s[MAXN];
int n = 1;
LL last = 0;

inline LD f(int k)
{
	return (k * last - s[k] + 0.0) / (k + 1.0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> q;
	LL type, x;
	REP(Q, q)
	{
		cin >> type;
		if (type == 1)
		{
			cin >> x;
			a[n] = x;
			s[n] = s[n - 1] + x;
			last = x;
			++n;
		}
		else
		{
			if (n == 2)
			{
				cout << 0.00000 << endl;
				continue;
			}

			int L = 1, R = n - 2, M1, M2;
			while (R - L > 2)
			{
				M1 = L + (R - L) / 3;
				M2 = R - (R - L) / 3;
				if (f(M1) < f(M2))
					L = M1;
				else
					R = M2;
			}

			LD ans = f(L);
			for (int i = L + 1; i <= R; ++i)
				ans = max(ans, f(i));

			cout << fixed << setprecision(10) << ans << endl;
		}
	}
	
	return 0;
}