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
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
void setmin(int& a, int val) {if (a > val) a = val;}
void setmax(int& a, int val) {if (a < val) a = val;}


double getangle(pair<ld, ld> a) {
	if (a.fi == 0) {
		if (a.se > 0) return PI / 2;
		return 3 * PI / 2;
	}
	if (a.se == 0) {
		if (a.fi > 0) return 0;
		return PI;
	}
	double alpha = atan(a.se / a.fi);
	if (a.fi < 0) return alpha + PI;
	if (a.se < 0) return alpha + 2 * PI;
	return alpha;
}

void solve() {
	ld px, py, vx, vy, a, b, c, d; cin>>px>>py>>vx>>vy>>a>>b>>c>>d;
	pair<ld, ld> res[7];
	res[0] = mp(px, py + b);
	res[1] = mp(px - a / 2, py);
	res[2] = mp(px - c / 2, py);
	res[3] = mp(px - c / 2, py - d);
	res[4] = mp(px + c / 2, py - d);
	res[5] = mp(px + c / 2, py);
	res[6] = mp(px + a / 2, py);
	ld al = getangle(mp(vx, vy)) - PI / 2;
	
	FOR(i, 0, 7) {
		ld s = res[i].fi - px;
		ld t = res[i].se - py;
		res[i].fi = s * cos(al) - t * sin(al);
		res[i].se = s * sin(al) + t * cos(al);
		cout<<prec(9)<<px + res[i].fi<<" "<<py + res[i].se<<"\n";
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}