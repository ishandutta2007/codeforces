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
const int maxp = 60;
int n;
ll x[maxn];
ll y[maxn];
ld pw[maxn];
ld f[maxp];

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%I64d%I64d", x + i, y + i);
	pw[0] = 1; FOR(i, 1, maxn) pw[i] = pw[i - 1] * 0.5;
	FOR(i, 1, min(n, maxp)) f[i] = (1.0 - pw[n - i - 1]) / ((1LL << (i + 1)) - (n * n + n + 2) * pw[n - i]);
	ld ans = 0;
	FOR(j, 1, min(n - 1, maxp)) FOR(i, 0, n) {
		int k = (i + j) % n;
		ll d = gcd(abs(x[k] - x[i]), abs(y[k] - y[i]));
		ans += f[j] * (x[i] * y[k] - x[k] * y[i] - d);
	}
	cout<<fixed<<setprecision(9)<<ans / 2 + 1;
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