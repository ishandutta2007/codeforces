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

const int maxn = 200010;
int n, m;
int a[maxn];
int cnt[maxn];

void solve() {
	ms(cnt, 0);
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i);
	scanf("%d", &m);
	FOR(i, 0, m) {int b; scanf("%d", &b); cnt[b - 1]++;}
	bool flag1 = m % ((n - 1) << 1);
	ll ans = 0;
	cnt[0] <<= 1; cnt[n - 1] <<= 1;
	bool flag2 = 1;
	FOR(i, 0, n - 1) {
		ans += 1LL * min(cnt[i], cnt[i + 1]) * (a[i + 1] - a[i]);
		flag2 &= a[i + 1] - a[i] == a[1] - a[0];
	}
	if (flag1 || flag2) printf("%I64d", ans - (!flag1) * (a[1] - a[0])); else printf("-1");
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