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
const LL MAX = 2e5 + 47;

char a[4][100];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n, k;
	cin >> n >> k;

	FOR(i, 0, 4)
		FOR(j, 0, n)
		a[i][j] = '.';

	
	cout << "YES" << endl;
	if (k % 2 == 0)
	{		
		FOR(j, 1, n - 1)
		{
			if (k)
			{
				k -= 2;
				a[1][j] = '#';
				a[2][j] = '#';
			}
		}

		FOR(i, 0, 4)
		{
			FOR(j, 0, n)
				cout << a[i][j];
			cout << endl;
		}


		cin >> n;
		return 0;
	}
		
	
	a[1][n / 2] = '#';
	--k;

	FOR(x, 1, n - 1)
	{
		if (n - 1 - x <= x)
			break;
		if (k)
		{
			k -= 2;
			a[1][x] = '#';
			a[1][n - 1 - x] = '#';
		}
	}

	FOR(x, 1, n - 1)
	{
		if (n - 1 - x <= x)
			break;
		if (k)
		{
			k -= 2;
			a[2][x] = '#';
			a[2][n - 1 - x] = '#';
		}
	}


	FOR(i, 0, 4)
	{
		FOR(j, 0, n)
			cout << a[i][j];
		cout << endl;
	}


	cin >> n;
	return 0;
}