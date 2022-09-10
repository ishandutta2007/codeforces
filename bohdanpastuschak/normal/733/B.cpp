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
const LL MAXN = 1e5 + 1;
const LD EPS = 1e-6;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	int n;
	cin >> n;
	VPII a(n);
	FOR(i, 0, n)
		cin >> a[i].X >> a[i].Y;

	int L = 0, R = 0;
	FOR(i, 0, n)
		L += a[i].X, R += a[i].Y;

	int B = abs(L - R);
	VI now(n);
	int l, r;
	FOR(i, 0, n)
	{
		l = L, r = R;
		L -= a[i].X;
		R -= a[i].Y;
		L += a[i].Y;
		R += a[i].X;
		now[i] = abs(R - L);
		L = l, R = r;
	}

	int ma = B;
	FOR(i, 0, n)
		ma = max(ma, now[i]);

	if (ma == B)
		cout << 0;
	else
	{
		FOR(i,0,n)
			if (ma == now[i])
			{
				cout << i + 1;
				return 0;
			}
	}


	/*
	int n, m;
	cin >> n >> m;
	VVCH a(n, VCH(m));
	FOR(i, 0, n)
		FOR(j, 0, m)
		cin >> a[i][j];

	bool x = 0, y = 0, z = 0;
	FOR(i, 0, n)
	{
		if (a[i][0] >= '0' && a[i][0] <= '9')
			x = 1;
		else
		{
			if (a[i][0] >= 'a' && a[i][0] <= 'z')
				y = 1;
			else
				z = 1;
		}
	}

	if (x && y && z)
	{
		cout << 0;
		return 0;
	}
		*/


	return 0;
}