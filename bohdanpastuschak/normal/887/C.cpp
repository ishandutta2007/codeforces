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

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL mod = 1000000007;
const LL INF = 1e9;
const LL LINF = 1e18 + 10;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	VS ans = {
		"111155223333224466554466",
		"111144223333664422555566",
		"114422225533434315156666",
		"115522224433414135356666",
		"111122553333442255666644",
		"111122443333446655226655",
		"212132326363444455556161",
		"616112122323444455556363",
		"121223233636444455551616",
		"161621213232444455553636",
		"551122223344141453536666",
		"441122223355343451516666"
	};

	int n = 24;
	VI a(n);
	FOR(i, 0, n)
		cin >> a[i];

	for (auto s : ans)
	{
		bool ok = 1;

		FOR(i, 0, n)
			FOR(j, i + 1, n)
			if (s[i] == s[j] && a[i] != a[j])
				ok = 0;
			else
				if (s[i] != s[j] && a[i] == a[j])
					ok = 0;

		if (ok)
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";	
	return 0;
}