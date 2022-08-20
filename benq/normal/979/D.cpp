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

int q;
vi divi[MX];
bool done[MX];

struct tri {
    static const int MXBIT = 17;
    vector<array<int,2>> trie;
    int nex = 0; // easily changed to character
    ll ans = 0;
    
    tri() { trie.pb({0,0}); }
    
    void ins(ll x) { // insert or delete
        int cur = 0;
        F0Rd(i,MXBIT) {
            int t = (x&(1LL<<i))>>i;
            if (!trie[cur][t]) {
                trie[cur][t] = ++nex;
                trie.pb({0,0});
            }
            cur = trie[cur][t];
        }
    }
    
    int solve(int s, int x, int cnum = 0, int cind = 0, int cbit = MXBIT-1) {
        if (cnum > s) return -1;
        if (cbit == -1) return cnum;
        
        int b = (x & (1<<cbit)) ? 1 : 0;
        
        int res = -1;
        if (b == 0) {
            if (trie[cind][1]) res = solve(s, x^(1<<cbit), cnum^(1<<cbit), trie[cind][1], cbit-1);
        } else {
            if (trie[cind][0]) res = solve(s, x, cnum, trie[cind][0], cbit-1);
        }
        
        if (res != -1) return res;
        if (b == 1) {
            if (trie[cind][1]) return solve(s, x^(1<<cbit), cnum^(1<<cbit), trie[cind][1], cbit-1);
        } else {
            if (trie[cind][0]) return solve(s, x, cnum, trie[cind][0], cbit-1);
        }
        
        return -1;
    }
};

tri bes[MX];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> q;
    FOR(i,1,MX) for (int j = i; j < MX; j += i) divi[j].pb(i);
    F0R(i,q) {
        int t; cin >> t;
        if (t == 1) {
            int u; cin >> u;
            if (done[u]) continue;
            done[u] = 1;
            for (int j: divi[u]) bes[j].ins(u);
        } else {
            int x,k,s; cin >> x >> k >> s;
            if (x % k != 0) {
                cout << "-1\n";
                continue;
            }
            s -= x;
            cout << bes[k].solve(s,x) << "\n";
        }
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS