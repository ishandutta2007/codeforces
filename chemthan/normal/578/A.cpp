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
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}


int a, b;

void solve() {
	scanf("%d%d", &a, &b);
	ld ans = 10LL * INT_MAX;
	int k = a / b - 1;
	if (k >= 0) {
		k >>= 1;
		ans = min(ans, ld(1.0) * (a + b) / (2 * k + 2));
	}
	k = a / b - 1;
	if (k >= 0) {
		k >>= 1;
		if (k > 0) ans = min(ans, ld(1.0) * (a - b) / (2 * k));
	}
	if (ans == 10LL * INT_MAX) printf("-1"); else cout<<fixed<<setprecision(9)<<ans;
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}