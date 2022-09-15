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
const int maxm = 5010;
int n, m, k;
ll p;
ll h[maxn];
ll a[maxn];
ll b[maxn];
int t[maxm];

bool check(ll mid) {
	ll tot = 0;
	FOR(i, 0, n) if (b[i] > mid) tot += max(0LL, (b[i] - mid + p - 1) / p);
	if (tot > m * k) return false;
	ms(t, 0);
	FOR(i, 0, n) {
		ll end = b[i] - mid - h[i];
		for (ll j = end; j + h[i] > 0; j -= p) {
			if (j <= 0) t[0]++;
			else if (j > a[i] * (m - 1)) return false;
			else t[(j + a[i] - 1) / a[i]]++;
		}
	}
	int tmp = 0;
	FOR(i, 0, m) {
		tmp += t[i];
		tmp = max(0, tmp - k);
	}
	return tmp == 0;
}

void solve() {
	scanf("%d%d%d%I64d", &n, &m, &k, &p);
	FOR(i, 0, n) scanf("%I64d%I64d", h + i, a + i);
	FOR(i, 0, n) b[i] = h[i] + a[i] * m;
	ll l = 0, r = 1e18;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (!check(mid)) l = mid + 1; else r = mid;
	}
	printf("%I64d", l);
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