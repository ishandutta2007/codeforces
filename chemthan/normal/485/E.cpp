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

const int maxn = 1000010;
int n, m;
char s[maxn];
int p[maxn];
int tmp[2][maxn];
char ans[maxn];

void solve() {
	ms(ans, 0);
	scanf("%s", s);
	n = strlen(s);
	FOR(i, 0, n) p[i] = i;
	scanf("%d", &m);
	while (m--) {
		int k, d; scanf("%d%d", &k, &d);
		bool cnt = 0;
		int l = 0;
		FOR(i, 0, d) for (int j = i; j < k; j += d) tmp[cnt][j] = (n - 1 + l++) % n;
		FOR(i, k, n) tmp[cnt][i] = (i + n - 1) % n;
		FOR(i, 0, n) p[i] = tmp[cnt][p[i]];
		int c = n - k;
		while (c) {
			if (c & 1) FOR(i, 0, n) p[i] = tmp[cnt][p[i]];
			FOR(i, 0, n) tmp[cnt ^ 1][i] = tmp[cnt][tmp[cnt][i]];
			c >>= 1; cnt ^= 1;
		}
		FOR(i, 0, n) {p[i] = (p[i] + n - k + 1) % n; ans[p[i]] = s[i];}
		printf("%s\n", ans);
	}
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