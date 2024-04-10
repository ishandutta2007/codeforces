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

const int maxn = 410;
const int maxc = 26;
char s[maxc];
int n, m;
char t[maxn];
vi adj[maxn];
vi radj[maxn];
bool vis[maxn];
int comp[maxn];
vi tpo;
int ans[maxn];

void add(int u, int v) {
	adj[u].push_back(v);
	radj[v].push_back(u);
	adj[v ^ 1].push_back(u ^ 1);
	radj[u ^ 1].push_back(v ^ 1);
}

void add(int i) {
	if (s[ans[i]] == 'V') add(i << 1, (i << 1) + 1); else add((i << 1) + 1, i << 1);
}

void del(int i) {
	int u = (i << 1) + 1;
	int v = i << 1;
	if (s[ans[i]] == 'V') {u = i << 1; v = (i << 1) + 1;}
	adj[u].pop_back();
	radj[v].pop_back();
	adj[v ^ 1].pop_back();
	radj[u ^ 1].pop_back();
}

void dfs1(int u) {
	vis[u] = 1;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (!vis[v]) dfs1(v);
	}
	tpo.push_back(u);
}

void dfs2(int u, int k) {
	vis[u] = 1;
	comp[u] = k;
	FOR(i, 0, sz(radj[u])) {
		int v = radj[u][i];
		if (!vis[v]) dfs2(v, k);
	}
}

bool check() {
	tpo.clear(); ms(vis, 0); ms(comp, -1);
	FOR(i, 0, 2 * n) if (!vis[i]) dfs1(i);
	int cnt = 0; ms(vis, 0);
	FORd(i, sz(tpo), 0) {
		int u = tpo[i];
		if (!vis[u]) dfs2(u, cnt++);
	}
	FOR(i, 0, n) if (comp[i << 1] == comp[(i << 1) + 1]) return 0;
	return 1;
}

void solve() {
	scanf("%s", s); int len = strlen(s);
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) {
		char type1[10], type2[10];
		int pos1, t1, pos2, t2; scanf("%d%s%d%s", &pos1, type1, &pos2, type2);
		pos1--; pos2--; t1 = type1[0] == 'V'; t2 = type2[0] == 'V';
		add((pos1 << 1) + t1, (pos2 << 1) + t2);
	}
	scanf("%s", t);
	bool flag = 0; FOR(i, 0, len) if (s[i] == 'V') flag = 1;
	if (!flag) FOR(i, 0, n) add((i << 1) + 1, i << 1);
	flag = 0; FOR(i, 0, len) if (s[i] == 'C') flag = 1;
	if (!flag) FOR(i, 0, n) add(i << 1, (i << 1) + 1);
	FOR(i, 0, n) {ans[i] = t[i] - 'a'; add(i);}
	FORd(i, n, 0) {
		del(i);
		int low = t[i] - 'a';
		if (i < n - 1) low++;
		bool flag1 = 0, flag2 = 0;
		FOR(j, low, len) {
			if (flag1 && s[j] == 'V') continue;
			if (flag2 && s[j] == 'C') continue;
			if (s[j] == 'V') flag1 = 1; else flag2 = 1;
			ans[i] = j; add(i);
			if (check()) {
				FOR(k, i + 1, n) {
					bool flag1 = 0, flag2 = 0;
					FOR(l, 0, len) {
						if (flag1 && s[l] == 'V') continue;
						if (flag2 && s[l] == 'C') continue;
						if (s[l] == 'V') flag1 = 1; else flag2 = 1;
						ans[k] = l; add(k);
						if (check()) break;
						del(k);
					}
				}
				FOR(k, 0, n) printf("%c", ans[k] + 'a');
				return;
			}
			del(i);
		}
	}
	printf("-1");
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