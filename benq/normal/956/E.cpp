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
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

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

int n,l,r,bes[10001],a[10001],sumh = 0;
vpi v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> l >> r;
    F0R(i,n) {
        cin >> a[i];
        sumh += a[i];
    }
    F0R(i,n) {
        int b; cin >> b;
        v.pb({b,-a[i]});
    }
    swap(l,r); l = sumh-l, r = sumh-r;
    FOR(i,1,10001) bes[i] = -MOD;
    sort(all(v));
    for (auto& x: v) {
        x.s *= -1;
        F0Rd(i,10001-x.s) if (bes[i] != -MOD) bes[i+x.s] = max(bes[i+x.s],bes[i]+(x.f&&(l <= i+x.s && i+x.s <= r)));
    }
    
    int ans = 0; F0R(i,10001) ans = max(ans,bes[i]);
    cout << ans;
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)