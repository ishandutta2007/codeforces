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
const int MX = 1000001;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

int n,k,a[MX],ans;
pair<int,vpi> tmp[MX];

void AD(int& a, int b) { a = (a+b)%MOD; }
void SUB(int& a, int b) { a = (a-b+MOD)%MOD; }
int mul(int& a, int b) { return (ll)a*b%MOD; }

void setmx(pair<int,vpi>& p, int x) {
    int num = 0;
    while (sz(p.s) && p.s.back().f <= x) {
        SUB(p.f,mul(p.s.back().f,p.s.back().s));
        num += p.s.back().s;
        p.s.pop_back();
    }
    if (num) {
        p.s.pb({x,num});
        AD(p.f,mul(x,num));
    }
}

int main() {
    io();
    cin >> n >> k;
    F0R(i,n) cin >> a[i];
    deque<pi> cmx;
    F0Rd(i,n) {
        while (sz(cmx) && cmx.front().f <= a[i]) cmx.pop_front();
        cmx.push_front({a[i],i});
        while (cmx.back().s >= i+k) cmx.pop_back();
        if (i+k-1 < n) swap(tmp[i],tmp[i+k-1]);
        setmx(tmp[i],cmx.back().f);
        AD(ans,tmp[i].f);
        AD(tmp[i].f,a[i]); tmp[i].s.pb({a[i],1});
    }
    cout << ans;
    
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/