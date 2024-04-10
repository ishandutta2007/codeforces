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
#include <unordered_map>
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
const LL MAX = 2e5 + 7;
const LL MAXN = 20;
const LL MAXM = 1e5;
const LD EPS = 1e-9;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	string a, b;
	getline(cin, a);
	getline(cin, b);

	int sz = SZ(a);
	FOR(i, 0, SZ(a))
		if (a[i] == '0')
			--sz;
		else
			break;

	int sz2 = SZ(b);
	FOR(i, 0, SZ(b))
		if (b[i] == '0')
			--sz2;
		else
			break;

	string s, t;
	FOR(i, SZ(a) - sz, SZ(a))
		s += a[i];

	FOR(i, SZ(b) - sz2, SZ(b))
		t += b[i];

	if (SZ(s) > SZ(t))
		cout << ">";
	else
		if (SZ(s) < SZ(t))
			cout << "<";
		else
		{
			if (s == t)
				cout << "=";
			else
			{
				FOR(i, 0, SZ(s))
					if (s[i] > t[i])
					{
						cout << ">";
						break;
					}
					else
						if (s[i] < t[i])
						{
							cout << "<";
							break;
						}
			}
		}

	return 0;
}