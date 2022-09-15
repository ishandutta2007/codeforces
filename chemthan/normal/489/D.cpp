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

const int maxn = 3010;
int n, m;
vi adj[maxn];
int cnt[maxn];

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		adj[a].push_back(b);
	}
	int ans = 0;
	FOR(i, 0, n) {
		ms(cnt, 0);
		FOR(j, 0, sz(adj[i])) {
			int k = adj[i][j];
			FOR(u, 0, sz(adj[k])) {
				int v = adj[k][u];
				if (v != i) cnt[v]++;
			}
		}
		FOR(i, 0, n) if (cnt[i]) ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	printf("%d", ans);
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