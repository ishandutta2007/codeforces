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
const int N = 5e5 + 11;
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
//#define int ll
int a[N], f[N];
vector<int> par;
vector<int> gen(vector<int> &a)
{
	int n = a.size();
	vector<int> ans;
	int sm = 0;
	for (auto x : a) sm += x;
	if (sm % 2) return ans;
	sm /= 2;
	const int SZ = 1000 * 1000 + 228;
	bitset<SZ> bs[3];
	bs[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		bs[1] = bs[0] | (bs[0] << a[i]);
		bs[2] = (bs[1] ^ bs[0]);
		// find all positions of 1
		int fs = bs[2]._Find_first();
		for (int x = fs; x < SZ; )
		{
			par[x] = i;
			x = bs[2]._Find_next(x);
		}
		bs[0] = bs[1];
		bs[1] = bs[2] = 0;
	}
	if (bs[0][sm])
	{
		ans = a;
		while (sm > 0)
		{
		    ans[par[sm]] *= -1;
			sm -= a[par[sm]];
		}
	}
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		// No in case non-equal halves
		int h, l, u = 0, v = 0;
		cin >> h;
		vector<int> H(h);
		for (int i = 0; i < h; i++) cin >> H[i];
		cin >> l;
		if (h != l)
		{
		  	vector<int> L(l);
		for (int i = 0; i < l; i++) cin >> L[i];
			cout << "No\n";
			continue;
		}
		vector<int> L(l);
		for (int i = 0; i < l; i++) cin >> L[i];
		const int SZ = 1000 * 1000 + 228;
		par.resize(SZ, -228);
		vector<int> hh = gen(H);
		if (hh.size() == 0)
		{
			cout << "No\n";
			continue;
		}
		par.resize(SZ, -228);
		vector<int> Ll = gen(L);
		if (Ll.size() == 0)
		{
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		sort(Ll.begin(), Ll.end());
		sort(hh.begin(), hh.end());
		int shift = 0;
		while (hh[shift] < 0) shift++;
		reverse(Ll.begin(), Ll.begin() + shift);
		reverse(hh.begin() + shift, hh.end());
		//for (auto x : Ll) cout << x << " ";
		cout << "\n";
		for (int i = 0; i < 2 * h; i++)
		{
			cout << v << " " << u << "\n";
			if (i % 2) u += Ll[i / 2];
			else v += hh[i / 2];
		}

	}
	return 0;
}