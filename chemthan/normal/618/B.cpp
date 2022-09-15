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
template<class T> gcd(T a, T b) {T r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
template<class T> lcm(T a, T b) {return a / gcd(a, b) * b;}
template<class T> void setmin(T& a, T val) {a = min(a, val);}
template<class T> void setmax(T& a, T val) {a = max(a, val);}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = (int) 1e9 + 7) {if ((a = a + val) >= p) a -= p;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 60;
int n;
int a[maxn][maxn];
int b[maxn];
int ans[maxn];

int check(int u, int v, int k) {
	FOR(i, 0, n) if (a[u][i] > k) return 0;
	FOR(i, 0, n) if (a[i][v] > k) return 0;
	return 1;
}

void solve() {
	cin>>n;
	FOR(i, 0, n) FOR(j, 0, n) {cin>>a[i][j]; a[i][j]--;}
	FOR(i, 0, n) {
		FOR(j, 0, n) if (!b[j] && check(j, j, i)) {
			ans[j] = i;
			b[j] = 1;
			break;
		}
	}
	FOR(i, 0, n) {
		cout<<ans[i] + 1;
		if (i < n - 1) cout<<" ";
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