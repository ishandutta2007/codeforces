#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second
 
using namespace std;
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
 
const int N = 2020;
 
int n, a[N];
int m, b[N];
 
inline bool read() {
    if (!(cin >> n)) return false;
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
    assert(cin >> m);
    forn(i, m) assert(scanf("%d", &b[i]) == 1);
    return true;
}
 
li sa, sb;
 
inline void solve() {
    sa = accumulate(a, a + n, 0ll);
    sb = accumulate(b, b + m, 0ll);
 
    li ansv = INF64;
    vector<pt> ansp;
 
    {
        li curv = abs(sa - sb);
        if (ansv > curv) {
            ansv = curv;
            ansp.clear();
        }
    }
 
    forn(i, n)
        forn(j, m) {
            sa += b[j] - a[i];
            sb += a[i] - b[j];
            li curv = abs(sa - sb);
            if (ansv > curv) {
                ansv = curv;
                ansp.clear();
                ansp.pb(mp(i, j));
            }
            sa -= b[j] - a[i];
            sb -= a[i] - b[j];
        }
 
    map<li, pt> z;
    forn(j, n)
        forn(i, j)
            z[2ll * (a[i] + a[j])] = mp(i, j);
 
    forn(j, m)
        forn(i, j) {
            li val = sa - sb + 2ll * (b[i] + b[j]);
            auto it = z.lower_bound(val);
            if (it != z.begin()) it--;
            forn(k, 2) {
                if (it == z.end()) break;
                li curv = abs(val - it->x);
                pt p = it->y;
                assert(abs(sa - 2ll * (a[p.x] + a[p.y]) - (sb - 2ll * (b[i] + b[j]))) == curv);
                if (ansv > curv) {
                    ansv = curv;
                    ansp.clear();
                    ansp.pb(mp(p.x, i));
                    ansp.pb(mp(p.y, j));
                }
                it++;
            }
        }
 
    assert(ansv != INF64);
    cout << ansv << endl;
    cout << sz(ansp) << endl;
    forn(i, sz(ansp)) cout << ansp[i].x + 1 << ' ' << ansp[i].y + 1 << endl;
}
 
int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif
   
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
 
    while (read()) {
        solve();
        //break;
    }
   
    return 0;
}