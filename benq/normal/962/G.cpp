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
const ll INF = 1e18;
const int MX = 100001;

template<int SZ> struct DSU {
    int par[SZ], sz[SZ], nex=0;
    DSU() {
        F0R(i,SZ) par[i] = i, sz[i] = 1;
    }
    
    int get(int x) { // path compression
    	if (par[x] != x) par[x] = get(par[x]);
    	return par[x];
    }
    
    bool unite(int x, int y) { // union-by-rank
    	x = get(x), y = get(y);
    	if (x == y) return 0;
    	if (sz[x] < sz[y]) swap(x,y);
    	sz[x] += sz[y], par[y] = x;
    	return 1;
    }
};

DSU<100001> D;

int n,ans;
pi X,Y;
pi p[15000];
vpi v[15001];
set<pair<pi,int>> cur;

pair<pi,int> mergeLeft(int ind, pair<pi,int> z) {
    // last one with second <= z.f 
    auto it = cur.ub(z);
    if (it != cur.end() && it->f.f == z.f.s) {
        ans -= D.unite(it->s,z.s);
        z.f.s = it->f.s;
        cur.erase(it);
    }
    return z;
}

pair<pi,int> mergeRight(int ind, pair<pi,int> z) {
    auto it = cur.ub(z);
    if (it != cur.begin() && prev(it)->f.s == z.f.f) {
        it = prev(it);
        ans -= D.unite(it->s,z.s);
        z.f.f = it->f.f;
        cur.erase(it);
    }
    return z;
}

void mod(int ind, pi t) {
    auto a = cur.ub({{t.f,MOD},MOD});
    if (a != cur.begin() && prev(a)->f.s >= t.s) {
        auto A = *prev(a); cur.erase(A);
        if (A.f.f < t.f) cur.insert({{A.f.f,t.f},A.s});
        if (t.s < A.f.s) cur.insert({{t.s,A.f.s},A.s});
    } else {
        pair<pi,int> z = mp(t,D.nex++); if (ind <= X.s) ans ++;
        z = mergeLeft(ind,z);
        z = mergeRight(ind,z);
        cur.insert(z);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> X.f >> X.s >> Y.f >> Y.s;
    cin >> n;
    F0R(i,n) cin >> p[i].f >> p[i].s; // only horizontal
    F0R(i,n) if (p[i].s == p[(i+1)%n].s) {
        pi z = {p[i].f,p[(i+1)%n].f};
        if (z.f > z.s) swap(z.f,z.s);
        z.f = max(z.f,X.f); z.s = min(z.s,Y.f);
        if (z.f < z.s) v[p[i].s].pb(z);
    }
    F0Rd(i,15001) {
        if (i == Y.s) {
            cout << ans;
            return 0;
        }
        for (auto t: v[i]) {
            mod(i,t);
        }
        if (i == X.s) {
            D = DSU<100001>();
            ans = 0;
            
            set<pair<pi,int>> CUR;
            for (auto t: cur) {
                CUR.insert({t.f,D.nex++});
                ans ++;
            }
            cur = CUR;
            // for (auto a: CUR) cout << a.f.f << " " << a.f.s << "\n";
            // cout << "HI " << ans << " " << i << "\n";
        } 
    }
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)