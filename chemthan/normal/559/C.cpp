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

const int maxn = 2010;
const int maxc = 100010;
const int mod = 1000000007;
int h, w, n;
int d[maxn];
int f[2 * maxc];
int r[2 * maxc];
vii v;

ll ex(ll n, ll k) {
	if (k == 0) return 1;
	if (k % 2 == 1) return n * ex(n, k - 1) % mod;
	ll t = ex(n, k >> 1);
	return t * t % mod;
}

void build() {
	f[0] = 1; r[0] = 1;
	FOR(i, 1, 2 * maxc) {f[i] = 1LL * f[i - 1] * i % mod; r[i] = ex(f[i], mod - 2);}
}

ll cal(ll a, ll b) {
	if (a > b || a < 0) return 0;
	if (a == 0 || a == b) return 1;
	return (1LL * f[b] * r[a] % mod) * r[b - a] % mod;
}

void solve() {
	ms(d, 0); build();
	scanf("%d%d%d", &h, &w, &n);
	FOR(i, 0, n) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	v.push_back(make_pair(h - 1, w - 1));
	FOR(i, 0, sz(v)) d[i] = cal(v[i].first, v[i].first + v[i].second);
	FOR(i, 0, sz(v)) FOR(j, i + 1, sz(v)) d[j] = (d[j] - (1LL * d[i] * cal(v[j].first - v[i].first, v[j].first + v[j].second - v[i].first - v[i].second) % mod) + mod) % mod;
	printf("%d", d[sz(v) - 1]);
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