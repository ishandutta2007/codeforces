#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int mod = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 100010;
int n, k;
int a[maxn];
int b[maxn];

int calc(int n, int k) {
	if (n < 0) return 0;
	return n / k + 1;
}

int calc(int l, int r, int k) {
	return calc(r, k) - calc(l - 1, k);
}

void solve() {
	scanf("%d%d", &n, &k);
	int d = n / k;
	FOR(i, 0, d) scanf("%d", a + i);
	FOR(i, 0, d) scanf("%d", b + i);
	int pw = 1; FOR(i, 1, k) pw *= 10;
	int ans = 1;
	FOR(i, 0, d) {
		int res = calc((b[i] + 1) * pw, 10 * pw - 1, a[i]);
		res += calc(0, b[i] * pw - 1, a[i]);
		ans = 1LL * ans * res % mod;
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