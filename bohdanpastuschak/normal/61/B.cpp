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
#include <complex>
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

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-6;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 123456789;
const LL MAX = 1e6 + 47;

string get(string x)
{
	string res;
	FOR(i, 0, SZ(x))
	{
		if (x[i] >= 'A' && x[i] <= 'Z')
			x[i] =  (x[i] - 'A' + 'a');

		if (x[i] >= 'a' && x[i] <= 'z')
			res += x[i];
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	string a, b, c, s;
	cin >> a >> b >> c;
	a = get(a);
	b = get(b);
	c = get(c);

	string abc, acb, bac, bca, cab, cba;
	abc = a + b + c;
	acb = a + c + b;
	bac = b + a + c;
	bca = b + c + a;
	cab = c + a + b;
	cba = c + b + a;

	int n;
	cin >> n;
	bool ok;
	REP(q, n)
	{
		cin >> s;
		ok = 0;
		s = get(s);
		if (s == abc || s == acb || s == bca || s == bac || s == cab || s == cba)
			ok = 1;
		if (ok)
			cout << "ACC";
		else
			cout << "WA";
		cout << endl;
	}

	return 0;
}