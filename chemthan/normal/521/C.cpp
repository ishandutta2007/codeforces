#ifndef ONLINE_JUDGE
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef vector<pl> vll;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 100010;
const int mod = 1000000007;
int n, k;
char s[maxn];
ll sum[maxn];
ll f[maxn];
ll r[maxn];
ll p10[maxn];

//find x, y, d such that a * x + b * y = d, d = (a, b)
int x, y, d;
void Euclid(int a, int b) {
	if (b == 0) {x = 1; y = 0; d = a; return;}
	Euclid(b, a % b);
	int x1 = y;
	int y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}

ll ex(ll n, ll k) {
	if (k == 0) return 1;
	if (k % 2 == 1) return n * ex(n, k - 1) % mod;
	ll t = ex(n, k >> 1);
	return t * t % mod;
}

ll inv[maxn];
void makeinv() {
	inv[1] = 1;
	FOR(i, 2, maxn) inv[i] = (mod - ((mod / i) * inv[mod % i] % mod)) % mod;
}

void build() {
	p10[0] = 1;
	FOR(i, 1, maxn) p10[i] = p10[i - 1] * 10 % mod;
	makeinv();
	f[0] = 1;
	FOR(i, 1, maxn) f[i] = f[i - 1] * i % mod;
	r[0] = 1;
	FOR(i, 1, maxn) {
		r[i] = r[i - 1] * inv[i] % mod;
		//Euclid(f[i], mod);
		//r[i] = (mod + x) % mod;
		//r[i] = ex(f[i], mod - 2);
	}
}

ll combine(ll a, ll b) {
	if (a > b) return 0;
	if (a == 0 || a == b) return 1;
	return (f[b] * r[a] % mod) * r[b - a] % mod;
}

void solve() {
	build();
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	FOR(i, 0, n) {
		if (!i) sum[i] = s[i] - '0';
		else sum[i] = sum[i - 1] + s[i] - '0';
	}
	ll ans = 0;
	FOR(l, 0, n - 1) ans = (ans + (p10[l] * combine(k - 1, n - l - 2) % mod) * sum[n - l - 2]) % mod;
	FOR(i, 0, n) ans = (ans + ((s[i] - '0') * p10[n - i - 1] % mod) * combine(k, i)) % mod;
	printf("%I64d", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifndef ONLINE_JUDGE
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}