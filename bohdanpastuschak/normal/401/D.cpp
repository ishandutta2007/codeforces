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
const LL MAXN = 5e3 + 1;

LL DP[1 << 18][100];
string s;
int m;
LL f[19];
int cnt[10];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> s >> m;
	f[0] = 1;
	FOR(i, 1, 19)
		f[i] = f[i - 1] * i;

	int n = SZ(s);
	DP[0][0] = 1;
	int TO = 1 << n;
	FOR(mask, 0, TO)
	{
		FOR(rem, 0, m)
		{
			if (DP[mask][rem])
			{
				FOR(j, 0, n)
				{
					if (mask == 0 && s[j] == '0')
						continue;
					if (mask & (1 << j))
						continue;

					DP[mask | (1 << j)][(rem*10 + s[j] - '0')%m] += DP[mask][rem];
				}
			}
		}
	}

	FOR(i, 0, n)
		cnt[s[i] - '0']++;

	LL ans = DP[(1 << n) - 1][0];
	
	FOR(i, 0, 10)
		ans /= f[cnt[i]];

	cout << ans;
	cin >> n; 
	return 0;
}