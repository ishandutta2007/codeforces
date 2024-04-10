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
int MOD = 1'000'000'007;
const int INF = 1e5;
const int MaXN = 150;
const int N = 1e5 + 22;
const int LOG = 25;
const int FACT = 120;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
typedef uint64_t ull;
uniform_int_distribution<ull> nextRand(0, (1LL << 62) - 1);
template<class A, class B>
void sum(A &a, B b)
{
	ll val = (a + b) % MOD;
	a = val;
}
ll add(ll a, ll b)
{
	ll val = (a + b) % MOD;
	return val;

}
int to_i(char c)
{
	return c - 'a';
}
ll mult(ll a, ll b) {
	ll val = a % MOD * b % MOD;
	return val % MOD;
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
#define int ll
const int Mx = 55;
const int Hf = Mx - 5;
const int sq = Mx * Mx;
int f[Mx], C[Mx][Mx];
int dp[sq], sm[sq];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, p, ans = 0;
	cin >> n >> p;
	MOD = p;
	f[0] = f[1] = 1;
	for (int i = 2; i < Mx; i++) f[i] = mult(f[i - 1], i);
	for (int i = 0; i < Mx; i++) C[i][0] = 1;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
		}
	}
	//cout << C[5][2] << " " << f[7] << "\n";
	dp[sq / 2] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sq; j++) {
			sm[j] = dp[j];
			if (j > 0) {
				sum(sm[j], sm[j - 1]);
			}
		}
		for (int j = Hf; j + Hf < sq; j++) {
			ll pref = sm[j - i - 1] - sm[j] + sm[j + i + 1];
			dp[j + 1] = add(dp[j] - sm[j], pref);
		}
		if (i != 0) {
			for (int j = -i; j < 0; j++) {
				ll l = mult(C[n][n - i - 1], f[n - i - 1]);
				ll r = sm[j + sq / 2 - 1];
				l = mult(l, i + j + 1);
				sum(ans, mult(l, r));
			}
		}
	}
	while (ans < 0) ans += MOD;
	cout << ans % MOD  << "\n";

}