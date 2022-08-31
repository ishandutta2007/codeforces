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
const int MX = 200001;

int n,m,ans[MX];
pl p[MX];
vector<array<ll,3>> ok;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,n) cin >> p[i].f >> p[i].s;
    F0R(i,n-1) {
        ok.pb({p[i+1].f-p[i].s,p[i+1].s-p[i].f,i+1});
    }
    sort(all(ok));
    vpl a(m); 
    F0R(i,m) {
        cin >> a[i].f;
        a[i].s = i+1;
    }
    sort(all(a));
    int ind = 0, use = 0;
    set<pl> S;
    for (auto x: a) {
        while (ind < sz(ok) && ok[ind][0] <= x.f) {
            S.insert({ok[ind][1],ok[ind][2]});
            ind ++;
        }
        while (sz(S) && S.begin()->f < x.f) S.erase(S.begin());
        if (sz(S)) {
            ans[S.begin()->s] = x.s;
            S.erase(S.begin()); use ++;
        }
    }
    if (use == n-1) {
        cout << "Yes\n";
        FOR(i,1,n) cout << ans[i] << " ";
    } else cout << "No";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS