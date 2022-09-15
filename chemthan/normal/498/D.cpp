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
const int maxc = 60;
int n;
int a[maxn];
int st[maxc][4 * maxn];

void build(int node, int L, int R) {
	if (L == R) {
		FOR(i, 0, maxc) if (i % a[L] == 0) st[i][node] = 2; else st[i][node] = 1;
		return;
	}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
	FOR(i, 0, maxc) {
		int t = st[i][node << 1];
		if ((t + i) % a[((L + R) >> 1) + 1] == 0) t++;
		st[i][node] = t + st[(t + i) % maxc][(node << 1) + 1];
	}
}

void update(int node, int i, int L, int R, int val) {
	if (i < L || i > R) return;
	if (L == R) {
		FOR(i, 0, maxc) if (i % val == 0) st[i][node] = 2; else st[i][node] = 1;
		return;
	}
	update(node << 1, i, L, (L + R) >> 1, val);
	update((node << 1) + 1, i, ((L + R) >> 1) + 1, R, val);
	FOR(i, 0, maxc) {
		int t = st[i][node << 1];
		if ((t + i) % a[((L + R) >> 1) + 1] == 0) t++;
		st[i][node] = t + st[(t + i) % maxc][(node << 1) + 1];
	}
}

int query(int node, int t, int l, int r, int L, int R) {
	if (l > R || r < L) return 0;
	if (l <= L && r >= R) return st[t][node];
	int tmp = query(node << 1, t, l, r, L, (L + R) >> 1);
	return tmp + query((node << 1) + 1, (t + tmp) % maxc, l, r, ((L + R) >> 1) + 1, R);
}

void solve() {
	ms(st, 0);
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i);
	build(1, 0, n - 1);
	int q; scanf("%d", &q);
	while (q--) {
		char c[10]; int x, y; scanf("%s%d%d", c, &x, &y);
		if (c[0] == 'A') {
			x--; y -= 2;
			//cout<<x<<" "<<y<<endl;
			printf("%d\n", query(1, 0, x, y, 0, n - 1));
		}
		else {
			x--; a[x] = y;
			update(1, x, 0, n - 1, y);
		}
	}
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