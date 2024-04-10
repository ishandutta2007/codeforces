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

const int maxn = 60;
const int maxc = 30;
int n;
char s[maxn][maxc];
ll f[1 << 21];
ld g[1 << 21];

int popcount(ll k) {
	int res = 0;
	FOR(i, 0, maxn) if (k & 1LL << i) res++;
	return res;
}

void solve() {
	ms(s, 0); ms(f, 0); ms(g, 0);
	scanf("%d", &n);
	ld ans = 0;
	FOR(i, 0, n) scanf("%s", s + i);
	int len = strlen(s[0]);
	FOR(i, 0, n) FOR(j, i + 1, n) {
		int mask = 0;
		FOR(k, 0, len) if (s[i][k] == s[j][k]) mask |= 1 << k;
		f[mask] |= 1LL << i;
		f[mask] |= 1LL << j;
	}
	FORd(i, 1 << len, 0) FOR(j, 0, len) if (i & 1 << j) f[i ^ 1 << j] |= f[i];
	FOR(i, 0, 1 << len) f[i] = n - popcount(f[i]);
	g[0] = 1;
	FOR(i, 1, 1 << len) {
		int size = popcount(i);
		FOR(j, 0, len) if (i & 1 << j) {
			g[i] += g[i ^ 1 << j] / (len - size + 1);
			ans += 1.0 * (f[i] - f[i ^ 1 << j]) / n * size * g[i ^ 1 << j] / (len - size + 1);
		}
	}
	cout<<fixed<<setprecision(9)<<ans;
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