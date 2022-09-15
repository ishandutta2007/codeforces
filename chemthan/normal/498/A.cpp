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

const int maxn = 310;
ll X1, Y1, X2, Y2;
ll n;

void solve() {
	scanf("%I64d%I64d%I64d%I64d%I64d", &X1, &Y1, &X2, &Y2, &n);
	ll ans = 0;
	FOR(i, 0, n) {
		ll a, b, c;
		scanf("%I64d%I64d%I64d", &a, &b, &c);
		if (a * X1 + b * Y1 + c > 0 && a * X2 + b * Y2 + c < 0) ans++;
		if (a * X1 + b * Y1 + c < 0 && a * X2 + b * Y2 + c > 0) ans++;
	}
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