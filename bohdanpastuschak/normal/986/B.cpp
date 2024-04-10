#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <cassert>
#include <string.h>
#include <cstdio>
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1 << 20;

int n;
int a[MAX];
PII b[MAX];

void petr()
{
	cout << "Petr" << endl;
	exit(0);
}

void umnik()
{
	cout << "Um_nik" << endl;
	exit(0);
}

int t[MAX];

inline void add(int i)
{
	for (; i < MAX; i |= (i + 1))
		t[i]++;
}

inline int sum(int r)
{
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		res += t[r];
	return res;
}

inline int sum(int l, int r)
{
	return sum(r) - sum(l - 1);
}

inline LL cnt()
{
	FILL(t, 0);
	FOR(i, 0, n)
		b[i] = MP(a[i], i);
	sort(b, b + n);

	LL ans = 0;

	FOR(i, 0, n)
	{
		ans += sum(b[i].Y, n - 1);
		add(b[i].Y);
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n;
	FOR(i, 0, n)
		a[i] = i + 1;

	FOR(i, 0, n)
		cin >> a[i];
	
	LL c3 = cnt();
	
	if (n & 1)
	{
		if (c3 & 1)
			petr();
		else
			umnik();
	}
	else
	{
		if (c3 & 1)
			umnik();
		else
			petr();
	}

	cin >> n;
	return 0;
}