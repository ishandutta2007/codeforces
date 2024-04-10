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

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-6;
const LL INF = 1e9;
const LL mod = 1000000007;
const LL LINF = 1e18 + 10;
const LL MAX = 101;
const LL MAXN = 100;

bool ok1(char x, char y)
{
	if (x == y)
	{
		return x == 'o' || x == 'x' || x == 'v' || x == 'w' ||
			x == 'O' || x == 'I' || x == 'X' || x == 'V' || x == 'U' || x == 'W' || x == 'A' || x == 'Y' || x == 'T' || x == 'H' || x == 'M';
	}

	if (x == 'b' && y == 'd')
		return 1;

	if (x == 'd' && y == 'b')
		return 1;

	if (x == 'p' && y == 'q')
		return 1;

	if (x == 'q' && y == 'p')
		return 1;
	return 0;
}


int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	bool ok = 1;
	if (SZ(s) & 1)
	ok&= ok1(s[SZ(s)/2], s[SZ(s)/2]);
	FOR(i, 0, SZ(s)/2)
		if (!ok1(s[i], s[SZ(s) - 1 - i]))
			ok = 0;


	if (ok)
		cout << "TAK";
	else
		cout << "NIE";


	return 0;
}