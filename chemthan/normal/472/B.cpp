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
const ld PI = 2 * acos((ld) 0);

const int maxn = 2010;
int n, k;
int a[maxn];
int f[maxn];

int st[4 * maxn];
void build(int node, int L, int R) {
	if (L == R) {st[node] = a[L]; return;}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
	st[node] = max(st[node << 1], st[(node << 1) + 1]);
}
int query(int node, int l, int r, int L, int R) {
	if (l > R || r < L) return 0;
	if (l <= L && r >= R) return st[node];
	return max(query(node << 1, l, r, L, (L + R) >> 1), query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}

void solve() {
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	build(1, 0, n - 1);
	ms(f, 0x3f); f[n] = 0;
	FORd(i, n, 0) {
		FOR(j, i, i + k) {
			f[i] = min(f[i], f[j + 1] + 2 * query(1, i, j, 0, n - 1) - 2);
		}
	}
	printf("%d", f[0]);
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