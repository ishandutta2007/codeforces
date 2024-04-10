#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 30;
int n, k;
ll s;
int a[maxn];
ll frac[maxn];
map<ll, ll> mp[maxn];
ll ans;

void cal(int t, ll _s, ll _l, ll _r, ll _k, ll __k) {
	if (_l == _r) {
		if (!t) mp[__k - _k][_s]++; else FOR(i, 0, k - (__k - _k) + 1) ans += mp[i][s - _s];
		return;
	}
	cal(t, _s, _l + 1, _r, _k, __k);
	cal(t, _s + a[_l], _l + 1, _r, _k, __k);
	if (a[_l] <= 18 && _k) cal(t, _s + frac[a[_l]], _l + 1, _r, _k - 1, __k);
}

void solve() {
	frac[0] = 1; FOR(i, 1, maxn) frac[i] = frac[i - 1] * i;
	scanf("%d%d%I64d", &n, &k, &s);
	FOR(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	ans = 0;
	int d = n / 2;
	cal(0, 0, 0, d + 1, k, k);
	cal(1, 0, d + 1, n, k, k);
	printf("%I64d", ans);
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}