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

const int maxn = 100010;
int n, m;
char s[maxn];
int c[maxn];
ll f[maxn][2][2];

ll cal(int pos, int a, int b) {
	if (pos == n) return a == 0;
	if (f[pos][a][b] != -1) return f[pos][a][b];
	ll res = cal(pos + 1, a, b);
	if (a) {
		if (pos == n - 1) res += b == 0 ? m : 0;
		else res += (m - 1) * cal(pos + 2, a - 1, b);
	}
	if (b) {
		if (pos + a < n && s[pos + a - 1] != s[pos + a]) res += cal(pos + 1, a, b - 1);
	}
	if (a && b) {
		if (pos < n - 1 && s[pos] != s[pos + 1]) res += (m - 2) * cal(pos + 2, a - 1, b - 1);
		else if (pos == n - 1) res += m - 1;
	}
	return f[pos][a][b] = res;
}

void solve() {
	ms(f, -1);
	scanf("%d%d%s", &n, &m, s);
	ll ans = cal(0, 1, 1); c[0] = 1;
	FOR(i, 1, n) {
		if (s[i] != s[i - 1]) c[i] = 2; else c[i] = 1;
		if (s[i] != s[i - 1] && s[i] == s[i - 2]) c[i] = c[i - 1] + 1;
		ans -= c[i] - 1;
	}
	printf("%I64d", ans);
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