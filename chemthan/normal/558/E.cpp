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
const int maxc = 30;
int n, q;
char s[maxn];
int st[maxc][4 * maxn];
int lz[maxc][4 * maxn];
int cnt[maxc];

void build(int c, int p, int L, int R) {
	if (L == R) {st[c][p] = (s[L] - 'a' == c ? 1 : 0); return;}
	build(c, p << 1, L, (L + R) / 2);
	build(c, (p << 1) + 1, (L + R) / 2 + 1, R);
	st[c][p] = st[c][p << 1] + st[c][(p << 1) + 1];
}

void update(int c, int p, int x, int y, int L, int R, int val) {
	if (lz[c][p] != -1) {
		st[c][p] = lz[c][p] * (R - L + 1);
		if (L < R) {
			lz[c][p << 1] = lz[c][p];
			lz[c][(p << 1) + 1] = lz[c][p];
		}
		lz[c][p] = -1;
	}
	if (x > R || y < L) return;
	if (x <= L && y >= R) {
		st[c][p] = val * (R - L + 1);
		if (L < R) {
			lz[c][p << 1] = val;
			lz[c][(p << 1) + 1] = val;
		}
		lz[c][p] = -1;
		return;
	}
	update(c, p << 1, x, y, L, (L + R) / 2, val);
	update(c, (p << 1) + 1, x, y, (L + R) / 2 + 1, R, val);
	st[c][p] = st[c][p << 1] + st[c][(p << 1) + 1];
}

int query(int c, int p, int x, int y, int L, int R) {
	if (lz[c][p] != -1) {
		st[c][p] = lz[c][p] * (R - L + 1);
		if (L < R) {
			lz[c][p << 1] = lz[c][p];
			lz[c][(p << 1) + 1] = lz[c][p];
		}
		lz[c][p] = -1;
	}
	if (x > R || y < L) return 0;
	if (x <= L && y >= R) return st[c][p];
	return query(c, p << 1, x, y, L, (L + R) / 2) + query(c, (p << 1) + 1, x, y, (L + R) / 2 + 1, R);
}

void get(int c, int p, int L, int R) {
	if (lz[c][p] != -1) {
		st[c][p] = lz[c][p] * (R - L + 1);
		if (L < R) {
			lz[c][p << 1] = lz[c][p];
			lz[c][(p << 1) + 1] = lz[c][p];
		}
		lz[c][p] = -1;
	}
	if (!st[c][p]) return;
	if (L == R)
	{
		s[L] = c + 'a';
		return;
	}
	get(c, p << 1, L, (L + R) / 2);
	get(c, (p << 1) + 1, (L + R) / 2 + 1, R);
}

void update(int L, int R, int k) {
	ms(cnt, 0);
	FOR(i, 0, maxc) cnt[i] = query(i, 1, L, R, 0, n - 1);
	int cur = 0;
	if (k) {
		FOR(i, 0, maxc) {
			if (!cnt[i]) continue;
			update(i, 1, L, R, 0, n - 1, 0);
			update(i, 1, L + cur, L + cur + cnt[i] - 1, 0, n - 1, 1);
			cur += cnt[i];
		}
	}
	else {
		FORd(i, maxc, 0) {
			if (!cnt[i]) continue;
			update(i, 1, L, R, 0, n - 1, 0);
			update(i, 1, L + cur, L + cur + cnt[i] - 1, 0, n - 1, 1);
			cur += cnt[i];
		}
	}
}

void solve() {
	ms(st, 0); ms(lz, -1);
	scanf("%d%d%s", &n, &q, s);
	FOR(i, 0, maxc) build(i, 1, 0, n - 1);
	while (q--) {
		int i, j, k; scanf("%d%d%d", &i, &j, &k); i--; j--;
		update(i, j, k);
	}
	FOR(i, 0, maxc) get(i, 1, 0, n - 1);
	printf("%s", s);
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