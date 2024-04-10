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

ll a, b, n;

ll cal(ll l, ll r, ll m) {
	return max(((r - l + 1) * a + b * (r + l - 2) * (r - l + 1) / 2 + m - 1) / m, a + (r - 1) * b);
}

void solve() {
	scanf("%I64d%I64d%I64d", &a, &b, &n);
	ll l, r, f, t, m;
	FOR(i, 0, n) {
		scanf("%I64d%I64d%I64d", &f, &t, &m);
		l = f; r = INT_MAX;
		while (l < r) {
			ll mid = (l + r + 1) >> 1;
			if (cal(f, mid, m) <= t) l = mid; else r = mid - 1;
		}
		if (cal(f, l, m) > t) printf("-1\n");
		else printf("%I64d\n", l);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}