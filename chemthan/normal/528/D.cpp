#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 200010;
const int maxc = 4;
int n, m, k;
char s[maxn];
char t[maxn];
int f[256];
int cnt[maxc][maxn];
bitset<maxn> a[maxc], b;

void solve() {
	f['A'] = 0; f['T'] = 1; f['G'] = 2; f['C'] = 3;
	ms(cnt, 0);
	scanf("%d%d%d%s%s", &n, &m, &k, s, t);
	FOR(i, 0, n) {
		FOR(j, 0, maxc) cnt[j][i + 1] = cnt[j][i];
		cnt[f[s[i]]][i + 1]++;
	}
	FOR(i, 0, n) FOR(j, 0, maxc) if (cnt[j][min(n, i + k + 1)] > cnt[j][max(0, i - k)]) a[j].set(i);
	FOR(i, 0, n - m + 1) b.set(i);
	FOR(i, 0, m) b &= a[f[t[i]]] >> i;
	printf("%d", b.count());
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