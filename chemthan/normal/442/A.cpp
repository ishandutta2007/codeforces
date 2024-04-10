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

const int maxn = 110;
int n;
int x[maxn];
int y[maxn];
int a[5];
int b[5];
map<int, int> cnt[2];

int get(char c, int k) {
	if (cnt[k].count(c)) return cnt[k][c];
	int res = sz(cnt[k]);
	cnt[k][c] = res;
	return res;
}

void solve() {
	cin>>n;
	FOR(i, 0, n) {
		string s; cin>>s;
		x[i] = get(s[0], 0);
		y[i] = get(s[1], 1);
		a[x[i]] |= 1 << y[i];
		b[y[i]] |= 1 << x[i];
	}
	int ans = INF;
	FOR(i, 0, 1 << 5) FOR(j, 0, 1 << 5) {
		int tot = 0;
		FOR(k, 0, n) {
			int flagx = 0, flagy = 0;
			if (bit(i, x[k]) || bitcount(i) == sz(cnt[0]) - 1) flagx = 1;
			if (bit(j, y[k]) || bitcount(j) == sz(cnt[1]) - 1) flagy = 1;
			if (flagx && flagy) {
				tot++;
				continue;
			}
			if (flagx) {
				int d = 0;
				FOR(l, 0, 5) {
					if (bit(j, l) && bit(a[x[k]], l)) {
						d++;
					}
				}
				if (d < bitcount(a[x[k]]) - 1) {
					break;
				}
				else {
					tot++;
					continue;
				}
			}
			if (flagy) {
				int d = 0;
				FOR(l, 0, 5) {
					if (bit(i, l) && bit(b[y[k]], l)) {
						d++;
					}
				}
				if (d < bitcount(b[y[k]]) - 1) {
					break;
				}
				else {
					tot++;
					continue;
				}
			}
		}
		if (tot >= n - 1) ans = min(ans, bitcount(i) + bitcount(j));
	}
	cout<<ans;
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