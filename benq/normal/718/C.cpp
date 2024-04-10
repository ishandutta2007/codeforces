#include <bits/stdc++.h>
 
using namespace std;

#define F0R(i,a) for (int i = 0; i < a; ++i)

typedef long long ll;
typedef vector<ll> vi;

const ll INF = 1e18;
const int MOD = 1000000007;

struct mat {
	ll d[2][2];
	
	mat() {
		d[0][0] = d[0][1] = d[1][0] = d[1][1] = 0;
	}
	mat operator*(const mat& m) {
		mat C;
		F0R(i,2) F0R(j,2) F0R(k,2) C.d[i][j] = (C.d[i][j]+d[i][k]*m.d[k][j]) % MOD;
		return C;
	}
	mat operator+(const mat& m) {
		mat C;
		F0R(i,2) F0R(j,2) C.d[i][j] = (d[i][j]+m.d[i][j]) % MOD;
		return C;
	}
};

mat init(int a, int b, int c, int d) {
	mat C;
	C.d[0][0] = a, C.d[0][1] = b;
	C.d[1][0] = c, C.d[1][1] = d;
	return C;
}

mat po(ll p) {
    mat ans = init(1,0,0,1);
    mat m = init(1,1,1,0);
    while (p) {
        if (p&1) ans = ans*m;
        m = m*m;
        p /= 2;
    }
    return ans;
}

template<int SZ>
class LazySegTree { 
	public:
		mat lazy[2*SZ]; 
		mat sum[2*SZ];
		
		LazySegTree() {
			F0R(i,2*SZ) sum[i] = init(0,0,1,0);
			F0R(i,2*SZ) lazy[i] = init(1,0,0,1);
		}
		
		void push(int ind, int L, int R) {
			sum[ind] = lazy[ind]*sum[ind];
			if (L != R) {
				lazy[2*ind] = lazy[2*ind]*lazy[ind];
				lazy[2*ind+1] = lazy[2*ind+1]*lazy[ind];
			}
			lazy[ind] = init(1,0,0,1);
		}
		
		void build() {
			for (int i = SZ-1; i > 0; --i) sum[i] = sum[2*i]+sum[2*i+1];
		}
		
		void pull(int ind) {
			sum[ind] = sum[2*ind]+sum[2*ind+1];
		}
		 
		mat qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
			push(ind,L,R);
			if (lo > R || L > hi) return init(0,0,0,0);
			if (lo <= L && R <= hi) return sum[ind];
			
			int M = (L+R)/2;
			return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
		}
		 
		void upd(int lo, int hi, mat inc, int ind = 1, int L = 0, int R = SZ-1) { // take account for minimum as well
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
 
LazySegTree<1<<17> seg;
int n,m;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	F0R(i,n) {
		int x; cin >> x;
		seg.sum[i+(1<<17)] = po(x)*seg.sum[i+(1<<17)];
	}
	
	seg.build();
	F0R(i,m) {
		int tp, l, r; cin >> tp >> l >> r;
		l--, r--;
		if (tp == 1) {
			int x; cin >> x;
			seg.upd(l,r,po(x));
		} else {
			cout << seg.qsum(l,r).d[0][0] << "\n";
		}
	}
}