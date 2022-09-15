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
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 200010;
int n, k, b, c;
int t[maxn];

ll work(int r) {
	vector<ll> vt(n, 0), vx(n, 0);
	FOR(i, 0, n) {
		vt[i] = t[i];
		while ((vt[i] % 5 + 5) % 5 != r) {
			vx[i] -= c;
			vt[i]++;
		}
		vx[i] += b * (vt[i] - r) / 5;
	}
	multiset<ll> st;
	ll sum = 0;
	FOR(i, 0, k) {
		st.insert(vx[i]);
		sum += vx[i];
	}
	ll res = (ll) b * k * (vt[k - 1] - r) / 5 - sum;
	FOR(i, k, n) {
		sum += vx[i];
		st.insert(vx[i]);
		sum -= *st.begin();
		st.erase(st.begin());
		setmin(res, (ll) b * k * (vt[i] - r) / 5 - sum);
	}
	return res;
}

void solve() {
	cin>>n>>k>>b>>c;
	setmin(b, 5 * c);
	FOR(i, 0, n) cin>>t[i];
	sort(t, t + n);
	ll ans = LINF;
	FOR(r, 0, 5) setmin(ans, work(r));
	cout<<ans<<"\n";
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