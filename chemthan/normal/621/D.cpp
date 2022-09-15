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

ld a[12];
string s[] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y", "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x", "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};

void solve() {
	ld x, y, z; cin>>x>>y>>z;
	if (x <= 1 || y <= 1 || z <= 1) {
		a[0] = pow(x, pow(y, z));
		a[1] = pow(x, pow(z, y));
		a[2] = pow(x, y * z);
		a[3] = pow(x, z * y);
		a[4] = pow(y, pow(x, z));
		a[5] = pow(y, pow(z, x));
		a[6] = pow(y, x * z);
		a[7] = pow(y, z * x);
		a[8] = pow(z, pow(x, y));
		a[9] = pow(z, pow(y, x));
		a[10] = pow(z, x * y);
		a[11] = pow(z, y * x);
	}
	else {
		a[0] = log(log(x)) + z * log(y);
		a[1] = log(log(x)) + y * log(z);
		a[2] = log(log(x)) + log(y * z);
		a[3] = log(log(x)) + log(z * y);
		a[4] = log(log(y)) + z * log(x);
		a[5] = log(log(y)) + x * log(z);
		a[6] = log(log(y)) + log(x * z);
		a[7] = log(log(y)) + log(z * x);
		a[8] = log(log(z)) + y * log(x);
		a[9] = log(log(z)) + x * log(y);
		a[10] = log(log(z)) + log(x * y);
		a[11] = log(log(z)) + log(y * x);
	}
	ld dmax = a[0];
	int imax = 0;
	FOR(i, 0, 12) {
		if (dmax < a[i] + 1e-100) {
			dmax = a[i];
			imax = i;
		}
	}
	cout<<s[imax];
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