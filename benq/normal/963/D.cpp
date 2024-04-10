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
const int MX = 110000;

template<int SZ> struct Aho {
    int link[SZ], dict[SZ], sz = 1, num = 0;
    vpi ind[SZ];
    int to[SZ][26];
    vi oc[SZ];
    queue<int> q;
    
    Aho() {
        memset(link,0,sizeof link);
        memset(dict,0,sizeof dict);
        F0R(i,SZ) F0R(j,26) to[i][j] = MOD;
    }

    void add(string s) {
        int v = 0;
        for(auto c: s) {
            if (to[v][c-'a'] == MOD) to[v][c-'a'] = sz++;
            v = to[v][c-'a'];
        }
        dict[v] = v; ind[v].pb({++num,sz(s)});
    }
 
    void push_links() {
        link[0] = -1; q.push(0);
        while (sz(q)) {
            int v = q.front(); q.pop();
            F0R(i,26) if (to[v][i] != MOD) {
                char c = char('a'+i); int u = to[v][i], j = link[v];
                while (j != -1 && to[j][c-'a'] == MOD) j = link[j];
                if (j != -1) {
                    link[u] = to[j][c-'a'];
                    if (!dict[u]) dict[u] = dict[link[u]];
                }
                q.push(u);
            }
        }
    }
    
    void process(int pos, int cur) {
        cur = dict[cur];
        while (cur) {
            for (auto a: ind[cur]) oc[a.f].pb(pos-a.s+1);
            cur = dict[link[cur]];
        }
    }
    
    int nex(int pos, int cur, char c) {
        while (cur != -1 && to[cur][c-'a'] == MOD) cur = link[cur];
        if (cur == -1) cur = 0;
        else cur = to[cur][c-'a'];
        process(pos, cur);
        return cur;
    }
};

Aho<MX> A = Aho<MX>();
int a[MX];
string b[MX];

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string ret; cin >> ret;
    cin >> n;
    FOR(i,1,n+1) {
        cin >> a[i] >> b[i];
        A.add(b[i]);
    }
    A.push_links();
    
    int cur = 0;
    F0R(i,sz(ret)) cur = A.nex(i,cur,ret[i]);
    FOR(i,1,n+1) {
        int ans = MOD;
        for (int j = 0; j+a[i]-1 < sz(A.oc[i]); ++j) ans = min(ans,A.oc[i][j+a[i]-1]+sz(b[i])-A.oc[i][j]); 
        if (ans == MOD) cout << "-1\n";
        else cout << ans << "\n";
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)