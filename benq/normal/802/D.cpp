#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
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
const int MX = 3005;

int V, oc[MX];
ld prob0[MX], prob1[MX];

void solve() {
    int tmp = rand() % 1950+50;
    
    F0R(i,MX) oc[i] = prob0[i] = prob1[i] = 0;
    
    ll sum = 0;
    F0R(i,250) {
        // int k = rand() % tmp+1; 
        int k; cin >> k;
        if (k < MX) oc[k] ++;
        sum += k;
    }
    sum = round((ld)sum/250); 
    // cout << tmp << " " << sum << "\n";
    sum = min(sum,1000LL); sum = max(sum,10LL);
    ld a = 1;
    int divi = sum;
    F0R(i,MX) {
        prob0[i] = a*exp(-divi);
        a *= sum; a /= i+1;
        while (divi && a/exp(1) >= 1) divi --, a /= exp(1);
    }
    F0R(i,2*sum+1) prob1[i] = (ld)1/(2*sum+1);
    
    ld x = 0, y = 0, t = 0;
    F0R(i,MX) {
        t += prob0[i];
        x += abs(prob0[i]-(ld)oc[i]/250);
        y += abs(prob1[i]-(ld)oc[i]/250);
    }
    //cout << x << " " << y << " " << t << "\n";
    
    if (x < y) cout << "poisson";
    else cout << "uniform";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V;
    F0R(i,V) solve();
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/