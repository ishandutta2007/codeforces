#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

ll n,S;
vpl p;

struct Fraction {
    ll n,d;
    Fraction() { n = 0, d = 1; }
    Fraction(ll _n, ll _d) {
        n = _n, d = _d;
        /*ll g = __gcd(n,d);
        n /= g, d /= g;*/
        if (d < 0) n *= -1, d *= -1;
    }
};

Fraction abs(Fraction F) { return Fraction(abs(F.n),F.d); }
    
bool operator<(const Fraction& l, const Fraction& r) { return l.n*r.d < r.n*l.d; }
bool operator==(const Fraction& l, const Fraction& r) { return l.n == r.n && l.d == r.d; }
bool operator!=(const Fraction& l, const Fraction& r) { return !(l == r); }

Fraction operator+(const Fraction& l, const Fraction& r) { return Fraction(l.n*r.d+r.n*l.d,l.d*r.d); }
Fraction operator-(const Fraction& l, const Fraction& r) { return Fraction(l.n*r.d-r.n*l.d,l.d*r.d); }
Fraction operator*(const Fraction& l, const Fraction& r) { return Fraction(l.n*r.n,l.d*r.d); }
Fraction operator*(const Fraction& l, int r) { return l*Fraction(r,1); }
Fraction operator*(int r, const Fraction& l) { return l*r; }
Fraction operator/(const Fraction& l, const Fraction& r) { return l*Fraction(r.d,r.n); }
Fraction operator/(const Fraction& l, const int& r) { return l/Fraction(r,1); }
Fraction operator/(const int& l, const Fraction& r) { return Fraction(l,1)/r; }

Fraction operator+=(Fraction& l, const Fraction& r) { return l = l+r; }
Fraction operator-=(Fraction& l, const Fraction& r) { return l = l-r; }
template<class T> Fraction operator*=(Fraction& l, const T& r) { return l = l*r; }
template<class T> Fraction operator/=(Fraction& l, const T& r) { return l = l/r; }

std::ostream& operator<<(std::ostream &strm, const Fraction &a) {
    strm << a.n;
    if (a.d != 1) strm << "/" << a.d;
    return strm;
}

struct line {
    ll A, B, C;
    line(ll _A, ll _B, ll _C) {
        A = _A, B = _B, C = _C;
        if (B < 0 || (B == 0 && A > 0)) {
            A *= -1, B *= -1, C *= -1;
        }
    }
    ll eval(pi x) {
        return A*x.f+B*x.s;
    }
};

bool operator<(const line& x, const line& y) {
    if (x.B == 0) return 0;
    if (y.B == 0) return 1;
    return Fraction(-x.A,x.B) < Fraction(-y.A,y.B);
}

bool done[2000][2000];
int pos[2000];
vi P;

void swa(int a, int b) {
    if (a > b) swap(a,b);
    if (done[a][b]) return;
    // cout << "OOPS " << a << " " << b << " " << pos[a] << " " << pos[b] << "\n";
    done[a][b] = 1;
    if (abs(pos[a]-pos[b]) != 1) exit(5);
    swap(pos[a],pos[b]);
    swap(P[pos[a]],P[pos[b]]);
}

std::ostream& operator<<(std::ostream &strm, const pi& a) {
    strm << a.f << " " << a.s; // << " | ";
    return strm;
}

void search(line x, pi z) {
    int l = 0, r = n-1;
    while (l < r) {
        int m = (l+r)/2;
        if (x.eval(p[P[m]]) < x.C) l = m+1;
        else r = m;
    }
    if (l < n && x.eval(p[P[l]]) == x.C) {
        cout << "Yes\n";
        cout << p[P[l]] << "\n" << p[z.f] << "\n" << p[z.s] << "\n";
        exit(0);
    }
    /*cout << x.A << " " << x.B << " " << x.C << "\n";
    for (auto a: P) cout << x.eval(p[a]) << " ";
    cout << "\n";
    cout << "\n";*/
}

ll area(pl a, pl b, pl c) {
    b.f -= a.f, b.s -= a.s, c.f -= a.f, c.s -= a.s;
    return abs(b.s*c.f-b.f*c.s);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> S; S *= 2;
    p.resize(n);
    F0R(i,n) {
        //p[i].f = rand()% 2000000000 - 1000000000;
        //p[i].s = rand()% 2000000000 - 1000000000;
        cin >> p[i].f >> p[i].s;
    }
    // cout << area(p[23],p[235], p[14])/2 ;
    vector<pair<line,pi>> v;
    F0R(i,n) F0R(j,n) if (i != j) {
        line t = {p[j].s-p[i].s,p[i].f-p[j].f,p[i].f*p[j].s-p[i].s*p[j].f-S};
        // cout << t.A << " " << t.B << " " << t.C << "\n";
        v.pb({t,{i,j}});
    }
    sort(all(v));
    
    
    F0R(i,n) P.pb(i);
    sort(all(P),[](int i, int j) { return p[i] < p[j]; });
    // for (int i: P) cout << i << " " << p[i].f << " " << p[i].s << "\n";
    F0R(i,n) pos[P[i]] = i;
    
    for (int i = 0; i < sz(v); ++i) {
        swa(v[i].s.f,v[i].s.s);
        search(v[i].f,v[i].s);
    }
    
    cout << "No";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/