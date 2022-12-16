#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

/**
 * @52C@ Circular RMQ (Lazy Segtree!)
 * 
 * Question: array 2e5, elements to 1e6, two operations:
 *   1. inc() increments all elements in segment by v
 *   2. rmq() returns min value in segment
 * Also, this is circular, so if l > r, then it cycles.
 * 
 * SOLUTION
 *   Circular: Just split into to parts.
 *   Lazy Segtree: my first time coding it, so an explanation:
 *   - t type segtrees = point updates, range queries
 *   - d type segtrees = range updates, point queries
 *   - combine to make a lazy segtree
 *   - Things are stored in t type, but if you make a range update
 *     then you cache the change in a d type, and before querying or
 *     updating you "push" the changes down to the edges that you
 *     are observing.
 *   - d stores "something that must be changed BELOW me, so you can
 *     have an updated t layer that still has d in it
 *
 */

struct segtree{
	vector<ll> t, d;
	int h, n;
	segtree(vector<int>& v) {
		//if(v.size() == 1) h = 0;
		int sz = v.size();
		if(sz == 1) h = 1;
		else h = sizeof(int)*8 - __builtin_clz(sz-1);
		n = 1 << h;
		d = vector<ll>(n, 0);
		t = vector<ll>(n<<1, 0);
		for(int i=0;i<v.size();++i) t[i+n] = v[i];
		for(int i=n-1;i>0;--i) t[i] = min(t[i<<1],t[i<<1|1]);
	}
	void apply(int p, ll v) {
		t[p] += v;
		//cerr << "APPLY: " << p << " vs " << t.size();
		if(p < n) {
			d[p] += v;
			//cerr << ", " << d.size();
		}
		//cerr << endl;
	}
	void push(int p) {
		int x;
		for(int s=h;s>0;--s) { // start at top, go down
			x = p>>s;
			//cerr << "PUSH: " << x << " vs " << d.size() << endl;
			if(d[x] != 0) {
				apply(x<<1, d[x]);
				apply(x<<1|1, d[x]);
				d[x] = 0;
			}
		}
	}
	void build(int p) {
		while(p>1) {
			p/=2;
			//cerr << "BUILD: " << p << " vs " << t.size() << endl;
			t[p] = min(t[p<<1], t[p<<1|1]) + d[p];
		}
	}
	void inc(int l, int r, ll v) {
		////cerr << "INC " << l << " " << r << " " << v << endl;
		int l0 = l+n, r0=r+n;
		push(l0), push(r0-1);
		for(l=l+n,r=r+n;l<r;r/=2, l/=2) {
			if(l&1) apply(l++, v);
			if(r&1) apply(--r, v);
		}
		//push(l0), push(r0-1);
		build(l0); build(r0-1);
		////cerr;for(int i=n;i<n*2;++i)
			////cerr << t[i] << " " ; ////cerr << endl;
	}
	ll rmq(int l, int r) {
		////cerr;int l0 = l, r0 = r;
		ll tot = (ll) 1e8 * 1e8;
		push(l+n), push(r+n-1);
		for(l=l+n, r=r+n; l<r; l>>=1, r>>=1) {
			if(l&1) tot = min(tot, t[l++]);
			if(r&1) tot = min(tot, t[--r]);
		}
		////cerr << "RMQ " << l0 << " " << r0 <<" = " << tot << endl;
		return tot;
	}
	void printarr(vector<ll>& v) {
		int x= 1 << h;
		for(int i=1;i<v.size();++i) {
			if(__builtin_clz(i) != __builtin_clz(i-1) && i != 1) {
				x /= 2;
				cout << "\n";
			}
			for(int j=0;j<x-1;++j) cout << " ";
			cout << v[i];
			for(int j=0;j<x;++j) cout << " ";
		}
		cout << "\n" ;
	}
	void print() {
		cout << "  t:\n";
		printarr(t);
		cout << "  d:\n";
		printarr(d);
		cout << "\n";
	}
};

inline char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T=(S=buf)+fread(buf, 1, 100000, stdin);
		if(S==T) return EOF;
	}
	return *S++;
}
inline bool read(int& x) {
	static char c = 'x'; x=0; int s = 1;
	for(;c < '0' || c > '9';c=get()) if(c=='-') s=-1;
	for(;c >='0' && c <='9';c=get()) x = x*10+c-'0';
	for(;c != '\n' && c != EOF && (c < '0' || c > '9') && c != '-';c=get());
	x*=s;
	return (c != '\n' && c != EOF);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N; read(N);
	vector<int> A(N);
	for(auto& ii : A) read(ii);
	segtree st(A);
	int M; read(M);
	int a, b, c;
	//cout << "~~~~~\n\n\n";
	for(int i=0;i<M;++i) {
		////cerr << i << endl;
		read(a);
		if(read(b)) {
			read(c);
			if(a > b) {
				st.inc(a, N, c);
				st.inc(0, b+1, c);
			} else st.inc(a, b+1, c);
			//cout<< i << ". INC(" << a << "," << b << "," << c << ")" << "\n";
			//st.print();
		} else {
			ll ans;
			if( a > b )
				ans = min(st.rmq(a, N), st.rmq(0, b+1));
			else ans = st.rmq(a, b+1);
			//cout << i <<". RMQ(" << a << "," << b << ") = " << ans << "\n";
			//st.print();
			cout << ans << "\n";
		}
	}
	return 0;
}