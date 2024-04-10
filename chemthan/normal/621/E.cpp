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
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = a + val) >= p) a -= p;}

const int MAXN = 110;
struct matrix {
	int x[MAXN][MAXN];
	matrix() {
		memset(x, 0, sizeof(x));
	}
	matrix unit() {
		matrix res;
		for (int i = 0; i < MAXN; i++) res.x[i][i] = 1;
		return res;
	}
	matrix operator + (matrix A) {
		matrix res;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = (x[i][j] + A.x[i][j]) % MOD;
		}
		return res;
	}
	matrix operator * (matrix A) {
		matrix res;
		for (int i = 0; i < MAXN; i++) for (int k = 0; k < MAXN; k++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = (res.x[i][j] + 1LL * x[i][k] * A.x[k][j]) % MOD;
		}
		return res;
	}
	matrix operator ^ (long long k) {
		if (!k) return unit();
		matrix res, tmp;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = tmp.x[i][j] = x[i][j];
		}
		k--;
		while (k) {
			if (k & 1) res = res * tmp;
			tmp = tmp * tmp;
			k >>= 1;
		}
		return res;
	}
	friend matrix sumpower(matrix A, long long k) {
		if (k == 1) return A;
		if (k & 1) return (A ^ k) + sumpower(A, k - 1);
		k >>= 1;
		matrix T = sumpower(A, k);
		return T + (T * (A ^ k));
	}
};

const int maxx = 110;
int n, b, k, x;
int cnt[maxx];

void solve() {
	cin>>n>>b>>k>>x;
	FOR(i, 0, n) {
		int a; cin>>a;
		cnt[a % x]++;
	}
	matrix A;
	FOR(i, 0, x) FOR(j, 0, x) {
		int d = (i - 10 * j % x + x) % x;
		A.x[i][j] = cnt[d];
	}
	A = A ^ b;
	cout<<A.x[k][0];
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