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

int h, q;
vector<pair<ll, ll> > s, t, tmp;

void solve() {
	scanf("%d%d", &h, &q);
	ll mi = 1LL << (h - 1), ma = (mi << 1) - 1;
	while (q--) {
		ll i, L, R, ans; scanf("%I64d%I64d%I64d%I64d", &i, &L, &R, &ans);
		ll l = L << (h - i), r = ((R + 1) << (h - i)) - 1;
		if (ans == 1) {
			if (l > ma || r < mi) {printf("Game cheated!"); return;}
			mi = max(mi, l);
			ma = min(ma, r);
		}
		else s.push_back(make_pair(l, r));
	}
	sort(s.begin(), s.end());
	ll cur = mi - 1;
	FOR(i, 0, sz(s)) {
		if (s[i].first > ma) break;
		if (s[i].first > cur + 1) t.push_back(make_pair(cur + 1, s[i].first - 1));
		cur = max(cur, s[i].second);
	}
	if (ma > cur) t.push_back(make_pair(cur + 1, ma));
	if (mi > ma || sz(t) == 0) {printf("Game cheated!"); return;}
	else if (sz(t) > 1 || t[0].second - t[0].first > 0) {printf("Data not sufficient!"); return;}
	printf("%I64d", t[0].first);
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