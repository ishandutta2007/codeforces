#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e6 + 7;

int a[N], b[N];
int posa[N], posb[N];

void extgcd(ll a, ll &x, ll b, ll &y, ll &g) {
	if(b == 0) {
		g = a;
		x = 1, y = 0;
	} else {
		extgcd(b, y, a%b, x, g);
		y -= a/b*x;
	}
}

ll inv(ll i , ll M) {
	if(M == 1) return 0;
	ll x, y, g;
	extgcd(i, x, M, y, g);
	return (x%M+M)%M;
}

bool dbg = false;

signed main()
{
	IO_OP;

	memset(posa, -1, sizeof posa);
	memset(posb, -1, sizeof posb);
	mt19937 rng(time(0));

	int n, m;
	ll k;
	if(!dbg) cin >> n >> m >> k;
	else n = 5e5, m = n - 1, k = 1e12;
	for(int i = 0; i < n; i++) {
		if(!dbg) cin >> a[i];
		else a[i] = rng() % (2 * n) + 1;
		posa[a[i]] = i;
	}
	for(int i = 0; i < m; i++) {
		if(!dbg) cin >> b[i];
		else b[i] = rng() % (2 * n) + 1;
		posb[b[i]] = i;
	}
	int g = __gcd(n, m), invn, invm;
	int nn = n / g, mm = m / g;
	invn = inv(nn % mm, mm), invm = inv(mm % nn, nn);
	auto solve = [&] (int p1, int p2, int n, int m, int invn) -> ll{
		if(p1 == p2) return p1;
		assert(p1 > p2);
		if(m == 1) return p1;
		int mm = m / g;
		ll alpha = (ll) ((p2 - p1) / g  % mm + mm) % mm * invn % mm;
		assert((p1 + alpha * n) % m == p2);
		return p1 + alpha * n;
	};
	V<ll> pre(2 * max(n, m) + 1, -1);
	for(int i = 1; i <= 2 * max(n, m); i++) {
		if(posa[i] == -1) continue;
		if(posb[i] == -1) continue;
		ll p1 = posa[i], p2 = posb[i];
		if(p1 % g != p2 % g) continue;
		ll x;
		if(p1 > p2)
			x = solve(p1, p2, n, m, invn);
		else
			x = solve(p2, p1, m, n, invm);
		pre[i] = x;
	}
	auto bad = [&] (ll day) {
		ll bad = day;
		for(int i = 1; i <= 2 * max(n, m); i++) {
			ll x = pre[i];
			if(x == -1) continue;
			if(x >= day) continue;
			ll step = (ll) n * m / g;
			ll k = (day - 1 - x) / step;
			bad -= k + 1;
		}
		return bad;
	};
	ll lb = 1, rb = 1e18;
	while(lb <= rb) {
		ll mb = lb + (rb - lb) / 2;
		if(bad(mb) >= k) rb = mb - 1;
		else lb = mb + 1;
	}
	cout << lb << '\n';

}