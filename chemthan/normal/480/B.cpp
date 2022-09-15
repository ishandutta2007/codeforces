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

const int maxn = 100010;
int n;
ll l, x, y;
ll a[maxn];
map<ll, bool> mp;

void solve() {
	scanf("%d%I64d%I64d%I64d", &n, &l, &x, &y);
	FOR(i, 0, n) {
		scanf("%I64d", a + i);
		mp[a[i]] = 1;
	}
	bool flag[2]; ms(flag, 0);
	FOR(i, 0, n) if (mp[a[i] + x] || mp[a[i] - x]) {flag[0] = 1; break;}
	FOR(i, 0, n) if (mp[a[i] + y] || mp[a[i] - y]) {flag[1] = 1; break;}
	if (flag[0] && flag[1]) {printf("0"); return;}
	if (!flag[0] && flag[1]) {printf("1\n%I64d", x); return;}
	if (flag[0] && !flag[1]) {printf("1\n%I64d", y); return;}
	FOR(i, 0, n) if (mp[a[i] + x + y]) {printf("1\n%I64d", a[i] + x); return;}
	FOR(i, 0, n) if (mp[a[i] + x - y] && a[i] + x <= l) {printf("1\n%I64d", a[i] + x); return;}
	FOR(i, 0, n) if (mp[a[i] + x - y] && a[i] - y >= 0) {printf("1\n%I64d", a[i] - y); return;}
	swap(x, y);
	FOR(i, 0, n) if (mp[a[i] + x - y] && a[i] + x <= l) {printf("1\n%I64d", a[i] + x); return;}
	FOR(i, 0, n) if (mp[a[i] + x - y] && a[i] - y >= 0) {printf("1\n%I64d", a[i] - y); return;}
	printf("2\n%I64d %I64d", x, y);
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