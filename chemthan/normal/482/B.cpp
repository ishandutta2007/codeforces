#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 100010;
int n, m;
int st[4 * maxn];
int lz[4 * maxn];
vector<pair<pair<int, int>, int> > v;
int ans[maxn];

void update(int node, int l, int r, int L, int R, int val) {
	if (lz[node]) {
		st[node] |= lz[node];
		if (L < R) {
			lz[node << 1] |= lz[node];
			lz[(node << 1) + 1] |= lz[node];
		}
		lz[node] = 0;
	}
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		st[node] |= val;
		if (L < R) {
			lz[node << 1] |= val;
			lz[(node << 1) + 1] |= val;
		}
		lz[node] = 0;
		return;
	}
	update(node << 1, l, r, L, (L + R) >> 1, val);
	update((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, val);
	if (L > ((L + R) >> 1)) st[node] = st[(node << 1) + 1];
	else if (((L + R) >> 1) + 1 > R) st[node] = st[node << 1];
	else st[node] = st[node << 1] & st[(node << 1) + 1];
}

int query(int node, int l, int r, int L, int R) {
	if (lz[node]) {
		st[node] |= lz[node];
		if (L < R) {
			lz[node << 1] |= lz[node];
			lz[(node << 1) + 1] |= lz[node];
		}
		lz[node] = 0;
	}
	if (l > R || r < L) return (1 << 30) - 1;
	if (l <= L && r >= R) return st[node];
	return query(node << 1, l, r, L, (L + R) >> 1) & query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R);
}

void get(int node, int L, int R) {
	if (lz[node] > 0) {
		st[node] |= lz[node];
		if (L < R) {
			lz[node << 1] |= lz[node];
			lz[(node << 1) + 1] |= lz[node];
		}
		lz[node] = 0;
	}
	if (L == R) {ans[L] = st[node]; return;}
	get(node << 1, L, (L + R) >> 1);
	get((node << 1) + 1, ((L + R) >> 1) + 1, R);
}

void solve() {
	ms(st, 0); ms(lz, 0);
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) {
		int l, r, q; scanf("%d%d%d", &l, &r, &q); l--; r--;
		v.push_back(make_pair(make_pair(l, r), q));
		update(1, l, r, 0, n - 1, q);
	}
	FOR(i, 0, sz(v)) if (query(1, v[i].first.first, v[i].first.second, 0, n - 1) != v[i].second) {printf("NO"); return;}
	get(1, 0, n - 1);
	printf("YES\n");
	FOR(i, 0, n) printf("%d ", ans[i]);
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}