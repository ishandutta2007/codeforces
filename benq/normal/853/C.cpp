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

ll n,q,p[200001];
vector<pair<int,pii>> v1[200002], v2[200002];
ll ans[200000];

template<int SZ> struct BIT {
    int bit[SZ+1];
    
    BIT() {
        memset(bit,0,sizeof bit);
    }
    
    void upd(int k, int val) {
        for( ;k <= n; k += (k&-k)) bit[k] += val;
    }
    
    int query(int k) {
        int temp = 0;
        for (;k > 0;k -= (k&-k)) temp += bit[k];
        return temp;
    }
    int query(int l, int r) { return query(r)-query(l-1); }
};

BIT<200000> B;

void zz(pair<int,pii> a) {
    ll c1 = B.query(a.s.f-1), c2 = B.query(a.s.s)-c1;
    ll c3 = B.query(n)-c1-c2;
    ll sum = c1+c2+c3;
    ans[a.f] -= (sum*(sum-1)/2-c1*(c1-1)/2-c3*(c3-1)/2);
}

void process() {
    FOR(i,1,n+1) {
        B.upd(p[i],1);
        for (auto a: v1[i]) zz(a);
    }
    memset(B.bit,0,sizeof B.bit);
    FORd(i,1,n+1) {
        B.upd(p[i],1);
        for (auto a: v2[i]) zz(a);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	FOR(i,1,n+1) cin >> p[i];
	F0R(i,q) {
	    ll l,d,r,u; cin >> l >> d >> r >> u;
	    ans[i] += n*(n-1)/2-(d-1)*(d-2)/2-(n-u)*(n-u-1)/2;
	    v1[l-1].pb({i,{d,u}});
	    v2[r+1].pb({i,{d,u}});
	}
	process();
	F0R(i,q) cout << ans[i] << "\n";
}

// read!
// ll vs. int!