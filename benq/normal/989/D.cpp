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

ll n,l,w;
vi st,en;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> l >> w;
    F0R(i,n) {
        int x,v; cin >> x >> v;
        if (v == 1) st.pb(x);
        else en.pb(x+l);
    }
    sort(all(st)); reverse(all(st)); sort(all(en));
    
    ll ans = 0;
    int ind = sz(en);
    for (int i: st) {
        while (ind > 0 && en[ind-1] > i) ind --;
        int l = ind, r = sz(en);
        while (l < r) {
            int j = (l+r)/2;
            if ((i+en[j])-w*(en[j]-i) < 0 && (i+en[j])+w*(en[j]-i) > 0) r = j;
            else l = j+1;
        }
        ans += sz(en)-r;
        // cout << "HI " << i << " " << r << " " << ind << " " << sz(en) << " " << ans << "\n";
    }
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS