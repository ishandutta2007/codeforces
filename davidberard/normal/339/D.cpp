#include <bits/stdc++.h>
#define nl "\n"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

/**
 * 339D. Xenia and Bit Operations: THE SEGTREE BOOTCAMP
 * 
 * NO lazy propagation
 * 
 * - Segtree with val(x) = val(x.left) | val(x.right)
 * - There are 2^n values
 * - Queries p, b : m of them
 *   + this means that a[p] = b
 */

int N, M;

struct stree {
	vector<int> v;
	int h,n;
	stree() {}
	stree(const vector<int>& nv) {
		h = 0;
		for(int vs=nv.size()-1;vs>0;++h,vs/=2);
		n = 1<<h;
		v = vector<int>((1<<(h+1)), 0);
		for(int i=0;i<nv.size();++i)
			v[i+n] = nv[i];
		for(int i=n-1,iter=0;i>0;--i) {
			v[i]=(iter ? (v[i<<1]^v[i<<1|1]) : (v[i<<1]|v[i<<1|1]) );
			if(!(i&(i-1))) {
				iter++;iter%=2;
			}
		}
	}
	void set(int pos, int val) {
		v[pos+n] = val;
		for(int pp=pos+n, iter=0;pp>1;iter=(iter+1)%2) {pp>>=1; v[pp]=(iter ? (v[pp<<1]^v[pp<<1|1]) : (v[pp<<1]|v[pp<<1|1]) ); }
	}
	int query() {
		return v[1];
	}
};


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	vector<int> a(1<<N);
	for(int i=0;i<(1<<N);++i) {
		cin >> a[i];
	}
	stree st(a); int p, b;
	for(int i=0;i<M;++i) {
		cin >> p >> b;
		--p;
		st.set(p, b);
		cout << st.query() << nl;
	}
	
	return 0;
}