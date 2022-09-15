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
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 200010;
int n;
int a[3];
int t[maxn];
multiset<int> st;

int dprocess(int t) {
	multiset<int>::iterator it = st.upper_bound(a[t]);
	if (it == st.begin()) return 0;
	it--; st.erase(it);
	return 1;
}

void process(int t) {
	if (t == 2) {
		if (!sz(st)) return;
		multiset<int>::iterator it = st.end(); it--;
		int k = *it; st.erase(it);
		if (k <= a[t]) {
			process(t - 1);
		}
		else {
			if (k <= a[0] + a[1]) {
				dprocess(2);
			}
			else if (k <= a[0] + a[2]) {
				dprocess(1);
			}
			else if (k <= a[1] + a[2]) {
				dprocess(0);
			}
		}
	}
	else if (t == 1) {
		if (!sz(st)) return;
		if (dprocess(t)) {
			dprocess(t - 1);
		}
		else {
			multiset<int>::iterator it = st.upper_bound(a[0] + a[1]);
			if (it == st.begin()) return;
			it--; st.erase(it);
		}
	}
	else dprocess(t);
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, 3) scanf("%d", a + i);
	FOR(i, 0, n) {
		scanf("%d", t + i);
		st.insert(t[i]);
	}
	if (*st.rbegin() > a[0] + a[1] + a[2]) {
		printf("-1");
		return;
	}
	sort(a, a + 3);
	int ans = 0;
	while (sz(st)) {
		ans++;
		process(2);
	}
	printf("%d", ans);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}