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

const int maxn = 1000010;
int n;
int a[maxn];
map<int, int> dc;
int cnt[maxn];
int f[maxn];
int g[maxn];

ll bit[maxn];
void add(int p, int val) {
	for (; p < maxn; p += p & -p) bit[p] += val;
}
int get(int p) {
	ll res = 0;
	for (; p > 0; p -= p & -p) res += bit[p];
	return res;
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {scanf("%d", a + i); dc[a[i]];}
	int d = 0; FORall(it, dc) dc[it->fi] = d++;
	FOR(i, 0, n) f[i] = ++cnt[dc[a[i]]];
	ms(cnt, 0);
	FORd(i, n, 0) g[i] = ++cnt[dc[a[i]]];
	ll ans = 0;
	FORd(i, n, 0) {
		ans += get(f[i]);
		add(g[i] + 1, 1);
	}
	printf("%I64d", ans);
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