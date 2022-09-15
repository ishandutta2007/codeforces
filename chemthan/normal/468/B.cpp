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

#define maxv 200010
#define pos(v) ((v) << 1)
#define neg(v) (pos(v) ^ 1)
namespace twosat {
	int n;
	vector<int> forward[maxv], backward[maxv];
	bool used[maxv];
	int cnt, order[maxv], comp[maxv];
	void init(int _n) {
		n = _n;
		for (int i = 0; i < n; i++) {
			forward[i].clear();
			backward[i].clear();
		}
	}
	void add(int u, int v) {
		forward[u].push_back(v);
		backward[v].push_back(u);
	}
	void dfs1(int u) {
		used[u] = true;
		for (int i = 0; i < forward[u].size(); i++) {
			int v = forward[u][i];
			if (!used[v]) dfs1(v);
		}
		order[cnt++] = u;
	}
	void dfs2(int u, int c) {
		comp[u] = c;
		for (int i = 0; i < backward[u].size(); i++) {
			int v = backward[u][i];
			if (comp[v] == -1) dfs2(v, c);
		}
	}
	bool solve(vector<int> &res) {
		cnt = 0;
		memset(used, 0, sizeof(used));
		for (int u = 0; u < n; u++) if (!used[u]) dfs1(u);
		memset(comp, -1, sizeof(comp));
		int c = 0;
		for (int i = n - 1; i >= 0; i--) {
			int u = order[i];
			if (comp[u] == -1) dfs2(u, c++);
		}
		for (int u = 0; u < n; u += 2)
			if (comp[u] == comp[u ^ 1]) return false;
		res.clear();
		for (int u = 0; u < n; u += 2) {
			int choose = (comp[u] > comp[u ^ 1]) ? u : u ^ 1;
			if (!(choose & 1)) res.push_back(choose >> 1);
		}
		return true;
	}
}

const int maxn = 100010;
int n, a, b;
int p[maxn];
map<int, int> mp;
bool ans[maxn];

void solve() {
    ms(ans, 1);
    scanf("%d%d%d", &n, &a, &b);
    FOR(i, 0, n) {scanf("%d", p + i); mp[p[i]];}
    int cnt = 0;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        mp[it->first] = cnt++;
    }
    twosat::init(n << 1);
    FOR(i, 0, n) {
        bool flag = 0;
        if (mp.count(a - p[i])) {
            twosat::add(mp[p[i]] << 1, mp[a - p[i]] << 1);
            twosat::add((mp[a - p[i]] << 1) + 1, (mp[p[i]] << 1) + 1);
            flag = 1;
        }
        else twosat::add(mp[p[i]] << 1, (mp[p[i]] << 1) + 1);
        if (mp.count(b - p[i])) {
            twosat::add((mp[p[i]] << 1) + 1, (mp[b - p[i]] << 1) + 1);
            twosat::add(mp[b - p[i]] << 1, mp[p[i]] << 1);
            flag = 1;
        }
        else twosat::add((mp[p[i]] << 1) + 1, mp[p[i]] << 1);
        if (!flag) {printf("NO"); return;}
    }
    vi res; if (!twosat::solve(res)) {printf("NO"); return;}
    FOR(i, 0, sz(res)) ans[res[i]] = 0;
    printf("YES\n"); FOR(i, 0, n) printf("%d ", ans[mp[p[i]]]);
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