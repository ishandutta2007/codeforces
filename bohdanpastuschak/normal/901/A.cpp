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
const LL MAXN = 107;
const LL MAXP = 1e7 + 1;

int h;
VI a;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> h;
	a.assign(h + 1, 0);
	FOR(i, 0, h + 1)
		cin >> a[i];

	bool ok = 1;
	FOR(i, 0, h)
		if (a[i] > 1 && a[i + 1] > 1)
			ok = 0;

	if (ok)
	{
		cout << "perfect";
		return 0;
	}

	cout << "ambiguous" << endl;
	int moment = -1;
	FOR(i,0,h)
		if (a[i] > 1 && a[i + 1] > 1)
		{
			moment = i;
			break;
		}

	int vert = 0;
	FOR(i, 0, h + 1)
		vert += a[i];

	VI f(vert + 1), s(vert + 1);

	f[1] = s[1] = 0;
	
	int counter = 1;
	int old = 1;

	int hel;
	FOR(i, 1, h + 1)
	{
		if (a[i] == 1)
		{
			f[++counter] = old;
			old = counter;
		}
		else
		{
			hel = counter + 1;
			FOR(j, 0, a[i])
			{
				f[++counter] = old;
			}
			old = hel;
		}
	}

	counter = 1;
	old = 1;

	bool was = 0;
	FOR(i, 1, h + 1)
	{
		if (a[i] == 1)
		{
			s[++counter] = old;
			old = counter;
		}
		else
		{
			if (!was && (i != h && a[i + 1] > 1))
			{
				was = 1;
				hel = counter + 1;
				FOR(j, 0, a[i])
					s[++counter] = old;

				old = hel;
				FOR(j, 0, a[i + 1] - 1)
					s[++counter] = old;
				s[++counter] = old + 1;
				++i;
				old = counter - 1;
			}
			else
			{
				hel = counter + 1;
				FOR(j, 0, a[i])
				{
					s[++counter] = old;
				}
				old = hel;
			}
		}
	}

	FOR(i,1,SZ(f))
		cout << f[i] << " ";
	cout << endl;
	FOR(i, 1, SZ(s))
		cout << s[i] << " ";
	cout << endl;
	//cin >> h;
	return 0;
}