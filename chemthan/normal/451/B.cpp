#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 100010;
int n;
int a[maxn];
map<int, int> dc;

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d", a + i);
		dc[a[i]];
	}
	int cnt = 0; FORall(it, dc) it->se = cnt++;
	FOR(i, 0, n) a[i] = dc[a[i]];
	if (a[0]) {
		int idx;
		FOR(i, 0, n) if (a[i] == 0) {
			idx = i; break;
		}
		FOR(i, 1, idx) if (a[i] + 1 != a[i - 1]) {
			printf("no");
			return;
		}
		FOR(i, idx + 1, n - 1) if (a[i] + 1 != a[i + 1]) {
			printf("no");
			return;
		}
		printf("yes\n%d %d", 1, idx + 1);
	}
	else if (a[n - 1] != n - 1) {
		int idx;
		FORd(i, n, 0) if (a[i] == n - 1) {
			idx = i; break;
		}
		FOR(i, idx, n - 1) if (a[i] != a[i + 1] + 1) {
			printf("no");
			return;
		}
		FOR(i, 0, idx - 1) if (a[i] + 1 != a[i + 1]) {
			printf("no");
			return;
		}
		printf("yes\n%d %d", idx + 1, n);
	}
	else {
		int idx1 = -1, idx2 = -1;
		FOR(i, 0, n) {
			if (a[i] != i) {
				idx1 = i;
				break;
			}
		}
		FORd(i, n, 0) {
			if (a[i] != i) {
				idx2 = i;
				break;
			}
		}
		if (!~idx1) {
			printf("yes\n%d %d", 1, 1);
			return;
		}
		FOR(i, idx1, idx2) {
			if (a[i] != a[i + 1] + 1) {
				printf("no");
				return;
			}
		}
		printf("yes\n%d %d", idx1 + 1, idx2 + 1);
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}