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
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = (int) 1e9 + 7) {if ((a = a + val) >= p) a -= p;}
template<class T> void setmin(T& a, T val) {a = min(a, val);}
template<class T> void setmax(T& a, T val) {a = max(a, val);}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 40;
int n, k;
int a[maxn];
ld f[2][maxn][maxn];

void solve() {
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) scanf("%d", a + i);
	int cnt = 0;
	FOR(i, 0, n) FOR(j, i + 1, n) {
		f[cnt][i][j] = a[i] > a[j];
	}
	FOR(t, 0, k) {
		FOR(i, 0, n) FOR(j, i + 1, n) {
			f[cnt ^ 1][i][j] = 0;
			FOR(u, 0, n) FOR(v, u, n) {
				int p = i, q = j;
				if (u <= i && i <= v) p = u + v - i;
				if (u <= j && j <= v) q = u + v - j;
				if (p < q) f[cnt ^ 1][i][j] += f[cnt][p][q];
				else f[cnt ^ 1][i][j] += 1 - f[cnt][q][p];
			}
			f[cnt ^ 1][i][j] /= n * (n + 1) / 2;
		}
		cnt ^= 1;
	}
	ld ans = 0;
	FOR(i, 0, n) FOR(j, i + 1, n) ans += f[cnt][i][j];
	cout<<prec(12)<<ans;
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