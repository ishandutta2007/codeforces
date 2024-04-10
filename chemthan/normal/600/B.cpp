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

const int maxn = 200010;
int n, m;
int a[maxn];
int b[maxn];
map<int, int> dc;

int bit[2 * maxn];
void add(int p, int val) {
	for (; p < 2 * maxn; p += p & -p) bit[p] += val;
}
int get(int p) {
	int res = 0;
	for (; p > 0; p -= p & -p) res += bit[p];
	return res;
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {scanf("%d", a + i); dc[a[i]];}
	FOR(i, 0, m) {scanf("%d", b + i); dc[b[i]];}
	int cnt = 0;
	FORall(it, dc) dc[it->fi] = ++cnt;
	FOR(i, 0, n) add(dc[a[i]], 1);
	FOR(i, 0, m) printf("%d ", get(dc[b[i]]));
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