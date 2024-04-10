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

int cnt[256];

int get(string s, int n)
{
	FILL(cnt, 0);
	FOR(i, 0, SZ(s))
		cnt[s[i]]++;

	int ma = 0;
	FOR(i, 0, 256)
		ma = max(ma, cnt[i]);

	if (ma + n <= SZ(s))
		return ma + n;

	if (ma + n - SZ(s) > 1)
		return SZ(s);

	if (n == 1)
		return SZ(s) - 1;
	else
		return SZ(s);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n;
	cin >> n;
	string a, b, c;
	cin >> a >> b >> c;

	int x = get(a, n);
	int y = get(b, n);
	int z = get(c, n);

	if (x > max(y, z))
		cout << "Kuro";
	else
	{
		if (y > max(x, z))
			cout << "Shiro";
		else
		{
			if (z > max(x, y))
				cout << "Katie";
			else
				cout << "Draw";
		}
	}

	cin >> n;
	return 0;
}