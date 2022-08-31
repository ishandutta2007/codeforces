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

int t,mx;
array<int,1000000> co = array<int,1000000>();
int nex = 1;

array<int,1000000> gen(int R, int C, int x, int y) {
    array<int,1000000> z = array<int,1000000>();
    if (x < 1 || x > R || y < 1 || y > C) return z;
    FOR(i,1,R+1) FOR(j,1,C+1) z[abs(i-x)+abs(j-y)] ++;
    return z;
}

void test(int R, int C) {
    int x = nex, y = mx+1-(R-nex);
    if (co == gen(R,C,x,y)) {
        cout << R << " " << C << "\n";
        cout << x << " " << y << "\n";
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t; 
    F0R(i,t) {
        int a; cin >> a;
        co[a] ++;
        mx = max(mx,a);
    }
    if (co[0] != 1) {
        cout << -1;
        exit(0);
    }
    while (co[nex] == 4*nex) nex ++;
    
    for (int i = 1; i*i <= t; ++i) if (t % i == 0) {
        test(i,t/i);
        test(t/i,i);
    }
    cout << -1;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS