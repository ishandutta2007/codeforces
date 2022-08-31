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

int n,m,cl,ce,v;
set<int> stair, ele;

int testStair(pi a, pi b) {
    if (a.s > b.s) swap(a.s,b.s);
    auto it = stair.lb(a.s);
    int ret = MOD;
    
    if (it != stair.end()) ret = min(ret,abs(a.f-b.f)+abs(*it-a.s)+abs(*it-b.s));
    if (it != stair.begin()) {
        it = prev(it);
        ret = min(ret,abs(a.f-b.f)+abs(*it-a.s)+abs(*it-b.s));
    }
    
    return ret;
}

int cdiv(int x) {
    x = abs(x);
    return (x+v-1)/v;
}

int testEle(pi a, pi b) {
    if (a.s > b.s) swap(a.s,b.s);
    auto it = ele.lb(a.s);
    int ret = MOD;
    
    if (it != ele.end()) ret = min(ret,cdiv(a.f-b.f)+abs(*it-a.s)+abs(*it-b.s));
    if (it != ele.begin()) {
        it = prev(it);
        ret = min(ret,cdiv(a.f-b.f)+abs(*it-a.s)+abs(*it-b.s));
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> cl >> ce >> v;
    F0R(i,cl) {
        int x; cin >> x;
        stair.insert(x);
    }
    F0R(i,ce) {
        int x; cin >> x;
        ele.insert(x);
    }
    int q; cin >> q;
    F0R(i,q) {
        pi x,y; cin >> x.f >> x.s >> y.f >> y.s;
        if (x.f == y.f) cout << abs(x.s-y.s) << "\n";
        else cout << min(testStair(x,y),testEle(x,y)) << "\n";
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)