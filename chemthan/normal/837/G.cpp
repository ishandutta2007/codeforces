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
const int MOD2 = 1007681537;
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

struct Node {
    Node *l, *r;
    long long suma, sumb, sumy1, sumy2;
    Node() {
        l = r = 0;
        suma = sumb = sumy1 = sumy2 = 0;
    }
};

int ptr = 0;
Node mem[20000000];

Node* newNode() {
    return mem + (ptr++);
}

Node* upd(Node* p, int i, int L, int R, long long suma, long long sumb, long long sumy1, long long sumy2) {
    if (!p) p = newNode();
    if (i < L || i > R) return p;
    if (L == R) {
        Node* res = newNode();
        res->l = p->l, res->r = p->r;
        res->suma = p->suma + suma;
        res->sumb = p->sumb + sumb;
        res->sumy1 = p->sumy1 + sumy1;
        res->sumy2 = p->sumy2 + sumy2;
        return res;
    }
    Node* res = newNode();
    res->l = upd(p->l, i, L, L + R >> 1, suma, sumb, sumy1, sumy2);
    res->r = upd(p->r, i, (L + R >> 1) + 1, R, suma, sumb, sumy1, sumy2);
    res->suma = res->l->suma + res->r->suma;
    res->sumb = res->l->sumb + res->r->sumb;
    res->sumy1 = res->l->sumy1 + res->r->sumy1;
    res->sumy2 = res->l->sumy2 + res->r->sumy2;
    return res;
}

struct Res {
    long long suma, sumb, sumy1, sumy2;
    Res(long long suma = 0, long long sumb = 0, long long sumy1 = 0, long long sumy2 = 0) : suma(suma), sumb(sumb), sumy1(sumy1), sumy2(sumy2) {}
    Res operator + (const Res& rhs) {
        Res res;
        res.suma = suma + rhs.suma;
        res.sumb = sumb + rhs.sumb;
        res.sumy1 = sumy1 + rhs.sumy1;
        res.sumy2 = sumy2 + rhs.sumy2;
        return res;
    }
};

Res query(Node* p, int l, int r, int L, int R) {
    if (!p) return Res();
    if (l > R || r < L) return Res();
    if (l <= L && r >= R) return Res(p->suma, p->sumb, p->sumy1, p->sumy2);
    return query(p->l, l, r, L, (L + R >> 1)) +  query(p->r, l, r, (L + R >> 1) + 1, R);
}

#define x1 x123
#define y1 y123
#define x2 x456
#define y2 y456
const int maxn = 2e5 + 5;
int n, q;
int x1[maxn];
int x2[maxn];
int y1[maxn];
int y2[maxn];
int a[maxn];
int b[maxn];
Node* fa[4][maxn];
Node* fb[4][maxn];
long long suma[maxn];
long long sumb[maxn];

void solve() {
    cin >> n;
    FOR(i, 1, n + 1) {
        cin >> x1[i] >> x2[i] >> y1[i] >> a[i] >> b[i] >> y2[i];
        fa[0][i] = upd(fa[0][i - 1], x1[i], 0, maxn - 1, a[i], b[i], y1[i], 0);
        
        fa[1][i] = upd(fa[1][i - 1], x2[i], 0, maxn - 1, a[i], b[i], 0, y2[i]);
        
        suma[i] = suma[i - 1];
        suma[i] += a[i];
        
        sumb[i] = sumb[i - 1];
        sumb[i] += b[i];
    }
    cin >> q;
    long long ans = 0;
    while (q--) {
        int l, r, x; cin >> l >> r >> x; x = (x + ans) % INF;
        int xx = min(x, maxn - 1);
        long long sa = suma[r] - suma[l - 1];
        long long sb = sumb[r] - sumb[l - 1];
        
        Res r0 = query(fa[0][r], xx, maxn - 1, 0, maxn - 1);
        Res r1 = query(fa[1][r], 0, xx - 1, 0, maxn - 1);
        
        Res l0 = query(fa[0][l - 1], xx, maxn - 1, 0, maxn - 1);
        Res l1 = query(fa[1][l - 1], 0, xx - 1, 0, maxn - 1);
        
        sa -= r0.suma;
        sa += l0.suma;
        
        sb -= r0.sumb;
        sb += l0.sumb;
        
        sa -= r1.suma;
        sa += l1.suma;
        
        sb -= r1.sumb;
        sb += l1.sumb;
        
        long long sy1 = 0, sy2 = 0;
        sy1 += r0.sumy1;
        sy1 -= l0.sumy1;
        
        sy2 += r1.sumy2;
        sy2 -= l1.sumy2;
        
        ans = sa * x + sb + sy1 + sy2;
        cout << ans << "\n";
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
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}