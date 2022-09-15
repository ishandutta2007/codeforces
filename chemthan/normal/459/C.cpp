#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 1010;
int n, k, d;
int a[maxn][maxn];

int go(int i, int l, int r) {
	if (i == d) return l == r;
	int p = (r - l + 1) / k;
	int s = (r - l + 1) % k;
	int res = 1, cur = l, cnt = 1;
	while (cur <= r) {
		int t = cur + p;
		if (s) {t++; s--;}
		FOR(j, cur, t) a[i][j] = cnt;
		res &= go(i + 1, cur, t - 1);
		cur = t;
		cnt++;
	}
	return res;
}

void solve() {
	scanf("%d%d%d", &n, &k, &d);
	if (!go(0, 0, n - 1)) {printf("-1"); return;}
	FOR(i, 0, d) {
		FOR(j, 0, n) printf("%d ", a[i][j]);
		printf("\n");
	}
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