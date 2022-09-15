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
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

vi FILL(int x, int tot, int n) {
	if (!x) {
		vi res;
		return res;
	}
	if (x == 1) {
		vi res; res.pb(tot);
		return res;
	}
	int nxt = min(n, tot - (x - 1));
	vi res = FILL(x - 1, tot - nxt, n);
	res.pb(nxt);
	return res;
}

void solve() {
	int x = 1, y = 0;
	vi order; order.pb(1);
	while (1) {
		char c[10]; scanf("%s", c);
		if (c[0] == '+') x++, order.pb(1);
		else if (c[0] == '-') y++, order.pb(-1);
		else if (c[0] == '=') break;
	}
	int n; scanf("%d", &n);
	if (x * n - y < n || x - y * n > n) {
		puts("Impossible");
		return;
	}
	FOR(i, y, y * n + 1) {
		if (n + i >= x && n + i <= x * n) {
			puts("Possible");
			vi vx = FILL(x, n + i, n);
			vi vy = FILL(y, i, n);
			FOR(i, 0, sz(order)) {
				if (!i) {
					printf("%d", vx.back());
					vx.pop_back();
				}
				else {
					if (order[i] == 1) {
						printf(" + %d", vx.back());
						vx.pop_back();
					}
					else {
						printf(" - %d", vy.back());
						vy.pop_back();
					}
				}
			}
			printf(" = %d\n", n);
			return;
		}
	}
	puts("Impossible");
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