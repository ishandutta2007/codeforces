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

const int maxn = 100 + 5;
int n, m;
int a[maxn][maxn];
int d[maxn][maxn];
int fromx[maxn][maxn];
int fromy[maxn][maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
string dir[] = {"D", "U", "R", "L"};

int inside(int u, int v) {
    if (!(u >= 0 && u < n)) return 0;
    if (!(v >= 0 && v < m)) return 0;
    return 1;
}

int okmove(int u, int v) {
    if (!inside(u, v)) return 1;
    return a[u][v] != '*';
}

int x, y;
pi ask(string dir) {
    cout << dir << "\n";
    cout.flush();
    int x, y; cin >> x >> y;
    return mp(x, y);
}

void init() {
    int t = 0;
    for (int d = 0; d < 4; d += 2) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        int nnx = x + dx[d ^ 1];
        int nny = y + dy[d ^ 1];
        if (okmove(nx, ny) && okmove(nnx, nny)) {
            if (ask(dir[d]) == mp(nx + 1, ny + 1)) {
                ask(dir[d ^ 1]);
            }
            else {
                swap(dir[d], dir[d ^ 1]);
            }
            t = d ^ 2;
            break;
        }
    }
    FOR(it, 0, 200) {
        int nx = x + dx[t];
        int ny = y + dy[t];
        int nnx = x + dx[t ^ 1];
        int nny = y + dy[t ^ 1];
        if (okmove(nx, ny) && okmove(nnx, nny)) {
            if (ask(dir[t]) == mp(nx + 1, ny + 1)) {
                ask(dir[t ^ 1]);
            }
            else {
                swap(dir[t], dir[t ^ 1]);
            }
            break;
        }
        pi res = ask(dir[t ^ 2]);
        x = res.fi - 1, y = res.se - 1;
    }
}

void solve() {
    cin >> n >> m;
    int edx = 0, edy = 0;
    FOR(i, 0, n) {
        string s; cin >> s;
        FOR(j, 0, m) {
            a[i][j] = s[j];
            if (s[j] == 'F') {
                edx = i, edy = j;
            }
        }
    }
    init();
    FOR(i, 0, n) FOR(j, 0, m) d[i][j] = INF;
    queue<int> que;
    que.push(x), que.push(y);
    d[x][y] = 0;
    while (sz(que)) {
        int u = que.front(); que.pop();
        int v = que.front(); que.pop();
        FOR(dd, 0, 4) {
            int nu = u + dx[dd];
            int nv = v + dy[dd];
            if (inside(nu, nv) && a[nu][nv] != '*' && chkmin(d[nu][nv], d[u][v] + 1)) {
                que.push(nu), que.push(nv);
                fromx[nu][nv] = u;
                fromy[nu][nv] = v;
            }
        }
    }
    vii path;
    while (mp(edx, edy) != mp(x, y)) {
        path.pb(mp(edx, edy));
        int nx = fromx[edx][edy];
        int ny = fromy[edx][edy];
        edx = nx, edy = ny;
    }
    reverse(all(path));
    FOR(i, 0, sz(path)) {
        FOR(d, 0, 4) {
            if (x + dx[d] == path[i].fi && y + dy[d] == path[i].se) {
                ask(dir[d]);
                break;
            }
        }
        x = path[i].fi, y = path[i].se;
    }
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        //ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}