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
const int MX = 200005;

int n,q,oc[MX],cnt[MX],ans[MX],val[MX],bad[MX];
array<int,3> mod[MX];
vi a;
vector<array<int,3>> Q;
map<int,int> m;

int t[3] = {0,-1,-1};

void compress() {
    for (auto x: a) m[x] = 0;
    int co = 0;
    for (auto& x: m) x.s = co ++;
    // cout << "HI " << co << "\n";
    for (auto& x: a) x = m[x];
}

bool cmp(array<int,3> a, array<int,3> b) {
    int mul = pow(n,2.0/3);
    if (a[0]/mul != b[0]/mul) return a[0] < b[0];
    if (a[1]/mul != b[1]/mul) return a[1] < b[1];
    return a[2] < b[2];
}

void updCnt(int x, int y) {
    oc[cnt[x]] --;
    cnt[x] += y;
    oc[cnt[x]] ++;
}

void solve(array<int,3> x) {
    // cout << "HI " << x[0] << " " << x[1] << " " << x[2] << "\n";
    while (t[0] > x[0]) {
        t[0] --;
        updCnt(val[t[0]],1);
    }
    while (t[1] < x[1]) {
        t[1] ++;
        updCnt(val[t[1]],1);
    }
    while (t[0] < x[0]) {
        updCnt(val[t[0]],-1);
        t[0] ++;
    }
    while (t[1] > x[1]) {
        updCnt(val[t[1]],-1);
        t[1] --;
    }
    
    while (t[2] < x[2]) {
        t[2] ++;
        if (bad[t[2]]) {
            int p = mod[t[2]][0];
            if (t[0] <= p && p <= t[1]) {
                updCnt(mod[t[2]][1],-1);
                updCnt(mod[t[2]][2],1);
            }
            val[p] = mod[t[2]][2];
        }
    }
    while (t[2] > x[2]) {
        if (bad[t[2]]) {
            int p = mod[t[2]][0];
            if (t[0] <= p && p <= t[1]) {
                updCnt(mod[t[2]][2],-1);
                updCnt(mod[t[2]][1],1);
            }
            val[p] = mod[t[2]][1];
        }
        t[2] --;
    }
    for (int i = 1;;++i) if (!oc[i]) {
        ans[x[2]] = i;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q; a.resize(n);
    F0R(i,n) cin >> a[i];
    compress();
    F0R(i,n) val[i] = a[i];
    
    F0R(i,q) {
        int t; cin >> t;
        if (t == 1) {
            int l,r; cin >> l >> r; l--, r--;
            Q.pb({l,r,i});
        } else {
            int p,x; cin >> p >> x; p--;
            if (!m.count(x)) m[x] = sz(m);
            x = m[x];
            mod[i] = {p,val[p],x};
            val[p] = x;
            bad[i] = 1;
        }
    }
    //F0R(i,n) cout << val[i] << " ";
    //cout << "\n";
    F0R(i,n) val[i] = a[i];
    //F0R(i,n) cout << val[i] << " ";
    //cout << "\n";
    sort(all(Q),cmp);
    for (auto x: Q) solve(x);
    F0R(i,q) if (ans[i]) cout << ans[i] << "\n";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)