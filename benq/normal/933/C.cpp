#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

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
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

typedef complex<double> cd;
typedef pair<cd,double> circle;

cd csol;
vector<cd> inter[3];

int intersect(circle a, circle b, int x = 0) { 
    double d = sqrt(norm(a.f-b.f));
    double co = (a.s*a.s+d*d-b.s*b.s)/(2*a.s*d);
    if (co < -1 || co > 1) return 0;
    double theta = acos(co);
    
    cd tmp = (b.f-a.f)/d;
    if (x == 0) csol = a.f+tmp*a.s*polar(1.0,theta);
    else csol = a.f+tmp*a.s*polar(1.0,-theta);
    
    if (co == -1 || co == 1) return 1;
    return 2;
}

double arc(circle x, cd a, cd b) {
    cd d = (a-x.f)/(b-x.f);
    return x.s*acos(d.real());
}

bool on (circle x, cd y) {
    return norm(y-x.f) == x.s*x.s;
}

map<pi,int> m;
vector<circle> v;

void process(circle a, circle b, int ind) {
    int t = intersect(a,b);
    if (t >= 1) {
        inter[ind].pb(csol);
        if (t == 2) {
            intersect(a,b,1);
            inter[ind].pb(csol);
        }
    }
}

bool close(cd a, cd b) {
    // cout << "AH " << abs(a-b) << "\n";
    return abs(a-b) <= 1e-10;
}

int getallthree() {
    int num = 0;
    for (auto a: inter[0]) {
        bool ok = 0;
        for (auto b: inter[1]) if (close(a,b)) ok = 1;
        if (!ok) continue;
        ok = 0;
        for (auto b: inter[2]) if (close(a,b)) ok = 1;
        if (!ok) continue;
        num ++;
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    F0R(i,n) {
        int a,b,c; cin >> a >> b >> c;
        v.pb(circle(cd(a,b),c));
    }
    m[{0,0}] = m[{1,0}] = m[{2,0}] = 4; m[{3,0}] = 5;
    m[{0,1}] = m[{1,1}] = 5, m[{2,1}] = 6;
    m[{0,2}] = 6; m[{1,2}] = 7;
    m[{0,3}] = 8;
    
    if (n == 1) cout << 2;
    else if (n == 2) {
        if (intersect(v[0],v[1]) == 2) cout << 4;
        else cout << 3;
    } else {
        process(v[0],v[1],0);
        // for (auto x: inter[0]) cout << x << "\n";
        process(v[1],v[2],1);
        process(v[0],v[2],2);
        
        int x = getallthree();
        if (x == 2) cout << 6;
        else if (x == 1) {
            if (intersect(v[1],v[2]) == 1 && intersect(v[0],v[2]) == 1) cout << 4;
            else if (intersect(v[1],v[2]) == 1 || intersect(v[0],v[2]) == 1 || intersect(v[0],v[1]) == 1) cout << 6;
            else cout << 7;
        } else {
            int co1 = 0, co2 = 0;
            F0R(i,3) {
                if (sz(inter[i]) == 1) co1 ++;
                else if (sz(inter[i]) == 2) co2 ++;
            }
            cout << m[{co1,co2}];
        }
    }
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)