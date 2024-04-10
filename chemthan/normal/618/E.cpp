#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = a + val) >= p) a -= p;}

struct PT {
	ld x, y;
	PT(ld x = 0, ld y = 0) : x(x), y(y) {}
	PT operator + (PT other) {
		PT res;
		res.x = x + other.x;
		res.y = y + other.y;
		return res;
	}
};

struct LZ {
	ld x[2][2];
	PT y;
	LZ() {
		x[0][0] = x[1][1] = 1;
	}
	int iszero() {
		if (x[0][0] != 1 || x[0][1] != 0 || x[1][0] != 0 || x[1][1] != 1) return 0;
		if (y.x != 0 || y.y != 0) return 0;
		return 1;
	}
	void clear() {
		x[0][0] = x[1][1] = 1;
		x[0][1] = x[1][0] = 0;
		y.x = y.y = 0;
	}
	LZ operator * (LZ other) {
		LZ res; ms(res.x, 0);
		FOR(i, 0, 2) FOR(k, 0, 2) FOR(j, 0, 2) {
			res.x[i][j] += other.x[i][k] * x[k][j];
		}
		res.y.x = other.y.x + other.x[0][0] * y.x + other.x[0][1] * y.y;
		res.y.y = other.y.y + other.x[1][0] * y.x + other.x[1][1] * y.y;
		return res;
	}
};

const int maxn = 300010;
PT st[4 * maxn];
LZ lz[4 * maxn];

void build(int node, int L, int R) {
	if (L == R) {
		st[node].x = L;
		st[node].y = 0;
		return;
	}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
}

void updatelz(int node, int L, int R) {
	if (!lz[node].iszero()) {
		PT p;
		p.x = lz[node].x[0][0] * st[node].x + lz[node].x[0][1] * st[node].y + lz[node].y.x;
		p.y = lz[node].x[1][0] * st[node].x + lz[node].x[1][1] * st[node].y + lz[node].y.y;
		st[node] = p;
		if (L < R) {
			lz[node << 1] = lz[node << 1] * lz[node];
			lz[(node << 1) + 1] = lz[(node << 1) + 1] * lz[node];
		}
		lz[node].clear();
	}
}

void update(int node, int l, int r, int L, int R, PT p) {
	updatelz(node, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		lz[node].y.x = p.x;
		lz[node].y.y = p.y;
		updatelz(node, L, R);
		return;
	}
	update(node << 1, l, r, L, (L + R) >> 1, p);
	update((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, p);
}

void update(int node, int l, int r, int L, int R, PT p, ld al) {
	updatelz(node, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		lz[node].x[0][0] = +cos(al);
		lz[node].x[0][1] = -sin(al);
		lz[node].x[1][0] = +sin(al);
		lz[node].x[1][1] = +cos(al);
		lz[node].y.x = (1 - cos(al)) * p.x + sin(al) * p.y;
		lz[node].y.y = -sin(al) * p.x + (1 - cos(al)) * p.y;
		updatelz(node, L, R);
		return;
	}
	update(node << 1, l, r, L, (L + R) >> 1, p, al);
	update((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, p, al);
}

PT query(int node, int i, int L, int R) {
	updatelz(node, L, R);
	if (i < L || i > R) return PT(0, 0);
	if (L == R) return st[node];
	return query(node << 1, i, L, (L + R) >> 1) + query((node << 1) + 1, i, ((L + R) >> 1) + 1, R);
}

void solve() {
	int n, m; cin>>n>>m;
	build(1, 0, n);
	while (m--) {
		int op, x, y; cin>>op>>x>>y;
		if (op == 1) {
			PT u = query(1, x - 1, 0, n);
			PT v = query(1, x, 0, n);
			ld z = v.x - u.x;
			ld t = v.y - u.y;
			update(1, x, n, 0, n, PT(z * y / sqrt(z * z + t * t), t * y / sqrt(z * z + t * t)));
		}
		else {
			PT u = query(1, x - 1, 0, n);
			update(1, x, n, 0, n, u, -y * PI / 180);
		}
		PT r = query(1, n, 0, n);
		cout<<prec(9)<<r.x<<" "<<r.y<<"\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}