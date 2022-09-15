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

const int maxn = 300010;
const int maxk = 5010;
int n, k;
int a[maxn];
ll f[maxk][maxk];
int d, r;

ll cal(int x, int y) {
	if (x == k) {
		if (y == r) return 0;
		return _I64_MAX / 10;
	}
	if (f[x][y] != -1) return f[x][y];
	f[x][y] = cal(x + 1, y) + a[d * (x + 1) + y - 1] - a[d * x + y];
	if (y < r) f[x][y] = min(f[x][y], cal(x + 1, y + 1) + a[d * (x + 1) + y] - a[d * x + y]);
	return f[x][y];
}

void solve() {
	ms(f, -1);
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	d = n / k;
	r = n % k;
	cout<<cal(0, 0);
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