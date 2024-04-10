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
const int FFTMOD = 1007681537;
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
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 1000 + 5;
int n, m, k;
int a[maxn][maxn];
int x[2], y[2];
int dp[maxn][maxn];
int f[4][maxn][maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

pi row[maxn][maxn << 1];
pi col[maxn][maxn << 1];

void upd(pi st[], int p, pi val) {
    for (st[p += maxn] = val; p > 1; ) p >>= 1, st[p] = max(st[p << 1], st[p << 1 | 1]);
}
pi query(pi st[], int l, int r) {
    pi res;
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) chkmax(res, st[l++]);
        if (r & 1) chkmax(res, st[--r]);
    }
    return res;
}

void rem(int r, int c) {
    upd(row[r], c, mp(0, c));
    upd(col[c], r, mp(0, r));
}

int inside(int u, int v) {
    if (!(u >= 0 && u < n)) return 0;
    if (!(v >= 0 && v < m)) return 0;
    return 1;
}

int calc(int dir, int x, int y) {
    int& res = f[dir][x][y];
    if (~res) return res;
    res = 0;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (inside(nx, ny) && a[nx][ny] == '.') {
        res = calc(dir, nx, ny) + 1;
    }
    return res;
}

void solve() {
    ms(f, -1);
    cin >> n >> m >> k;
    FOR(i, 0, n) {
        string s; cin >> s;
        FOR(j, 0, m) a[i][j] = s[j];
    }
    FOR(i, 0, n) FOR(j, 0, m) {
        upd(row[i], j, mp(1, j));
        upd(col[j], i, mp(1, i));
    }
    FOR(i, 0, 2) cin >> x[i] >> y[i], x[i]--, y[i]--;
    FOR(i, 0, n) FOR(j, 0, m) dp[i][j] = INF;
    queue<int> que;
    dp[x[0]][y[0]] = 0, que.push(x[0]), que.push(y[0]);
    rem(x[0], y[0]);
    while (sz(que)) {
        int u = que.front(); que.pop();
        int v = que.front(); que.pop();
        FOR(dir, 0, 4) {
            int mx = calc(dir, u, v);
            chkmin(mx, k);
            if (mx) {
                while (1) {
                    pi r;
                    if (dir == 0) {
                        r = query(col[v], u + 1, u + mx);
                    }
                    else if (dir == 1) {
                        r = query(col[v], u - mx, u - 1);
                    }
                    else if (dir == 2) {
                        r = query(row[u], v + 1, v + mx);
                    }
                    else {
                        r = query(row[u], v - mx, v - 1);
                    }
                    if (r.fi) {
                        int nu, nv;
                        if (dir < 2) {
                            nu = r.se;
                            nv = v;
                        }
                        else {
                            nu = u;
                            nv = r.se;
                        }
                        dp[nu][nv] = dp[u][v] + 1, que.push(nu), que.push(nv);
                        rem(nu, nv);
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
    if (dp[x[1]][y[1]] == INF) dp[x[1]][y[1]] = -1;
    cout << dp[x[1]][y[1]] << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int JUDGE_ONLINE = 1;
    if (argc > 1) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[2], "w", stdout));
    }
    solve();
    if (!JUDGE_ONLINE) {
        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}