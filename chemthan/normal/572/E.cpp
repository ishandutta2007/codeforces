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

const int maxn = 200010;
int n, m;
set<int> st[maxn];
set<pi> li;
vi v[maxn];
int ans[maxn];

void solve() {
	ms(ans, 0);
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		int k; scanf("%d", &k);
		FOR(j, 0, k) {
			int x; scanf("%d", &x);
			st[i].insert(x);
			v[abs(x)].push_back(i);
		}
		li.insert(make_pair(sz(st[i]), i));
	}
	while (sz(li)) {
		set<pi>::iterator it = li.begin();
		int i = it->second; li.erase(it);
		int k = *st[i].begin();
		ans[abs(k)] = k > 0 ? 1 : 0;
		FOR(j, 0, sz(v[abs(k)])) {
			int u = v[abs(k)][j];
			if (u != i) {
				set<pi>::iterator it = li.find(make_pair(sz(st[u]), u));
				if (it == li.end()) continue; li.erase(it);
				if (st[u].find(k) == st[u].end()) {
					st[u].erase(-k);
					if (sz(st[u])) li.insert(make_pair(sz(st[u]), u)); else {printf("NO"); return;}
				}
			}
		}
	}
	printf("YES\n"); FOR(i, 1, m + 1) if (ans[i]) printf("1"); else printf("0");
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