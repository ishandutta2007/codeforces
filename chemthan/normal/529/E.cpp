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

const int maxn = 5010;
const int maxx = 200000010;
const int maxc = 255;
int n, k;
int a[maxn];
unsigned char f[maxx];

void solve() {
	f[0] = 0; FOR(i, 1, maxx) f[i] = maxc;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) scanf("%d", a + i);
	FOR(i, 0, n) for (int j = 1; j <= k && j * a[i] < maxx; j++) f[j * a[i]] = min((int) f[j * a[i]], j);
	int q; scanf("%d", &q);
	while (q--) {
		int x; scanf("%d", &x);
		int ans = maxc;
		FOR(i, 0, n) for (int j = 1; j <= k && j * a[i] <= x; j++) ans = min(ans, j + f[x - j * a[i]]);
		if (ans > k) ans = -1;
		printf("%d\n", ans);
	}
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