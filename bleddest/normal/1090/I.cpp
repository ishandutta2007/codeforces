#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))

#define puts sykk

#define mp make_pair
#define pb push_back

#define x first
#define y second

typedef long long li;
typedef unsigned long long uli;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream &out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream &out, const vector<A> &v) {
    out << "[";
    forn(i, sz(v)) {
        if(i) out << " ";
        out << v[i];
    }
    return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

uli n, x, y, z, b0, b1;
li l, r;

bool read() {
    if(!(cin >> n >> l >> r >> x >> y >> z >> b0 >> b1))
        return false;
    return true;
}

const int N = 10 * 1000 * 1000 + 555;

uli b[N];
li a[N];

void solve() {
    b[0] = b0, b[1] = b1;
    fore(i, 2, n) {
        b[i] = (b[i - 2] * x + b[i - 1] * y + z) & ((1ll << 32) - 1);
    }

    forn(i, n)
        a[i] = b[i] % (r - l + 1) + l;

    li curMin = INF64;
    li ans = LONG_LONG_MAX;
    forn(i, n) {
        if(curMin < a[i])
            ans = min(ans, curMin * a[i]);

        curMin = min(curMin, a[i]);
    }

    {
        vector<li> ca;
        forn(i, n)
            if(a[i] < 0)
                ca.pb(-a[i]);

        vector<li> s;
        forn(i, sz(ca)) {
            while(!s.empty() && s.back() > ca[i]) {
                ans = min(ans, s.back() * ca[i]);
                s.pop_back();
            }
            s.pb(ca[i]);
        }
    }

    if(ans == LONG_LONG_MAX)
        cout << "IMPOSSIBLE\n";
    else
        cout << ans << '\n';
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int tc = 1;
    cin >> tc;

    while(tc--) {
        read();
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
#endif
    }
    return 0;
}