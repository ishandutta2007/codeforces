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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const LL INF = 2e9 + 1;
const LL LINF = 1e12;
const LL MAXN = 2e3 + 1;
const LD EPS = 1e-6;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	int n;
	cin >> n;
	string S, T;
	cin >> S >> T;

	map<int, int> s, t;
	FOR(i, 0, n)
		s[S[i] - '0']++, t[T[i] - '0']++;

	auto a = s;
	auto b = t;
	int ans = 0;

	int x;
	FOR(i, 0, n)
	{
		RFOR(j, 10, 0)
			if (s[j])
			{
				--s[j];
				x = j;
				break;
			}

		bool have = 0;
		FOR(j, x, 10)
			if (t[j])
			{
				--t[j];
				have = 1;
				break;
			}

		if (have)
			continue;
		
		FOR(j, 0, 10)
			if (t[j])
			{
				--t[j];
				++ans;
				break;
			}
	}

	cout << ans << endl;
	ans = 0;
	s = a;
	t = b;

	FOR(i, 0, n)
	{
		FOR(j, 0, 10)
			if (s[j])
			{
				--s[j];
				x = j;
				break;
			}

		bool have = 0;
		FOR(j, x + 1, 10)
			if (t[j])
			{
				--t[j];
				have = 1;
				++ans;
				break;
			}

		if (have)
			continue;

		FOR(j, 0, 10)
			if (t[j])
			{
				--t[j];
				break;
			}
	}


	cout << ans << endl;
	cin >> n;
	return 0;
}