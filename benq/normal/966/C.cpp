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

int n;

template<int MX> struct tri {
    int nex = 0, ans = 0;
    int trie[MX][2]; // easily changed to character
    int sz[MX];
    
    tri() {
        memset(trie,0,sizeof trie);
    }
    
    void ins(ll x, int T = 1) {
        int cur = 0; sz[cur] += T;
        F0Rd(i,60) {
            int t = (x&(1LL<<i))>>i;
            if (!trie[cur][t]) trie[cur][t] = ++nex;
            cur = trie[cur][t];
            sz[cur] += T;
        }
    }
    
    ll test(ll num, ll x = 0, bool ge = 0, int cur = 0, int st = 59) {
        if (st == -1) {
            ins(x,-1);
            return x;
        }
        int b = ((num&(1LL<<st))>>st);
        // cout << "AH " << num << " " << x << " " << b << " " << st << " " << cur << " " << ge << " " << trie[cur][0] << " " << sz[trie[cur][0]] << "\n";
        
        if (ge == 0) {
            if (trie[cur][0] && sz[trie[cur][0]]) {
                ll t = test(num,x,0,trie[cur][0],st-1);
                if (t != -1) return t;
            }
            if (b == 0 && (trie[cur][1] && sz[trie[cur][1]]))
                return test(num,x^(1LL<<st),1,trie[cur][1],st-1);
            return -1;
        } 
        if (!trie[cur][b] || !sz[trie[cur][b]]) b ^= 1;
        if (b) x ^= (1LL<<st);
        return test(num,x,1,trie[cur][b],st-1);
    }
};

tri<10000000> t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n) {
        ll x; cin >> x;
        t.ins(x);
    }
    ll cur = 0;
    vl ans;
    F0R(i,n) {
        ll z = t.test(cur);
        if (z == -1) {
            cout << "No";
            exit(0);
        }
        cur ^= z;
        ans.pb(z);
    }
    cout << "Yes\n";
    for (auto a: ans) cout << a << " ";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)