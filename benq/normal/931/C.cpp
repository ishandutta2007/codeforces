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

int n, mn = MOD, mx = -MOD, co[3];
vi v, BES;

int get(vi x) {
    if (sz(x) == 0) return MOD;
    int t = 0;
    F0R(i,3) t += min(co[i],x[i]);
    return t;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n) {
        int x; cin >> x; v.pb(x);
        mn = min(mn,x); mx = max(mx,x);
    }
    int z = 0;
    for (int i: v) {
        co[i-mn] ++;
        z += i-mn;
    }
    
    vi CO(3);
    F0R(i,n+1) {
        CO[2] = i;
        CO[1] = z-2*i;
        CO[0] = n-CO[2]-CO[1];
        if (CO[2] > 0 && mx-mn < 2) continue;
        if (CO[1] > 0 && mx-mn < 1) continue;
        if (min(CO[0],CO[1]) >= 0) if (get(CO) < get(BES)) BES = CO;
    }
    cout << get(BES) << "\n";
    F0R(i,3) F0R(j,BES[i]) cout << mn+i << " ";
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)