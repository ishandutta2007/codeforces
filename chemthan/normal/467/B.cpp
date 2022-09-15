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
ll gcd(ll a, ll b) {
	ll r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 1010;
int n, m, k;
int a[maxn];

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, m + 1) scanf("%d", a + i);
	int ans = 0;
	FOR(i, 0, m) {
		int cnt = 0;
		FOR(j, 0, n) cnt += (a[i] & 1 << j) != (a[m] & 1 << j);
		if (cnt <= k) ans++;
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