#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
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
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

const int maxn = 1e3 + 5;
int n, m;
int a[maxn][maxn];
int dp[maxn][maxn][4][4];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int inside(int u, int v) {
	if (!(u >= 0 && u < n)) return 0;
	if (!(v >= 0 && v < m)) return 0;
	return a[u][v] != '*';
}

void solve() {
	cin >> n >> m;
	pi st, ed;
	FOR(i, 0, n) {
		string s; cin >> s;
		FOR(j, 0, m) {
			a[i][j] = s[j];
			if (s[j] == 'S') {
				st = mp(i, j);
			}
			else if (s[j] == 'T') {
				ed = mp(i, j);
			}
		}
	}
	queue<int> que;
	FOR(i, 0, 4) {
		dp[st.fi][st.se][0][i] = 1;
		que.push(st.fi), que.push(st.se), que.push(0), que.push(i);
	}
	while (sz(que)) {
		int u = que.front(); que.pop();
		int v = que.front(); que.pop();
		int d = que.front(); que.pop();
		int p = que.front(); que.pop();
		FOR(dir, 0, 4) {
			int nu = u + dx[dir];
			int nv = v + dy[dir];
			int nd = d + (p != dir);
			if (nd == 3) continue;
			if (inside(nu, nv) && !dp[nu][nv][nd][dir]) {
				dp[nu][nv][nd][dir] = 1;
				que.push(nu), que.push(nv), que.push(nd), que.push(dir);
			}
		}
	}
	FOR(i, 0, 4) FOR(d, 0, 3) if (dp[ed.fi][ed.se][d][i]) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
        JUDGE_ONLINE = 0;
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    if (!JUDGE_ONLINE) {
    	//freopen("out.txt", "w", stdout);
    	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}