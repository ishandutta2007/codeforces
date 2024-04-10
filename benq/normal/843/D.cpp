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
const int MX = 100005;

int n,m,q,b[MX],c[MX], change[MX],st[MX];
queue<int> todo[MX];
int ed[MX];
ll dist[MX];
vi adj[MX];

void Dijkstra() {
    FOR(i,1,n+1) dist[i] = INF;
    priority_queue<pl,vpl,greater<pl>> p; 
    dist[1] = 0; p.push({0,1});
    while (sz(p)) {
        auto a = p.top(); p.pop();
        if (a.f > dist[a.s]) continue;
        for (int x: adj[a.s]) if (a.f+c[x] < dist[b[x]]) 
            p.push({dist[b[x]] = a.f+c[x],b[x]});
    }
}

void process(int x) {
    FOR(i,2,n+1) change[i] = MOD;
    todo[0].push(1);
    F0R(i,x+1) while (sz(todo[i])) {
        int t = todo[i].front(); todo[i].pop();
        if (change[t] < i) continue;
        FOR(z,st[t],st[t+1]) {
            int y = ed[z];
            int ne = i+c[y]+dist[t]-dist[b[y]];
            if (ne < change[b[y]]) {
                change[b[y]] = ne;
                if (ne <= x) todo[ne].push(b[y]);
            }
        }
    }
    FOR(i,1,n+1) dist[i] += change[i];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    FOR(i,1,m+1) {
        int a;
        cin >> a >> b[i] >> c[i];
        adj[a].pb(i);
    }
    int co = 0;
    FOR(i,1,n+2) {
        st[i] = co;
        for (int j: adj[i]) ed[co++] = j;
    }
    
    Dijkstra();
    F0R(i,q) {
        int t; cin >> t;
        if (t == 1) {
            int v; cin >> v;
            if (dist[v] >= INF) cout << "-1\n";
            else cout << dist[v] << "\n";
        } else {
            int num; cin >> num;
            F0R(i,num) {
                int l; cin >> l;
                c[l] ++;
            }
            process(min(num,n));
        }
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/