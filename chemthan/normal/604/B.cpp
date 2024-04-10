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
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-12
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 100010;
int n, k;
int s[maxn];

int check(int d) {
	int u = n - k;
	int v = 2 * k - n;
	if (v && s[n - 1] > d) return 0;
	multiset<int> st;
	FOR(i, 0, 2 * u) st.insert(s[i]);
	while (sz(st)) {
		int p = *st.rbegin();
		st.erase(st.find(p));
		set<int>::iterator it = st.upper_bound(d - p);
		if (it == st.begin()) return 0;
		it--; st.erase(it);
	}
	return 1;
}

void solve() {
	scanf("%d%d", &n, &k);
	k = min(k, n);
	FOR(i, 0, n) scanf("%d", s + i);
	int l = 0, r = (int) 1e9;
	while (l < r) {
		int m = (l + r) >> 1;
		if (!check(m)) l = m + 1;
		else r = m;
	}
	printf("%d", l);
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