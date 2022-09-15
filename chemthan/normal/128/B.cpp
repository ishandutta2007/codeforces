#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int MAXN = 100010;
const int MAXC = 26;
struct state {
	int len, link, fpos;
	int nxt[MAXC];
};
struct SuffixAutomaton {
	state st[MAXN << 1];
	int nsz, last;
	int cnt[MAXN << 1];
	long long nchild[MAXN << 1];
	void init() {
		st[0].len = 0;
		st[0].link = -1;
		st[0].fpos = 0;
		memset(st[0].nxt, -1, sizeof(st[0].nxt));
		nsz = 1; last = 0;
		cnt[0] = nchild[0] = 0;
	}
	void extend(char c) {
		int cur = nsz++;
		st[cur].len = st[last].len + 1;
		st[cur].fpos = st[cur].len - 1;
		memset(st[cur].nxt, -1, sizeof(st[cur].nxt));
		cnt[cur] = 1; nchild[cur] = 0;
		int p;
		for (p = last; ~p && !~st[p].nxt[c]; p = st[p].link) st[p].nxt[c] = cur;
		if (!~p) st[cur].link = 0;
		else {
			int q = st[p].nxt[c];
			if (st[p].len + 1 == st[q].len) st[cur].link = q;
			else {
				int clone = nsz++;
				st[clone].len = st[p].len + 1;
				memcpy(st[clone].nxt, st[q].nxt, sizeof(st[q].nxt));
				st[clone].link = st[q].link;
				st[clone].fpos = st[q].fpos;
				cnt[clone] = 0; nchild[clone] = 0;
				for (; ~p && st[p].nxt[c] == q; p = st[p].link) st[p].nxt[c] = clone;
				st[q].link = st[cur].link = clone;
			}
		}
		last = cur;
	}
	long long update(int u) {
		if (nchild[u]) return nchild[u];
		nchild[u] = cnt[u];
		for (int i = 0; i < MAXC; i++) {
			if (~st[u].nxt[i]) {
				nchild[u] += update(st[u].nxt[i]);
			}
		}
		return nchild[u];
	}
	void updatesize() {
		vector<int> v, vis(nsz, 0);
		queue<int> q;
		q.push(0); vis[0] = 1;
		while (q.size()) {
			int u = q.front(); q.pop();
			v.push_back(u);
			for (int i = 0; i < MAXC; i++) {
				if (~st[u].nxt[i] && !vis[st[u].nxt[i]]) {
					q.push(st[u].nxt[i]);
					vis[st[u].nxt[i]] = 1;
				}
			}
		}
		for (int i = v.size() - 1; i > 0; i--) {
			int u = v[i];
			cnt[st[u].link] += cnt[u];
		}
	}
	void kth(int u, int k) {
		if (k <= 0) return;
		int tot = 0;
		for (int i = 0; i < MAXC; i++) {
			if (~st[u].nxt[i]) {
				int v = st[u].nxt[i];
				if (tot + nchild[v] >= k) {
					printf("%c", 'a' + i);
					kth(v, k - tot - cnt[v]);
					return;
				}
				tot += nchild[v];
			}
		}
	}
} sa;

char s[MAXN];

void solve() {
	int k; scanf("%s%d", s, &k);
	int n = strlen(s);
	sa.init();
	FOR(i, 0, n) {
		sa.extend(s[i] - 'a');
	}
	sa.updatesize();
	sa.update(0);
	if (k > sa.nchild[0]) {
		puts("No such line.");
	}
	else {
		sa.kth(0, k);
		printf("\n");
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}