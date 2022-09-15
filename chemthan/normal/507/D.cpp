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

const int maxn = 1010;
const int maxk = 110;
ll n, k, m;
ll f[maxn][maxk];
ll p1[maxn];
ll p2[maxn];

void build() {
	p1[0] = p2[0] = 1;
	FOR(i, 1, maxn) {p1[i] = p1[i - 1] * 10 % k; p2[i] = p2[i - 1] * 10 % m;}
}

void solve() {
	ms(f, 0);
	scanf("%I64d%I64d%I64d", &n, &k, &m);
	build();
	FOR(i, 1, 10) f[1][i % k]++;
	FOR(i, 1, n) FOR(j, 0, k) FOR(l, 0, 10) if (l * p1[i] % k != j) f[i + 1][j] = (f[i + 1][j] + f[i][(k + j - (l * p1[i] % k)) % k]) % m; else if (l) f[i + 1][j] = (f[i + 1][j] + 1) % m;
	ll ans = f[n][0] % m;
	FOR(i, 1, n) ans = (ans + f[i][0] * 9 * p2[n - i - 1]) % m;
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