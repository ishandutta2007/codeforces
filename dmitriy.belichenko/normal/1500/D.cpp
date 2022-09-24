#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ins insert
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 998244353;
const int INF = 1e5;
const int MaXN = 150;
const int N = 5e6 + 11;
const int LOG = 25;
const int FACT = 120;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0, (ll)1e9);
template<class A, class B>
void sum(A &a, B b)
{
	a += b;
	if (a < 0LL) a += MOD;
	if (a >= MOD) a -= MOD;
}
ll add(ll a, ll b)
{
	a += b;
	if (a < 0) a += MOD;
	if (a >= MOD) a -= MOD;
	return a;

}
int to_i(char c)
{
	return c - 'a';
}
ll mult(ll a, ll b) {
	ll val = a * b - (ll)((ld)a * b / MOD) * MOD;
	if (val < 0) {
		val += MOD;
	}
	if (val >= MOD) {
		val -= MOD;
	}
	return val;
}
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll gcd_eu(ll a, ll b, ll & x, ll & y)
{
	if (a == 0)
	{
		x = 0LL; y = 1LL;
		return b;
	}
	ll x1, y1;
	ll d = gcd_eu(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
long long poww(long long a, long long b)
{
	long long val = 1;
	a %= MOD;
	while (b > 0)
	{
		if (b % 2) val = mult(a, val);
		a = mult(a, a);
		b >>= 1;
	}
	return val % MOD;
}
ll inv(ll a)
{
	return poww(a, MOD - 2);
}
int gcd(ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1 = 0, y1 = 0;
	ll d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
const int K = 1600;
const int P = 1600 * 1600;
int a[K][K];
int was[P], res[P];
pair<int, int> cp[K][K][12]; // ~3e7
int n, q;
vector<pair<int, int>> p;

void process_up(int row , int col)
{
	for (int i = 0; i < q + 1; i++)
	{
		if (cp[row - 1][col][i].fst || cp[row - 1][col][i].snd)
			p.pb({ cp[row - 1][col][i].fst + 1,  cp[row - 1][col][i].snd });
	}
}

void process_left(int row, int col)
{
	for (int i = 0; i < q + 1; i++)
	{
		if (cp[row][col - 1][i].fst || cp[row][col - 1][i].snd)
			p.pb({ cp[row][col - 1][i].fst + 1,  cp[row][col - 1][i].snd });
	}
}

void process_diag(int row, int col)
{
	for (int i = 0; i < q + 1; i++)
	{
		if (cp[row - 1][col - 1][i].fst || cp[row - 1][col - 1][i].snd)
			p.pb({ cp[row - 1][col - 1][i].fst + 1,  cp[row - 1][col - 1][i].snd });
	}
	sort(p.begin(), p.end());
}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	int ans = n * n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cur = 0;
			int mn = i + 1;
			p.clear();
			p.pb({ 1, a[i][j] });
			if (i > 0) process_up(i, j);
			if (j > 0) process_left(i, j);
			if (i > 0 && j > 0) process_diag(i, j);

			for (auto x : p)
			{
				if (cur > q) break;
				int ind = x.snd;
				if (!was[ind])
				{
					cp[i][j][cur] = x;
					cur++;
					was[ind] = 1;
				}
			}
			if (j < i) mn = j + 1;
			mn++;

			if (cp[i][j][q].fst || cp[i][j][q].snd)	mn = min(mn, cp[i][j][q].fst);

			res[mn]++;
			for (auto x : p)
			{
				int ind = x.snd;
				was[ind] = 0;
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		ans -= res[i];
		cout << ans << "\n";
	}
	return 0;
}