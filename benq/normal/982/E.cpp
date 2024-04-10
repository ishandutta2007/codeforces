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

namespace NT {
    vpi fac(int x) {
        vpi pri;
        
        for (int i = 2; i*i <= x; ++i) if (x % i == 0) {
            int t = 0;
            while (x % i == 0) x /= i, t ++;
            pri.pb({i,t});
        }
        
        if (x > 1) pri.pb({x,1});
        return pri;
    }

    int phi(int x) {
        for (auto a: fac(x)) x /= a.f, x *= a.f-1; 
        return x;
    }

    ll inv(ll a, ll b) { // 0 < a < b, gcd(a,b) = 1
        a %= b;
        if (a <= 1) return a;
        ll i = inv(b%a,a);
        ll tmp = -((b/a)*i+((b%a)*i)/a) % b;
        if (tmp < 0) tmp += b;
        return tmp;
    }
};

namespace CRT {
    pl solveSimple(pl a, pl b) { // b.s divides a.s*x+a.f-b.f
        ll x = (b.f-a.f)*NT::inv(a.s,b.s) % b.s;
        ll ans = (a.s*x+a.f) % (a.s*b.s);
        if (ans < 0) ans += a.s*b.s;
        return {ans,a.s*b.s};
    }

    pl solve(pl a, pl b) {
        // cout << a.f << " " << a.s << " " << b.f << " " << b.s << "\n";
        pl cur = {0,1};
        vpi v = NT::fac(a.s);
        vpi V = NT::fac(b.s); for (auto z: V) v.pb(z);
        
        for (auto z: v) {
            ll A = 1, B = 1; 
            while (a.s % z.f == 0) a.s /= z.f, A *= z.f;
            while (b.s % z.f == 0) b.s /= z.f, B *= z.f;
            if ((a.f-b.f)%min(A,B) != 0) return {-1,-1};
            
            if (A > B) cur = solveSimple(cur,{a.f%A,A});
            else cur = solveSimple(cur,{b.f%B,B});
        }
        return cur;
    }
};

ll n,m,x,y,vx,vy;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> x >> y >> vx >> vy;
    if (abs(vx) == 1 && vy == 0) {
        if (y == 0 || y == m) {
            if (vx == -1) cout << "0 " << y;
            else cout << n << " " << y;
        } else cout << -1;
        exit(0);
    }
    if (abs(vy) == 1 && vx == 0) {
        if (x == 0 || x == n) {
            if (vy == -1) cout << x << " " << 0;
            else cout << x << " " << m;
        } else cout << -1;
        exit(0);
    }
    ll t = CRT::solve({(n-x*vx)%n,n},{(m-y*vy)%m,m}).f;
    if (t == -1) {
        cout << -1;
        exit(0);
    }
    x += t*vx, y += t*vy;
    if (x % (2*n) == 0) cout << 0;
    else cout << n;
    cout << " ";
    if (y % (2*m) == 0) cout << 0;
    else cout << m;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)