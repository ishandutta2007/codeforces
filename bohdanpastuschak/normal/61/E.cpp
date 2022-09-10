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

int n;
LL t[MAX];
PII A[MAX];
PII a[MAX];
LL inv[MAX];

void add(int i, LL x)
{
	for (; i < n; i |= (i + 1))
		t[i] += x;
}

LL sum(int r)
{
	LL res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		res += t[r];
	return res;
}

LL sum(int l, int r)
{
	return sum(r) - sum(l - 1);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n;
	FOR(i, 0, n)
		cin >> A[i].X, A[i].Y = i;
	
	sort(A, A + n);
	FOR(i, 0, n)
		a[i].X = A[i].Y, a[i].Y = i;

	sort(a, a + n);

	FOR(i, 0, n)
	{
		int pos = a[i].Y;
		inv[pos] = sum(pos, n - 1);
		add(pos, 1);
	}

	FILL(t, 0);
	LL ans = 0;
	FOR(i, 0, n)
	{
		int pos = a[i].Y;
		ans += sum(pos, n - 1);
		add(pos, inv[pos]);
	}

	cout << ans;
	cin >> n;
	return 0;
}