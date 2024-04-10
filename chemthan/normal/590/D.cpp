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

const int maxn = 151;
int n, k, s;
int a[maxn];
int f[2][maxn][15000];

void solve() {
	ms(f, 0x3f);
	scanf("%d%d%d", &n, &k, &s);
	FOR(i, 0, n) scanf("%d", a + i);
	int d = min(12000, s + k * (k - 1) / 2);
	bool cnt = 0;
	FOR(i, 0, d + 1) f[cnt][0][i] = 0;
	FOR(i, 0, n) {
		FOR(j, 0, k + 1) FOR(l, 0, d + 1) {
			f[cnt ^ 1][j][l] = f[cnt][j][l];
			if (l) f[cnt ^ 1][j][l] = min(f[cnt ^ 1][j][l], f[cnt][j][l - 1]);
		}
		FOR(j, 1, k + 1) FOR(l, 0, d + 1) {
			if (l >= i) f[cnt ^ 1][j][l] = min(f[cnt ^ 1][j][l], f[cnt][j - 1][l - i] + a[i]);
		}
		cnt ^= 1;
	}
	printf("%d", f[cnt][k][d]);
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