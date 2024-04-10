#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 500010;
int n;
int a[maxn];
bool flag[maxn];
int res[maxn];

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i);
	vi v; v.push_back(0); flag[0] = 1;
	FOR(i, 1, n - 1) if (a[i - 1] == a[i] || a[i] == a[i + 1]) {v.push_back(i); flag[i] = 1;}
	v.push_back(n - 1); flag[n - 1] = 1;
	int ans = 0;
	FOR(i, 0, sz(v) - 1) {
		int x = v[i];
		int y = v[i + 1];
//		if (y - x == 1) continue;
		int d = (y - x) >> 1;
		ans = max(ans, d);
		FOR(j, x, x + d + 1) res[j] = a[x];
		FOR(j, x + d + 1, y) res[j] = a[y];
	}
	printf("%d\n", ans);
	FOR(i, 0, n) if (flag[i]) printf("%d ", a[i]); else printf("%d ", res[i]);
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