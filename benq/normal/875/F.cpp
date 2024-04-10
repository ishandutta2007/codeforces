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

int n,m;
vector<vi> edge;


template<int SZ> struct DSU {
    int par[SZ], sz[SZ], numedge[SZ];
    DSU() {
        F0R(i,SZ) par[i] = i, sz[i] = 1, numedge[i] = 0;
    }
    
    int get(int x) { // path compression
    	if (par[x] != x) par[x] = get(par[x]);
    	return par[x];
    }
    
    bool unite(int x, int y) { // union-by-rank
    	x = get(x), y = get(y);
    	if (x == y) {
    	    if (numedge[x] == sz[x]) return 0;
    	    numedge[x] ++; return 1;
    	} else {
    	    if (sz[x] < sz[y]) swap(x,y);
    	    if (numedge[x] == sz[x] && numedge[y] == sz[y]) return 0;
    	    numedge[x] += 1+numedge[y];
    	    sz[x] += sz[y]; par[y] = x;
    	    return 1;
    	}
    }
};

DSU<200001> D;
int ans = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,m) {
	    int a,b,w; cin >> a >> b >> w;
	    edge.pb({w,a,b});
	}
	sort(edge.begin(),edge.end()); reverse(edge.begin(),edge.end());
	for (auto a: edge) if (D.unite(a[1],a[2])) ans += a[0];
	cout << ans;
}

// read!
// ll vs. int!