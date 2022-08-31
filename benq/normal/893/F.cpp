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

int n,r,lst=0;
vi adj[100001];

int get(vector<pii>& v, int k) { // last one such that depth <= k
    int lo = -1, hi = v.size()-1;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        if (v[mid].f <= k) lo = mid;
        else hi = mid-1;
    }
    if (lo == -1) return MOD;
    return v[lo].s;
}

template<int SZ> struct Seg {
    typedef vector<pii> T;
    T seg[2*SZ];
    
    void build() {
        FORd(i,1,SZ) {
            for (auto j: seg[2*i]) seg[i].pb(j);
            for (auto j: seg[2*i+1]) seg[i].pb(j);
            sort(seg[i].begin(),seg[i].end());
            FOR(j,1,seg[i].size()) seg[i][j].s = min(seg[i][j].s,seg[i][j-1].s);
        }
    }
    
    int query(int l, int r, int k) {  // min on interval [l, r)
        int res = MOD; 
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = min(res,get(seg[l++],k));
            if (r&1) res = min(res,get(seg[--r],k));
        }
        return res;
    }
};

Seg<1<<17> S;

int st[100001], en[100001], depth[100001], A[100001];
vi z;

void euler(int pre, int cur) {
    st[cur] = z.size();
    depth[cur] = depth[pre]+1;
    S.seg[st[cur]+(1<<17)].pb({depth[cur],A[cur]});
    z.pb(cur);
    for (int i: adj[cur]) if (i != pre) euler(cur,i);
    en[cur] = z.size();
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> r;
	FOR(i,1,n+1) cin >> A[i];
	F0R(i,n-1) {
	    int a,b; cin >> a >> b;
	    adj[a].pb(b), adj[b].pb(a);
	}
	euler(0,r);
	S.build();
	
	int m; cin >> m;
	F0R(i,m) {
	    int p,q; cin >> p >> q;
	    int x = (p+lst)%n+1, k = (q+lst)%n;
	    lst = S.query(st[x],en[x],depth[x]+k);
	    cout << lst << "\n";
	}
}

// read!
// ll vs. int!