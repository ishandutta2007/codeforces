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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 200001;

int mul(int x, int y) { return (ll)x*y%MOD; }
int ad(int x, int y) { return (x+y)%MOD; }

const int SZ = 1<<18;

struct LazySegTree {
    int sum[2*SZ];
    pi lazy[2*SZ]; 
    
    LazySegTree() {
        memset (sum,0,sizeof sum);
        F0R(i,2*SZ) lazy[i] = {1,0};
    }
    
    void prop(int ind) {
    	lazy[ind].f = mul(lazy[ind].f,lazy[ind/2].f);
    	lazy[ind].s = ad(mul(lazy[ind].s,lazy[ind/2].f),lazy[ind/2].s);
    }
    
    void push(int ind, int L, int R) {
        sum[ind] = ad(mul(lazy[ind].f,sum[ind]),mul(R-L+1,lazy[ind].s));
        if (L != R) prop(2*ind), prop(2*ind+1);
        lazy[ind] = {1,0};
    }
    
    void pull(int ind) {
        sum[ind] = ad(sum[2*ind],sum[2*ind+1]);
    }
    
    void build() {
        F0Rd(i,SZ) pull(i);
    }
    
    int qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        
        int M = (L+R)/2;
        return ad(qsum(lo,hi,2*ind,L,M),qsum(lo,hi,2*ind+1,M+1,R));
    }

    void upd(int lo, int hi, pi inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree Seg;

int n,q;
set<pi> con[MX];

void solve1() {
	int L,R,x; cin >> L >> R >> x;
	int l = L;
	while (l <= R) {
		auto it = con[x].lb({l,MOD});
		if (it != con[x].begin() && prev(it)->s >= l) it = prev(it);
		
		if (it == con[x].end() || it->f > R) {
			Seg.upd(l,R,{1,1});
			break;
		}
		
		Seg.upd(l,it->f-1,{1,1});
		if (it->f < L) con[x].insert({it->f,L-1});
		if (it->s > R) con[x].insert({R+1,it->s});
		
		Seg.upd(max(l,it->f),min(it->s,R),{2,0});
		l = it->s+1;
		con[x].erase(it);
	}
	con[x].insert({L,R});
}

void solve2() {
	int l,r; cin >> l >> r;
	cout << Seg.qsum(l,r) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	F0R(i,q) {
		int t; cin >> t;
		if (t == 1) solve1();
		else solve2();
	}
}