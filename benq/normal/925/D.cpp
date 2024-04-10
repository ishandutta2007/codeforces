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
const int MX = 300001;

int n,m,dist[MX], pre[MX], DIST[MX], tot;
set<int> adj[MX];

void finish(vi x) {
    cout << sz(x)-1 << "\n";
    for (int i: x) cout << i << " ";
    exit(0);
}

void test4() {
    if (dist[n] <= 4) {
        vi v = {n};
        while (v.back() != 1) v.pb(pre[v.back()]);
        reverse(all(v));
        finish(v);
    }
    for (int i: adj[1]) 
        for (int j: adj[i]) if (j != 1 && !adj[1].count(j)) 
            finish({1,i,j,1,n});
}

void fillDist(int t) {
    if (t == 1) {
        FOR(i,1,n+1) dist[i] = MOD;
        queue<int> q; q.push(t); dist[t] = 0;
        tot ++;
        while (sz(q)) {
            int x = q.front(); q.pop();
            for (int i: adj[x]) if (dist[i] == MOD) {
                dist[i] = dist[x]+1;
                pre[i] = x;
                q.push(i);
                if (t == 1) tot ++;
            }
        }
    } else {
        FOR(i,1,n+1) DIST[i] = MOD;
        queue<int> q; q.push(t); DIST[t] = 0;
        while (sz(q)) {
            int x = q.front(); q.pop();
            for (int i: adj[x]) if (DIST[i] == MOD && i != 1) {
                DIST[i] = DIST[x]+1;
                pre[i] = x;
                q.push(i);
            }
        }
    }
}

void test5() {
    if (dist[n] == 5) {
        vi v = {n};
        while (v.back() != 1) v.pb(pre[v.back()]);
        reverse(all(v));
        finish(v);
    }
    FOR(i,2,n+1) if (dist[i] == 1 && sz(adj[i]) != tot-1) {
        fillDist(i);
        FOR(j,1,n+1) if (DIST[j] == 2) finish({1,i,pre[j],j,i,n});
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,m) {
        int a,b; cin >> a >> b;
        adj[a].insert(b), adj[b].insert(a);
    }
    fillDist(1);
    test4();
    test5();
    cout << -1;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)