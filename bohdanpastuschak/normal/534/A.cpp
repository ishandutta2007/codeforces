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
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
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
const LL LINF = 1e13;
const LL mod = 1e9 + 7;
const LL MAX = 1e5 + 47;

int ans[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n;
	cin >> n;
	int k = 0;
	if (n < 3)
	{
		k = 1;
		ans[0] = 1;
	}
	else
	{
		if (n == 3)
		{
			k = 2;
			ans[0] = 1;
			ans[1] = 3;
		}
		else
		{
			k = n;
			FOR(i, 0, n / 2)
				ans[i] = 2 * i + 2;
			FOR(i, n / 2, n)
				ans[i] = 2 * (i - n / 2) + 1;
		}
	}
	cout << k << endl;
	FOR(i, 0, k)
	{
		if (i)
			cout << " ";
		cout << ans[i];
	}

	return 0;
}