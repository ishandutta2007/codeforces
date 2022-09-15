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
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 200010;
ll n, d, m;
ll x[maxn];
ll p[maxn];

ll st[4 * maxn];
void build(int node, int L, int R) {
	if (L == R) {
		st[node] = p[L];
		return;
	}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
	st[node] = min(st[node << 1], st[(node << 1) + 1]);
}
ll query(int node, int l, int r, int L, int R) {
	if (l > R || r < L) return LINF;
	if (l <= L && r >= R) return st[node];
	return min(query(node << 1, l, r, L, (L + R) >> 1), query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}

void solve() {
	cin>>d>>n>>m;
	vii v;
	FOR(i, 1, m + 1) {
		cin>>x[i]>>p[i];
		v.pb(mp(x[i], p[i]));
	}
	sort(all(v));
	FOR(i, 1, m + 1) {
		x[i] = v[i - 1].fi;
		p[i] = v[i - 1].se;
	}
	x[m + 1] = d;
	build(1, 0, m + 1);
	int cur = 0;
	ll ans = 0, r = 0;
	while (cur < m + 1) {
		if (x[cur] + n < x[cur + 1]) {
			cout<<-1;
			return;
		}
		int lo = cur + 1, hi = upper_bound(x, x + m + 2, x[cur] + n) - x - 1;
		while (lo < hi) {
			int mid = (lo + hi) >> 1;
			if (query(1, cur + 1, mid, 0, m + 1) > p[cur]) lo = mid + 1; else hi = mid;
		}
		if (query(1, cur + 1, lo, 0, m + 1) <= p[cur]) {
			ans += p[cur] * max(0LL, x[lo] - x[cur] - r);
			r = max(0LL, x[cur] + r - x[lo]);
			cur = lo;
		}
		else {
			ans += (n - r) * p[cur];
			r = x[cur] + n - x[cur + 1];
			cur++;
		}
	}
	cout<<ans;
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