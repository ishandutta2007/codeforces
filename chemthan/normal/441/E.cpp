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
typedef double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

int x, k, p;
ld f[200][256][256][2];

ld calc(int pos, int c, int r, int t) {
	if (pos == k) {
		c = t ? 0 : c;
		if (!r) return c + 8;
		int res = 0;
		while (!(r & 1)) {
			res++;
			r >>= 1;
		}
		return res;
	}
	ld& res = f[pos][c][r][t];
	if (res >= 0) return res;
	res = 0;
	if (r < 128) {
		res += p / 100.0 * calc(pos + 1, t ? 1 : c + 1, r << 1, 0);
	}
	else {
		res += p / 100.0 * calc(pos + 1, t ? c + 1 : 1, (r << 1) - 256, 1);
	}
	if (r < 256 - 1) {
		res += (100.0 - p) / 100 * calc(pos + 1, c, r + 1, t);
	}
	else {
		res += (100.0 - p) / 100 * calc(pos + 1, t ? c : 1, 0, t ? 0 : 1);
	}
	return res;
}

void solve() {
	cin>>x>>k>>p;
	FOR(i, 0, 200) FOR(j, 0, 256) FOR(k, 0, 256) f[i][j][k][0] = f[i][j][k][1] = -1;
	int d = x / 256;
	int r = x % 256;
	int c = 0, t = 0;
	if (d & 1) {
		t = 1;
		while (d & 1) c++, d >>= 1;
	}
	else {
		t = 0;
		while (!(d & 1) && d) c++, d >>= 1;
	}
	cout<<prec(9)<<calc(0, c, r, t)<<"\n";
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