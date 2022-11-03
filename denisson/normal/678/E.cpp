#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//
#define read(x) scanf("%d", &x)
#define write(x) printf("%d", &x)
#define read2(x, y) scanf("%d %d", &x, &y)
//
#define sqr(x) x*x
#define clr(a, x) memset(a, x, sizeof(a));
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const int MAXN = 60007;
const ll MOD = 1e9 + 7;

int n;
db a[19][19];
db dp[1 << 19][19];

int get(int b)
{
	int ans = 0;
	forn(i, 20)
		if ((b >> i) & 1)
			ans++;
	re ans;
}

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n;
	forn(i, n)
		forn(j, n)
			cin >> a[i][j];
	if (n == 1)
		cout << 1, exit(0);
	n--;
	for (int mask = 1; mask < (1 << n); mask++)
		for (int i = 1; i <= n; i++)
		{		
			if (!((mask >> (i - 1)) & 1))
				continue;
			if (get(mask) == 1)
			{
				dp[mask][i] = a[0][i];
				continue;
			}
			for (int j = 1; j <= n; j++)
			{
				if (j == i || !( (mask >> (j - 1)) & 1 ))
					continue;
				dp[mask][i] = max(dp[mask][i], a[i][j] * dp[mask ^ (1 << (j - 1))][i] + a[j][i] * dp[mask ^ (1 << (i - 1))][j]);
			}
		}
	db ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[(1 << n) - 1][i]);
	cout.precision(7);
	cout << ans;
}