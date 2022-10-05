#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll inf = 1e9 + 5;
struct Node {
	Node *l = 0, *r = 0;
	ll lo, hi, mset = inf, madd = 0, val = 0, smol = inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vll& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = l->val + r->val;
			smol = min(l->smol, r->smol);
		}
		else val = v[lo], smol = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
	}
	
	int find(ll v) {
	    if (smol > v) return hi;
	    if (lo + 1 == hi) return lo;
	    if (mset <= v) return lo;
	    if (l->smol <= v) return l->find(v);
	    return r->find(v);
	}
	
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = x, val = (hi - lo) * x, smol = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = l->val + r->val;
			smol = min(l->smol, r->smol);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
	}
};

int n,q;

main() { FAST
	cin >> n >> q;
	vll l(n,0);
	for(int i = 0; i < n; i++){
	    ll v;
	    cin >> v;
	    l[i] = v;
	}
	
	Node seg = Node(l, 0, n);
	
	for (int it = 0; it < q; it++){
	    ll y;
	    int t, x;
	    cin >> t >> x >> y;
	    x -= 1;
	    
	    if (t == 1){
	        int left = seg.find(y);
	        if (x + 1 > left){
	            seg.set(left, x + 1, y);
	        }
	    }
	    else{
	        int out = 0;
	        
	        x = max(x, seg.find(y));
	        while (x < n){
	            ll dist = y / seg.query(x, x + 1);
	            int lo = min((ll) n - 1, x + dist - 1);
	            
	            y -= seg.query(x, lo + 1);
	            
	            out += (lo - x + 1);
	            x = max(lo + 1, seg.find(y));
	        }
	        
	        cout << out << '\n';
	    }
	}
}