#include <bits/stdc++.h>
#define nl "\n"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * 474F Ant Colony - SEGTREES
 *
 * PROBLEM 
 * Some story about eating ants...
 * 1e5 array, 1e5 query.  Array is of integers
 * Queries l, r.  How many integers in the segment = gcd of all a[i] in seg?
 *
 * SOLUTION
 *   1. Segtree stores gcd, # of integers that = gcd in segment
 *   2. Transistions: combine(a, b)
 *     a. GCD = gcd(gcd1, gcd2)
 *     b. IF GCD = gcd1, add count1, if GCD == gcd2, add count2
 *   3. yup.  Build and query, no updates.
 */

inline char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T = (S=buf) + fread(buf, 1, 100000, stdin);
		if(S==T) return EOF;
	}
	return *S++;
}
inline void read(int& x) {
	static char c; x = 0; int sgn = 1;
	for(c=get();c<'0' || c>'9';c=get()) { if(c=='-') sgn = -1; }
	for(;c>='0' && c<='9';c=get()) { x = x*10+c-'0'; }
	x *= sgn;
}

pii combo(pii a, pii b) {
	if(a.first == 0) return b;
	if(b.first == 0) return a;
	pii out(__gcd(a.first, b.first), 0);
	out.second = (a.second*(out.first == a.first) + b.second*(out.first == b.first));
	return out;
}

struct segtree {
	vector<pii> t;
	int n, h;
	segtree(const vector<int>& v) {
		h = sizeof(size_t)*8 - __builtin_clz(v.size()-1);
		n = 1<<h;
		t = vector<pii>(n<<1);
		for(size_t i=0;i<v.size();++i)
			t[i+n] = pii(v[i], 1);
		for(int i=n-1;i>0;--i)
			t[i] = combo(t[i<<1],t[i<<1|1]);
	}
	int query(int l, int r) {
		pii a(0, 0);
		for(l+=n, r+=n; l<r;l/=2,r/=2) {
			if(l%2) a = combo(a, t[l++]);
			if(r%2) a = combo(a, t[--r]);
		}
		return a.second;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	read(N);
	vector<int> a(N);
	for(int &ii:a) read(ii);
	segtree st(a);

	int T, l, r;
	read(T);
	for(;T>0;--T) {
		read(l);read(r);
		--l;
		cout << r-l - st.query(l, r) << nl;
	}

	return 0;
}