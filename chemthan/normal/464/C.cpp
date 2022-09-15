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
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 100010;
char s[maxn];
int n;
int d[maxn];
string t[maxn];
int f[10][maxn];
int g[10][maxn];

int ex(int n, int k) {
	if (!k) return 1;
	if (k & 1) return 1LL * n * ex(n, k - 1) % mod;
	int t = ex(n, k >> 1);
	return 1LL * t * t % mod;
}

void go(int k) {
	FOR(i, 0, 10) {f[i][k] = 1; g[i][k] = i;}
	if (k == n) return;
	go(k + 1);
	FOR(i, 0, 10) {f[i][k] = f[i][k + 1]; g[i][k] = g[i][k + 1];}
	f[d[k]][k] = g[d[k]][k] = 0;
	int cur = 0;
	FORd(i, sz(t[k]), 0) {
		f[d[k]][k] = (f[d[k]][k] + f[t[k][i] - '0'][k + 1]) % (mod - 1);
		g[d[k]][k] = (g[d[k]][k] + 1LL * g[t[k][i] - '0'][k + 1] * ex(10, cur)) % mod;
		cur = (cur + f[t[k][i] - '0'][k + 1]) % (mod - 1);
	}
}

void solve() {
	cin>>s>>n; n++;
	d[0] = 0; t[0] = s;
	FOR(i, 1, n) {
		cin>>t[i];
		d[i] = t[i][0] - '0';
		t[i] = t[i].substr(3);
	}
	go(0); printf("%d", g[0][0]);
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