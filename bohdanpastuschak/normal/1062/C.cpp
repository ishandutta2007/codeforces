#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

const int MAX = 1 << 20;
string s;
int n, q;
int cnt1[MAX];

const int mod = 1e9 + 7;

int add(int x, int y)
{
	if (x + y < mod)
		return x + y;
	return x + y - mod;
}

int mult(int x, int y)
{
	return x * (LL)y % mod;
}

int power(int x, int y)
{
	int r = 1;
	while (y)
	{
		if (y & 1)
			r = mult(r, x);
		x = mult(x, x);
		y >>= 1;
	}

	return r;
}

int sum(int r)
{
	return power(2, r + 1) - 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> q >> s;
	cnt1[0] = s[0] == '1';
	FOR(i, 1, n)
		cnt1[i] = cnt1[i - 1] + (s[i] == '1');

	//cout << cnt1[3] << endl;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		--l; --r;
		int od = cnt1[r];
		if (l)
			od -= cnt1[l - 1];

		int zr = r - l + 1 - od;
		int ans = add(sum(r - l), mod - sum(zr - 1));
		cout << ans << endl;
	}

	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}