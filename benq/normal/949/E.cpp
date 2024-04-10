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

int n;
vi ans;

void search(vi cur, vi need, int mult) {
    if (sz(need) >= sz(ans)) return;
    if (sz(cur) == 0) {
        ans = need;
        return;
    }
    
    int x = MOD; 
    for (int i: cur) x = min(x,i&-i);
    mult *= x;
    for (int& i: cur) i /= x;
    
    vi CUR, NEED = need;
    for (int i: cur) {
        int nex;
        if (i&1) nex = (i+1)/2;
        else nex = i/2;
        if ((sz(CUR) && CUR.back() == nex) || nex == 0) continue;
        CUR.pb(nex);
    }
    NEED.pb(-mult);
    search(CUR,NEED,mult*2);
    
    CUR.clear();
    for (int i: cur) {
        int nex;
        if (i&1) nex = (i-1)/2;
        else nex = i/2;
        if ((sz(CUR) && CUR.back() == nex) || nex == 0) continue;
        CUR.pb(nex);
    }
    
    NEED.pop_back();
    NEED.pb(mult);
    search(CUR,NEED,mult*2);
}

int main() {
    // (something out of a) - (something out of b)
    // we shouldn't have both x and -x 
    
    F0R(i,50) ans.pb(0);
    vi cur;
    
    cin >> n;
    F0R(i,n) {
        int x; cin >> x;
        if (x != 0) cur.pb(x);
    }
    
    sort(all(cur));
    search(cur,{},1);
    cout << sz(ans) << "\n";
    for (int i: ans) cout << i << " ";
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)