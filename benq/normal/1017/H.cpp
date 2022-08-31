#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001;

ll n,m,q, ans[MX];
ll fac[2*MX], ifac[2*MX];
int e[MX], co[MX], special[MX];
vi S;

ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
ll inv (ll b) { return po(b,MOD-2); }

ll mul(const ll& a, const ll& b) {
    return (a%MOD)*(b%MOD)%MOD;
}

ll MUL(ll& a, const ll& b) { return a = mul(a,b); }

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    FOR(i,1,n+1) {
        // e[i] = rand() % 300+1;
        cin >> e[i];
        co[e[i]] ++;
    }
    FOR(i,1,m+1) if ((ll)co[i]*co[i] > n) {
        special[i] = 1;
        S.pb(i);
    }
}

vector<array<int,4>> v;

bool cmp(array<int,4> a, array<int,4> b) {
    if (a[0]/320 != b[0]/320) return a[0] < b[0];
    return a[1] < b[1];
}

int tmp[MX], cur[MX];
int l = 1, r = 0;

void ad(int x, int y) {
    if (!special[x]) {
        if (y == 1) tmp[co[x]-cur[x]] ++;
        else tmp[co[x]-cur[x]+1] --;
    }
    cur[x] += y;
}

void answer(array<int,4> a) {
    while (l > a[0]) ad(e[--l],1);
    while (r < a[1]) ad(e[++r],1);
    while (l < a[0]) ad(e[l++],-1);
    while (r > a[1]) ad(e[r--],-1);
    
    ans[a[3]] = 1;
    for (int i = 1; i*i <= n; ++i) 
        MUL(ans[a[3]],po(i+a[2],tmp[i]));
    
    for (int i: S) 
        MUL(ans[a[3]],mul(fac[co[i]+a[2]],ifac[co[i]+a[2]-cur[i]]));
}

ll zz[MX];

void addFac() {
    sort(all(v),[](array<int,4> a, array<int,4> b) { return a[2] < b[2]; });
    for (int i = 0; i < sz(v); ) {
        zz[1] = 1;
        FOR(j,2,MX) zz[j] = mul(zz[j-1],m*v[i][2]+j-1);
        int I = i;
        while (i < sz(v) && v[i][2] == v[I][2]) {
            MUL(ans[v[i][3]],zz[n-(v[i][1]-v[i][0])]);
            i ++;
        }
    }
}

int main() {
    init();
    
    fac[0] = ifac[0] = 1;
    FOR(i,1,2*MX) {
        fac[i] = mul(i,fac[i-1]);
        ifac[i] = inv(fac[i]);
    }
    
    F0R(i,q) {
        int l,r,k; cin >> l >> r >> k;
        // int l = rand() % n+1, r = rand() % n+1, k = rand() % m+1;
        if (l > r) swap(l,r);
        v.pb({l,r,k,i});
    }
    
    sort(all(v),cmp);
    for (auto a: v) answer(a);
    addFac();
    F0R(i,q) cout << ans[i] << "\n";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/