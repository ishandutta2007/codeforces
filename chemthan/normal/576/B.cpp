#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 100010;
int n;
int p[maxn];
vi cyc[maxn];
bool vis[maxn];

void dfs(int u, int cnt) {
	vis[u] = 1;
	cyc[cnt].push_back(u);
	int k = p[u];
	if (!vis[k]) dfs(k, cnt);
}

void solve() {
	ms(vis, 0);
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", p + i + 1);
	int cnt = 0;
	FOR(i, 1, n + 1) if (!vis[i]) dfs(i, cnt++);
	int dmin = INT_MAX, imin, g = 0;
	FOR(i, 0, cnt) {
		if (dmin > sz(cyc[i])) {dmin = sz(cyc[i]); imin = i;}
		if (!g) g = sz(cyc[i]); else g = gcd(g, sz(cyc[i]));
	}
	if (dmin > 2) {printf("NO"); return;}
	if (dmin == 2) {
		if (g & 1) {printf("NO"); return;}
		cout<<"YES\n"<<cyc[imin][0]<<" "<<cyc[imin][1]<<"\n";
		FOR(i, 0, cnt) if (i != imin) {
			FOR(j, 0, sz(cyc[i])) {
				if (j & 1) cout<<cyc[imin][0]<<" "<<cyc[i][j]<<"\n";
				else cout<<cyc[imin][1]<<" "<<cyc[i][j]<<"\n";
			}
		}
		return;
	}
	cout<<"YES\n";
	FOR(i, 1, n + 1) if (i != cyc[imin][0]) cout<<cyc[imin][0]<<" "<<i<<"\n";
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