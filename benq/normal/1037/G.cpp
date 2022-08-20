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
const int MX = 100001;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

string s;
int m;
pi pre[MX][26], nex[MX][26];
int cum[MX][26];

int calc(int l, int r) {
    if (l > r) return 0;
    int v = 0;
    F0R(i,26) {
        int L = nex[l][i].f, R = pre[r][i].f;
        if (L > R) continue;
        int t = nex[l][i].s^pre[r][i].s^cum[R][i]^cum[L][i];
        if (t < 26) v |= 1<<t;
    }
    F0R(i,26) if (!(v&(1<<i))) return i;
    return 26;
}

void precalc() {
    F0R(i,sz(s)) {
        F0R(j,26) {
            if (i == 0) pre[i][j].f = -1;
            else pre[i][j].f = pre[i-1][j].f;
        }
        pre[i][s[i]-'a'].f = i;
    }
    F0Rd(i,sz(s)) {
        F0R(j,26) {
            if (i == sz(s)-1) nex[i][j].f = sz(s);
            else nex[i][j].f = nex[i+1][j].f;
        }
        nex[i][s[i]-'a'].f = i;
    }
    F0R(i,sz(s)) {
        int c = s[i]-'a';
        int lstOc = (i == 0 ? -1 : pre[i-1][c].f);
        FOR(j,lstOc+1,i+1) nex[j][c].s = calc(j,i-1);
        cum[i][c] = (lstOc == -1 ? 0 : cum[lstOc][c])^nex[lstOc+1][c].s;
        
        vpi tmp;
        F0R(j,26) tmp.pb({pre[i][j].f,j});
        sort(tmp.rbegin(),tmp.rend());
        
        for (auto a: tmp) pre[i][a.s].s = calc(a.f+1,i);
    }
    F0R(c,26) {
        int lstOc = pre[sz(s)-1][c].f;
        FOR(j,lstOc+1,sz(s)) nex[j][c].s = calc(j,sz(s)-1);
    }
}

int main() {
    io();
    cin >> s >> m;
    precalc();
    //cout << nex[6][1].s << " " << pre[6][1].s << "\n";
    //cout << calc(4,4) << " " << calc(6,6) << " " << calc(4,6) << "\n";
    
    F0R(i,m) {
        int l,r; cin >> l >> r;
        if (calc(l-1,r-1)) cout << "Alice\n";
        else cout << "Bob\n";
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/