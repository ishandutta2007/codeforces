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
    int cnt;
    Node() {
        l = r = 0;
        cnt = 0;
    }
};

const int oo = (int) 1e9;
const int MAXN = 50 + 5;
const int MAXM = 4e4 + 5;
int n, k;
int a[MAXM];
int nxt[MAXM];
int f[MAXN][MAXM];
int c[MAXN][MAXM];
Node* ff[MAXM];

Node* upd(Node* p, int i, int L, int R, int val) {
    if (!p) p = new Node();
    if (i < L || i > R) return p;
    if (L == R) {
        Node* res = new Node();
        res->l = p->l, res->r = p->r, res->cnt = p->cnt + val;
        return res;
    }
    Node* res = new Node();
    res->l = upd(p->l, i, L, L + R >> 1, val);
    res->r = upd(p->r, i, (L + R >> 1) + 1, R, val);
    res->cnt = res->l->cnt + res->r->cnt;
    return res;
}

int query(Node* p, int l, int r, int L, int R) {
    if (!p) return 0;
    if (l > R || r < L) return 0;
    if (l <= L && r >= R) return p->cnt;
    return query(p->l, l, r, L, L + R >> 1) + query(p->r, l, r, (L + R >> 1) + 1, R);
}

void divide(int i, int L, int R, int optL, int optR) {
    if (L > R) return;
    int M = L + R >> 1, ptr = optL;
    f[i][M] = -oo;
    int st = min(M - 1, optR);
    int cost = 0;
    if (st + 1 <= M) {
        cost += query(ff[M], M + 1, n + 1, 0, n + 1);
        cost -= query(ff[st], M + 1, n + 1, 0, n + 1);
    }
    for (int k = st; k >= optL; k--) {
        int cur = f[i - 1][k] + cost;
        if (f[i][M] <= cur) {
            f[i][M] = cur;
            ptr = k;
        }
        if (nxt[k] > M) cost++;
    }
    divide(i, L, M - 1, optL, ptr);
    divide(i, M + 1, R, ptr, optR);
}

void solve() {
    cin >> n >> k;
    FOR(i, 1, n + 1) cin >> a[i];
    static int lst[MAXM];
    fill_n(lst, n + 1, n + 1);
    FORd(i, n + 1, 1) {
        nxt[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    FOR(i, 1, n + 1) {
        ff[i] = upd(ff[i - 1], nxt[i], 0, n + 1, 1);
    }
    FOR(i, 1, k + 1) {
        divide(i, 1, n, 0, n);
    }
    cout << f[k][n] << "\n";
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