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
int p[maxn], q[maxn];
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
		FOR(i, 0, d) for (int j = i; j < k; j += d) tmp[cnt][(n - 1 + l++) % n] = j;
		FOR(i, k, n) tmp[cnt][(i + n - 1) % n] = i;
		FOR(i, 0, n) q[i] = p[tmp[cnt][i]]; FOR(i, 0, n) p[i] = q[i];
		int c = n - k;
		while (c) {
			if (c & 1) {FOR(i, 0, n) q[i] = p[tmp[cnt][i]]; FOR(i, 0, n) p[i] = q[i];}
			FOR(i, 0, n) tmp[cnt ^ 1][i] = tmp[cnt][tmp[cnt][i]];
			c >>= 1; cnt ^= 1;
		}
		FOR(i, 0, n) {q[i] = p[(i + k - 1) % n]; printf("%c", s[q[i]]);} printf("\n");
		FOR(i, 0, n) p[i] = q[i];
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