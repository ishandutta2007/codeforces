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

const int maxn = 100010;
int n, m;
int f[maxn];
int b[maxn];
int c[maxn];
int d[maxn];
int ans[maxn];

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, n + 1) {
		scanf("%d", f + i);
		c[f[i]] = i;
		d[f[i]]++;
	}
	FOR(i, 1, m + 1) {
		scanf("%d", b + i);
		if (!c[b[i]]) {
			printf("Impossible");
			return;
		}
	}
	FOR(i, 1, m + 1) {
		if (d[b[i]] > 1) {printf("Ambiguity"); return;}
		ans[i] = c[b[i]];
	}
	printf("Possible\n");
	FOR(i, 1, m + 1) printf("%d ", ans[i]);
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