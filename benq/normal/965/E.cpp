
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

template<int MX> struct tri {
    int nex = 0, ans = 0;
    int trie[MX][26]; // easily changed to character
    
    tri() {
        memset(trie,0,sizeof trie);
    }
    
    int need[MX];
    multiset<int> dat[MX];
    
    void comb(int a, int b) {
        bool swa = 0;
        if (sz(dat[a]) < sz(dat[b])) swap(a,b), swa = 1;
        for (auto& x: dat[b]) dat[a].insert(x);
        dat[b].clear();
        if (swa) swap(dat[a],dat[b]);
    }
    
    void process(int ind, int depth) {
        F0R(i,26) if (trie[ind][i]) {
            process(trie[ind][i],depth+1); 
            comb(ind,trie[ind][i]);
        }
        if (need[ind]) dat[ind].insert(depth);
        else if (ind) {
            dat[ind].erase(prev(dat[ind].end()));
            dat[ind].insert(depth);
        }
        if (ind == 0) {
            ll ans = 0;
            for (int i: dat[ind]) ans += i;
            cout << ans;
        }
    }
    
    void ins(string x) {
        int cur = 0;
        for (char c: x) {
            if (!trie[cur][c-'a']) trie[cur][c-'a'] = ++nex;
            cur = trie[cur][c-'a'];
        }
        need[cur] = 1;
    }
};

tri<MX> T;
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n) {
        string s; cin >> s;
        T.ins(s);
    }
    T.process(0,0);
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)