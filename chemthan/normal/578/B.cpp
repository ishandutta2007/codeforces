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

const int maxn = 200010;
int n, k, x;
ll a[maxn];
ll pref[maxn];
ll suff[maxn];

void solve() {
	ms(pref, 0); ms(suff, 0);
	scanf("%d%d%d", &n, &k, &x);
	FOR(i, 0, n) scanf("%I64d", a + i);
	FOR(i, 0, n) if (!i) pref[i] = a[i]; else pref[i] = pref[i - 1] | a[i];
	FORd(i, n, 0) suff[i] = suff[i + 1] | a[i];
	ll ans = 0;
	FOR(i, 0, n) {
		ll tmp = a[i];
		FOR(j, 0, k) tmp *= x;
		ans = max(ans, (i > 0 ? pref[i - 1] : 0) | tmp | suff[i + 1]);
	}
	cout<<ans;
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