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

pi p[2][4];

int are(vpi v) {
    int x = 0;
    F0R(i,sz(v)) {
        x += v[i].f*v[(i+1)%sz(v)].s;
        x -= v[i].s*v[(i+1)%sz(v)].f;
    }
    return abs(x);
}

bool in (int x, int y) {
    int area = 0;
    F0R(z,4) area += are({{x,y},p[1][z],p[1][(z+1)%4]});
    area -= are({p[1][0],p[1][1],p[1][2],p[1][3]});
    if (area == 0) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    F0R(i,2) F0R(j,4) cin >> p[i][j].f >> p[i][j].s;
    
    FOR(x,min(min(p[0][0].f,p[0][1].f),min(p[0][2].f,p[0][3].f)),max(max(p[0][0].f,p[0][1].f),max(p[0][2].f,p[0][3].f))+1) 
        FOR(y,min(min(p[0][0].s,p[0][1].s),min(p[0][2].s,p[0][3].s)),max(max(p[0][0].s,p[0][1].s),max(p[0][2].s,p[0][3].s))+1) if (in(x,y)) {
        cout << "Yes";
        exit(0);
    }
    cout << "No";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS