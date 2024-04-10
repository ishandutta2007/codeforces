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

	string a, b;
	cin >> a >> b;
	int n = SZ(a);
	
	int f = 0, fb = 0;
	FOR(i, 0, n)
		if (a[i] == '4')
			++f;
	FOR(i, 0, n)
		if (b[i] == '4')
			++fb;

	int ans = abs(f - fb);

	if (f >= fb)
	{
		int s = f - fb;
		FOR(i, 0, n)
			if (!s)
				break;
			else
				if (a[i] != b[i])
				{
					if (a[i] == '4')
						a[i] = '7', --s;
				}
	}
	else
	{
		int s = fb - f;
		FOR(i, 0, n)
			if (!s)
				break;
			else
				if (a[i] != b[i])
				{
					if (a[i] == '7')
						a[i] = '4', --s;
				}
	}

	int C = 0;
	FOR(i, 0, n)
		if (a[i] != b[i])
			++C;

	ans += C / 2;
	cout << ans;
	cin >> n;
	return 0;
}