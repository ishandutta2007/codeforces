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
const int MX = 300000;

namespace {
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}
}

int n,k; 
pi p[MX];
vpi v[MX][2];

map<int,int> m;

void tri(int x, int ind) {
    auto it = prev(m.ub(p[x].f));
    int lst = -1, tmp = 0;
    while (it->f <= p[x].s) {
        int len = min(next(it)->f,p[x].s)-max(it->f,p[x].f);
        if (len) v[x][ind].pb({it->s,len});
        
        lst = it->s;
        it = next(it);
        if (tmp) m.erase(prev(it));
        tmp ++;
    }
    m[p[x].s] = lst;
    m[p[x].f] = x;
}

void process(int ind) {
    m.clear();
    if (ind == 0) {
        m[1] = m[MOD] = -1;
        F0R(i,n) tri(i,ind);
    } else {
        m[1] = m[MOD] = n;
        F0Rd(i,n) tri(i,ind);
    }
}

void init() {
    io();
    cin >> n >> k;
    F0R(i,n) cin >> p[i].f >> p[i].s;
    process(0); process(1);
}

int l, r;
ll cans, csum;

void adLeft() {
    // csum: all > r 
    // cans == r 
    l --;
    for (auto a: v[l][1]) if (a.f > r) {
        cans += a.s;
        csum += (ll)(a.f-r-1)*a.s;
    }
}

void delRight() {
    csum += cans;
    for (auto a: v[r][0]) if (a.f < l) cans -= a.s;
    r --;
}

pl get(int mid) {
    pl res = {0,0}; 
    l = n, r = n-1; cans = csum = 0;
    F0Rd(i,n) {
        adLeft();
        while (cans >= mid) delRight();
        res.f += n-1-r; res.s += csum;
    }
    return res;
}

int main() {
    init();
    int lo = 1, hi = 1000000000;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (get(mid).f < k) hi = mid;
        else lo = mid+1;
    }
    auto a = get(lo);
    cout << a.s+(k-a.f)*(lo-1);
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/