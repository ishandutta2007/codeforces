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

#define FOR(i, a, b) for(LL i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e13;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1 << 20;

int n, k, m;
char banned[MAX];
int a[MAX];
int l[MAX];

LL get(int x)
{
	int r = 0, i = -1;
	int res = 0;
	while (r < n) 
	{
		if (l[r] <= i)
			return LINF;

		i = l[r];
		r = l[r] + x;
		++res;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> m >> k;
	int x;
	FOR(i, 0, m)
	{
		cin >> x;
		banned[x] = 1;
	}

	FOR(i, 0, k)
		cin >> a[i];

	FOR(i, 0, n)
	{
		if (banned[i] == 0)
		{
			l[i] = i;
			continue;
		}

		if (i)
			l[i] = l[i - 1];
		else
			l[i] = -1;
	}

	LL ans = LINF;
	FOR(i, 0, k)
	{
		LL t = get(i + 1);
		if (t == LINF)
			continue;

		ans = min(ans, t * a[i]);
	}

	if (ans == LINF)
		ans = -1;

	cout << ans << endl;
	cin >> n;
	return 0;
}