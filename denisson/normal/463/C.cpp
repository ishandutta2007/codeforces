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
#define y0 asdfasdf3rcdt234d5c23xd234dx43
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const int MAXN = 60007;
const ll MOD = 1e9 + 7;

int n;
pair<int, int> k1, k2, kek1, kek2;
int a[2007][2007];
ll sum[2007][2007];
ll d1[4007], d2[4007];

int get1(int x, int y)
{
	re x + y;
}

int get2(int x, int y)
{
	re x - y + n - 1;
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
	forn(i, n)
		forn(j, n)
			d1[get1(i, j)] += (ll)a[i][j];
	forn(i, n)
		forn(j, n)
			d2[get2(i, j)] += (ll)a[i][j];
	forn(i, n)
		forn(j, n)
			sum[i][j] = d1[get1(i, j)] + d2[get2(i, j)] - a[i][j];
	kek1 = mp(0, 0);
	kek2 = mp(0, 1);
	forn(i, n)
		forn(j, n)
			if (get1(i, j) % 2 == 0)
			{
				if (sum[kek1.XX][kek1.YY] < sum[i][j])
					kek1 = mp(i, j);
			}
			else
			{
				if (sum[kek2.XX][kek2.YY] < sum[i][j])
					kek2 = mp(i, j);

			}
	k1 = mp(0 ,0);
	k2 = mp(0, 1);
	forn(i, n)
		forn(j, n)
			if (get1(i, j) % 2 == 0)
			{
				if (sum[i][j] + sum[kek2.XX][kek2.YY] > sum[k1.XX][k1.YY] + sum[k2.XX][k2.YY] && mp(i, j) != kek2)
					k1 = mp(i, j), k2 = kek2;
			}
			else
			{
				if (sum[i][j] + sum[kek1.XX][kek1.YY] > sum[k1.XX][k1.YY] + sum[k2.XX][k2.YY] && mp(i, j) != kek1)
					k1 = mp(i, j), k2 = kek1;
			}
			
	cout << sum[k1.XX][k1.YY] + sum[k2.XX][k2.YY] << LN << k1.XX + 1 << ' ' << k1.YY + 1 << ' ' << k2.XX + 1 << ' ' << k2.YY + 1;
}