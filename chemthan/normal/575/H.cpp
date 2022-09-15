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

const int maxn = 2000010;
const int mod = 1000000007;
int n;
ll frac[maxn];

ll ex(ll n, int k) {
	if (k == 0) return 1;
	if (k & 1) return n * ex(n, k - 1) % mod;
	ll t = ex(n, k >> 1);
	return t * t % mod;
}

ll combine(int a, int b) {
	if (a == 0 || a == b) return 1;
	if (a > b) return 0;
	return (frac[b] * ex(frac[a], mod - 2) % mod) * ex(frac[b - a], mod - 2) % mod;
}

void build() {
	frac[0] = 1;
	FOR(i, 1, maxn) frac[i] = frac[i - 1] * i % mod;
}

void solve() {
	build();
	scanf("%d", &n);
	printf("%I64d", (combine(n + 1, 2 * n + 2) - 1 + mod) % mod);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}