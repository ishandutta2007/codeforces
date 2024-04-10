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

int n, sgn[MX];
vi cur[MX];
pi v[MX], ori[MX];
set<pair<ld,int>> lef;

pi operator-(const pi& a, const pi& b) {
    return {a.f-b.f,a.s-b.s};
}

pi operator+(const pi& a, const pi& b) {
    return {a.f+b.f,a.s+b.s};
}

pi operator*(const int& a, const pi& b) {
    return {a*b.f,a*b.s};
}

ll mag(pi x) {
    return (ll)x.f*x.f+(ll)x.s*x.s;
}

void ins(int x, int y = 1) {
    ld ang;
    if (v[x] == mp(0,0)) ang = 0;
    else ang = atan2(v[x].s,v[x].f);
    if (y) lef.insert({ang,x});
    else lef.erase({ang,x});
}

void comb(int x, int y, int sgn = -1) {
    ins(x,0), ins(y,0);
    if (sz(cur[x]) < sz(cur[y])) swap(x,y);
    if (sz(lef) > 0) assert(mag(v[x]+sgn*v[y]) <= max(mag(v[x]),mag(v[y])));
    //cout << "HI " << x << " " << y << " " << "TT " << sgn << " " << v[x].f << " " << v[x].s << " " << v[y].f << " " << v[y].s << "\n";
    v[x] = (v[x]+(sgn*v[y]));
    //cout << "HI " << x << " " << y << " " << v[x].f << " " << v[x].s << "\n";
    for (int z: cur[y]) cur[x].pb(sgn*z);
    cur[y].clear();
    ins(x);
    //for (auto a: lef) cout << a.s << " | ";
    //cout << "\n";
}

void elimSmall() {
    vector<pair<ld,int>> LEF; for (auto a: lef) LEF.pb(a);
    F0R(i,sz(LEF)) FOR(j,i+1,sz(LEF)) {
        pi a = v[LEF[i].s], b = v[LEF[j].s];
        if (mag(a-b) <= max(mag(a),mag(b))) {
            comb(LEF[i].s,LEF[j].s);
            return;
        }
        if (mag(a+b) <= max(mag(a),mag(b))) {
            comb(LEF[i].s,LEF[j].s,1);
            return;
        }
    }
}

void elimLarge() {
    for (auto it = lef.begin(); ; ++it) {
        if (mag(v[it->s]-v[next(it)->s]) <= max(mag(v[it->s]),mag(v[next(it)->s]))) {
            comb(it->s,next(it)->s);
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i,1,n+1) {
        cin >> v[i].f >> v[i].s;
        ori[i] = v[i];
        cur[i].pb(i);
        ins(i);
    }
    while (sz(lef) > 1) {
        if (sz(lef) > 20) elimLarge();
        else if (sz(lef) > 2) elimSmall();
        else {
            pi a = v[lef.begin()->s], b = v[next(lef.begin())->s];
            if (mag(a-b) < mag(a+b)) comb(lef.begin()->s,next(lef.begin())->s,-1);
            else comb(lef.begin()->s,next(lef.begin())->s,1);
        }
    }
    for (auto x: cur[lef.begin()->s]) sgn[abs(x)] = x/abs(x);
    // cout << sqrt(mag(v[lef.begin()->s])) << "\n";
    pl sum = {0,0};
    FOR(i,1,n+1) {
        sum = {sum.f+sgn[i]*ori[i].f,sum.s+sgn[i]*ori[i].s};
        cout << sgn[i] << " ";
    }
    //cout << sum.f << " " << sum.s << " " << lef.begin()->s << " " << v[lef.begin()->s].f << " " << v[lef.begin()->s].s << "\n";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS