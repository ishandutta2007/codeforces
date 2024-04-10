#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

struct node {
	int len;
	int sum;
	int hash1;
	int hash2;

	node() {len = sum = hash1 = hash2 = 0;}
} null;

const int maxn = 100010;
const int mod = 1000000007;
int n, m, k;
char s[maxn];
int p = 100000007;
int rev;
int pw[maxn];

ll ex(ll n, int k) {
	if (!k) return 1;
	if (k & 1) return n * ex(n, k - 1) % mod;
	ll t = ex(n, k >> 1);
	return t * t % mod;
}

node merge(node n1, node n2) {
	node res;
	res.len = n1.len + n2.len;
	res.sum = (n1.sum + n2.sum) % mod;
	res.hash1 = (1LL * n1.len * n2.sum + n1.hash1 + n2.hash1) % mod;
	res.hash2 = (1LL * n1.hash2 * pw[n2.len] + n2.hash2) % mod;
	return res;
}

node st[4 * maxn];
int lz[4 * maxn];
void build(int node, int L, int R) {
	if (L == R) {
		st[node].len = 1;
		st[node].sum = st[node].hash1 = pw[s[L] - '0' + 1];
		st[node].hash2 = s[L] - '0' + 1;
		return;
	}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
	st[node] = merge(st[node << 1], st[(node << 1) + 1]);
}

void update(int node, int l, int r, int L, int R, int val) {
	if (lz[node] != -1) {
		st[node].sum = 1LL * (R - L + 1) * pw[lz[node]] % mod;
		st[node].hash1 = (1LL * (R - L + 1) * (R - L + 2) / 2) % mod * pw[lz[node]] % mod;
		st[node].hash2 = 1LL * lz[node] * (pw[R - L + 1] - 1) % mod * rev % mod;
		if (L < R) {
			lz[node << 1] = lz[node];
			lz[(node << 1) + 1] = lz[node];
		}
		lz[node] = -1;
	}
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		st[node].sum = 1LL * (R - L + 1) * pw[val] % mod;
		st[node].hash1 = (1LL * (R - L + 1) * (R - L + 2) / 2) % mod * pw[val] % mod;
		st[node].hash2 = 1LL * val * (pw[R - L + 1] - 1) % mod * rev % mod;
		if (L < R) {
			lz[node << 1] = val;
			lz[(node << 1) + 1] = val;
		}
		lz[node] = -1;
		return;
	}
	update(node << 1, l, r, L, (L + R) >> 1, val);
	update((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, val);
	st[node] = merge(st[node << 1], st[(node << 1) + 1]);
}

node query(int node, int l, int r, int L, int R) {
	if (lz[node] != -1) {
		st[node].sum = 1LL * (R - L + 1) * pw[lz[node]] % mod;
		st[node].hash1 = (1LL * (R - L + 1) * (R - L + 2) / 2) % mod * pw[lz[node]] % mod;
		st[node].hash2 = 1LL * lz[node] * (pw[R - L + 1] - 1) % mod * rev % mod;
		if (L < R) {
			lz[node << 1] = lz[node];
			lz[(node << 1) + 1] = lz[node];
		}
		lz[node] = -1;
	}
	if (l > R || r < L) return null;
	if (l <= L && r >= R) return st[node];
	return merge(query(node << 1, l, r, L, (L + R) >> 1), query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}

void solve() {
	ms(lz, -1);
	pw[0] = 1; FOR(i, 1, maxn) pw[i] = 1LL * pw[i - 1] * p % mod; rev = ex(p - 1, mod - 2);
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", s);
	build(1, 0, n - 1);
	FOR(i, 0, m + k) {
		int t, l, r, d; scanf("%d%d%d%d", &t, &l, &r, &d); l--; r--;
		if (t == 1) update(1, l, r, 0, n - 1, d + 1);
		else {
			if (d == r - l + 1) printf("YES\n");
			else {
				node n1 = query(1, l + d, r, 0, n - 1);
				node n2 = query(1, l, r - d, 0, n - 1);
				if (n1.sum == n2.sum && n1.hash1 == n2.hash1 && n1.hash2 == n2.hash2) printf("YES\n"); else printf("NO\n");
			}
		}
	}
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}