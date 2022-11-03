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

struct matr
{
	ll x11, x12, x21, x22;
	matr(){}
	matr(ll xx11, ll xx12, ll xx21, ll xx22)
	{
		x11 = xx11;
		x12 = xx12;
		x21 = xx21;
		x22 = xx22;
	}
};

ll a, b, n, x;

matr umn(matr &a, matr &b)
{
	matr kek;
	kek.x11 = ((a.x11 * b.x11) % MOD + (a.x12 * b.x21) % MOD) % MOD;
	kek.x12 = ((a.x11 * b.x12) % MOD + (a.x12 * b.x22) % MOD) % MOD;
	kek.x21 = ((a.x21 * b.x11) % MOD + (a.x22 * b.x21) % MOD) % MOD;
	kek.x22 = ((a.x21 * b.x12) % MOD + (a.x22 * b.x22) % MOD) % MOD;
	re kek;
}

matr binpow(matr &a, ll k)
{
	if (k == 1)
		re a;
	if (k & 1)
	{
		re umn(binpow(a, k - 1), a);
	}
	else
	{
		matr q = binpow(a, k / 2);
		re umn(q, q);
	}

}

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> a >> b >> n >> x;
	matr m = matr(a, b, 0, 1);
	m = binpow(m, n);
	cout << ((m.x11 * x) % MOD + m.x12) % MOD;
}