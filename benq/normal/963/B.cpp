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
const int MX = 200001;

int n, p[MX], evensub[MX], root, deg[MX], done[MX], sub[MX];
vi adj[MX];
queue<int> todo;

void genEvenSub(int a, int b) {
    sub[a] = 1;
    for (int i: adj[a]) if (i != b) {
        genEvenSub(i,a);
        sub[a] += sub[i];
        if (sub[i] % 2 == 0) evensub[a] ++;
    }
}

void ad(int x) {
    if (evensub[x] == 0 && deg[x] == 0 && done[x] == 0) todo.push(x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i,1,n+1) {
        cin >> p[i];
        if (p[i] == 0) root = i;
        if (p[i]) adj[p[i]].pb(i), adj[i].pb(p[i]);
    }
    if (n % 2 == 0) {
        cout << "NO";
        return 0;
    }
    genEvenSub(root,0);
    FOR(i,1,n+1) deg[i] = (sz(adj[i])&1);
    FOR(i,1,n+1) if (evensub[i] == 0 && deg[i] == 0) todo.push(i);
    
    // current degree is even
    // no even subtrees
    // when you delete one, remove even from parent 
    cout << "YES\n";
    while (sz(todo)) {
        int x = todo.front(); todo.pop();
        if (done[x] || deg[x] || evensub[x]) continue;
        cout << x << "\n"; done[x] = 1;
        evensub[p[x]] --; ad(p[x]);
        for (int i: adj[x]) {
            deg[i] ^= 1;
            ad(i);
        }
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)