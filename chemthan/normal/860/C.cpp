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

const int maxn = 5e5 + 5;
int n;
string s[maxn];
int t[maxn];
map<string, int> hs;
string rb[maxn];
int a[maxn];

int query(string s) {
    if (hs.count(s)) return hs[s];
    int res = sz(hs);
    rb[res] = s;
    return hs[s] = res;
}

int cmp(int i, int j) {
    return a[i] > a[j];
}

void solve() {
    cin >> n;
    FOR(i, 1, n + 1) {
        stringstream ss; ss << i;
        string s; ss >> s;
        query(s);
    }
    int zeros = 0, ones = 0;
    FOR(i, 0, n) {
        cin >> s[i] >> t[i];
        a[i] = query(s[i]);
        if (t[i]) zeros++;
        else ones++;
    }
    set<int> st1, st2;
    FOR(i, 0, zeros) st1.insert(i);
    FOR(i, 0, ones) st2.insert(zeros + i);
    FOR(i, 0, n) {
        if (a[i] < zeros) {
            st1.erase(a[i]);
        }
        else if (a[i] < n) {
            st2.erase(a[i]);
        }
    }
    deque<int> vs[2];
    FOR(i, 0, n) {
        if (t[i] && a[i] < zeros) {
        }
        else if (!t[i] && a[i] >= zeros && a[i] < n) {
        }
        else {
            vs[t[i]].pb(i);
        }
    }
    sort(all(vs[0]), cmp);
    sort(all(vs[1]), cmp);
    vii res;
    while (sz(vs[0]) + sz(vs[1])) {
        int u = sz(vs[1]) ? vs[1].back() : -1;
        int v = sz(vs[0]) ? vs[0].back() : -1;
        if (~u && sz(st1)) {
            vs[1].pop_back();
            int k = *st1.begin();
            st1.erase(k);
            res.pb(mp(a[u], k));
            if (a[u] >= zeros && a[u] < n) {
                st2.insert(a[u]);
            }
        }
        else if (~v && sz(st2)) {
            vs[0].pop_back();
            int k = *st2.begin();
            st2.erase(k);
            res.pb(mp(a[v], k));
            if (a[v] < zeros) {
                st1.insert(a[v]);
            }
        }
        else {
            int u;
            if (!sz(vs[0])) {
                u = vs[1].back();
            }
            else if (!sz(vs[1])) {
                u = vs[0].back();
            }
            else {
                int x = vs[0].back();
                int y = vs[1].back();
                if (a[x] < a[y]) {
                    u = x;
                }
                else {
                    u = y;
                }    
            }    
            string s = ""; FOR(i, 0, 6) s += char('a' + rand() % 26);
            int x = query(s);
            res.pb(mp(a[u], x));
            if (a[u] < zeros) {
                st1.insert(a[u]);
            }
            else if (a[u] < n) {
                st2.insert(a[u]);
            }
            if (sz(vs[0]) && vs[0].back() == u) {
                vs[0].pop_back();
                vs[0].push_front(u);
            }
            if (sz(vs[1]) && vs[1].back() == u) {
                vs[1].pop_back();
                vs[1].push_front(u);
            }
            a[u] = x;
        }
    }
    cout << sz(res) << "\n";
    FOR(i, 0, sz(res)) cout << "move " << rb[res[i].fi] << " " << rb[res[i].se] << "\n";
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