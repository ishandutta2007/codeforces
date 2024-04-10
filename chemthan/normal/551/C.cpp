#ifndef ONLINE_JUDGE
	#include <iostream>
#else
	#include <bits/stdc++.h>
#endif
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const nmax = 100010;
int n, m;
int a[nmax];
int curbox;
int bg;

void run(int cur, ll t) {
	int k = bg;
	while (k < n && a[k] == 0) k++;
	bg = k;
	if (k == n || k - cur >= t) return;
	t -= abs(cur - k);
	if (t <= a[k]) {a[k] -= t; curbox -= t; return;}
	t -= a[k]; curbox -= a[k]; a[k] = 0;
	run(k, t);
}

void solve() {
	scanf("%d%d", &n, &m);
	curbox = 0;
	FOR(i, 0, n) {scanf("%d", a + i); curbox += a[i];}
	ll l = 0, r = _I64_MAX;
	int curbuf = curbox;
	int abuf[nmax]; memcpy(abuf, a, n * sizeof(int));
	while (l < r) {
		curbox = curbuf;
		memcpy(a, abuf, n * sizeof(int));
		bg = 0;
		ll mid = (l + r) >> 1;
		FOR(i, 0, m) if (curbox) run(-1, mid);
		if (curbox == 0) r = mid; else l = mid + 1;
	}
	cout<<l;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}