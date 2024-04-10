#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

const int MOD = 1000000007;
const int MX = 500001;

int n,m,k;
vi cur[MX], tmp[MX];
vector<pii> par[MX];
vector<vi> edge;

void unite(int a, int b, int w) {
    int A = par[a].back().s, B = par[b].back().s;
    if (cur[A].size() < cur[B].size()) swap(A,B), swap(a,b);
    for (int i: cur[B]) {
        par[i].pb({w,A});
        cur[A].pb(i);
    }
    cur[B].clear();
}

int PAR[MX];

int getpar(int x) {
    if (PAR[PAR[x]] != PAR[x]) PAR[x] = getpar(PAR[x]);
    return PAR[x];
}

int get(int wei, int ind) {
    // before that weight
    auto it = lb(par[ind].begin(),par[ind].end(),mp(wei,-1));
    return prev(it)->s;
}

bool test(int wei, vector<pii> z) {
    for (auto a: z) {
        PAR[a.f] = get(wei,a.f);
        PAR[PAR[a.f]] = PAR[a.f];
        PAR[a.s] = get(wei,a.s);
        PAR[PAR[a.s]] = PAR[a.s];
    } 
    for (auto a: z) {
        int x = getpar(a.f), y = getpar(a.s);
        if (x == y) return 0;
        if (rand()&1) swap(x,y);
        PAR[x] = y;
    }
    return 1;
}

void solve() {
    cin >> k;
    map<int,vector<pii>> z;
    F0R(i,k) {
        int o; cin >> o;
        z[tmp[o][0]].pb({tmp[o][1],tmp[o][2]});
    }
    for (auto& a: z) if (!test(a.f, a.s)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	FOR(i,1,m+1) {
	    int a,b,w; cin >> a >> b >> w;
	    tmp[i] = {w,a,b};
	    edge.pb(tmp[i]);
	}
	FOR(i,1,n+1) {
	    par[i].pb({0,i});
	    cur[i].pb(i);
	}
	sort(edge.begin(),edge.end());
	for (auto a: edge) if (par[a[1]].back().s != par[a[2]].back().s) unite(a[1],a[2],a[0]);
	
	int q; cin >> q;
	F0R(i,q) solve();
}

// read!
// ll vs. int!