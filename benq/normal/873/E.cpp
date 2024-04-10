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

struct RMQ {
    pii stor[3001][12];
    void build(vector<pii>& x) {
        F0R(i,3001) F0R(j,12) stor[i][j] = {-1,-1};
        F0R(i,x.size()) stor[i][0] = x[i];
        FOR(j,1,12) F0R(i,3001-(1<<(j-1))) 
            stor[i][j] = max(stor[i][j-1],stor[i+(1<<(j-1))][j-1]);
    }
    pii query(int l, int r) {
        int x = 31-__builtin_clz(r-l+1);
        assert(l+(1<<x)-1 <= r);
        assert((r-l+1) <= (2<<x));
        return max(stor[l][x],stor[r-(1<<x)+1][x]);
    }
};

RMQ R;

int n, ans[3000];
vi bes;
vector<pii> a;

void start() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    int x; cin >> x;
	    a.pb({x,i});
	}
	sort(a.begin(),a.end()); reverse(a.begin(),a.end());
	a.pb({0,-1});
	
	vector<pii> z = {{-1,0}};
	FOR(i,1,n+1) {
	    z.pb({a[i-1].f-a[i].f,i});
	    assert(z[i].f >= 0);
	}
	R.build(z);
} // 1st to the nth 

void finish() {
	F0R(i,bes[3]) ans[a[i].s] = 1;
	FOR(i,bes[3],bes[4]) ans[a[i].s] = 2;
	FOR(i,bes[4],bes[5]) ans[a[i].s] = 3;
	FOR(i,bes[5],n) ans[a[i].s] = -1;
	F0R(i,n) cout << ans[i] << " ";
}

void test(int x, int y) {
    int lo = 1, hi = n;
    lo = max(lo,(x+1)/2); hi = min(hi,2*x);
    lo = max(lo,(y-x+1)/2), hi = min(hi,2*(y-x));
    hi = min(hi,n-y);
    if (lo > hi) return;
    
    pii t = R.query(y+lo,y+hi); // a[x-1].f-a[x].f
    assert(y+lo <= t.s && t.s <= y+hi);
    vi tmp = {a[x-1].f-a[x].f,a[y-1].f-a[y].f,t.f,x,y,t.s};
    bes = max(bes,tmp);
}

int main() {
    start();
    FOR(i,1,n) FOR(j,i+1,n) if (2*i >= (j-i) && 2*(j-i) >= i) test(i,j);
    finish();
}

// read!
// ll vs. int!