#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * 920F SUM and REPLACE (SEGTREE)
 *
 * PROBLEM:
 *   Queries of type SUM and REPLACE on an array of size n < 3e5
 *   SUM = sum the values
 *   REPLACE = replace ai = D(ai) in range
 *   D(ai) = # of divisors in range
 *   ai < 1e6
 *
 * SOLUTION:
 *   1. Precompute D[ai] (this is op, in this solution)
 *   2. Segtree which stores sum
 *   3. Updates in LINEAR time.  However, the number of operations
 *      that can occur is quite small, before the end (1 or 2) is reached.
 *      Do THIS:
 *    - Updates occur on the range. Update anything above.
 *    - Keep pointer to the next thing that needs to be updated
 *      * This is a union find.  The union find merges the destinations, so
 *        you FIND() on the following element.  You MERGE to the following
 *        element if you become 2.
 */



vector<bool> sv(1e3+10, true);
vector<int> primes;
vector<int> par(3e5+10, -1);

int op[1000001];

int FIND(int a) {
	if(par[a] == -1) return a;
	int b = FIND(par[a]);
	par[a] = b;
	return b;
}
void UNION(int v) {
	par[v] = FIND(v+1);
}

struct segtree {
	vector<ll> t;
	int n, h;
	segtree(vector<int> v) {
		h = sizeof(size_t)*8-__builtin_clz(v.size()-1);
		n = 1<<h;
		t = vector<ll>(n<<1, 0);
		for(int i=0;i<v.size();++i)
			t[i+n] = v[i];
		update(0, v.size());
	}
	void update(int l, int r) {
		for(l=(n+l)/2,r=(n+r+1)/2;l>0;l/=2,r=(r+1)/2) {
			for(int i=l;i<r;++i) {
				t[i] = t[i<<1]+t[i<<1|1];
			}
		}
	}
	void replace(int l, int r) {
		int lo = l;
		l = FIND(l);
		int p = l, lp = l;
		for(;p < r;p=FIND(p+1)) {
			if( p < lo ) exit(1);
			t[p+n] = op[t[p+n]];
			update(p, p+1);
			if(t[p+n] <= 2)
				UNION(p);
			lp = p;
		}
	}
	ll query(int l, int r) {
		ll sum = 0;
		for(l+=n,r+=n;l<r;l/=2,r/=2) {
			if(l%2) sum += t[l++];
			if(r%2) sum += t[--r];
		}
		return sum;
	}
};

inline char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T=(S=buf)+fread(buf, 1, 100000, stdin);
		if(T==S) return EOF;
	}
	return *S++;
}
inline void read(int& x){
	static char c; x=0;int s=1;
	for(c=get();c<'0'||c>'9';c=get()) if(c=='-')s=-1;
	for(;c>='0'&&c<='9';c=get())x=x*10+c-'0';
	x*=s;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	memset(op, 0, sizeof op);
	for (int i = 1; i <= sqrt(1e6); i++) {
		op[i*i]++;
		for (int j = i*(i+1); j <= 1e6; j+= i)
			op[j] += 2;
	}

	int N, M;
	read(N); read(M);
	vector<int> a(N);
	for(int i=0;i<N;++i) {
		read(a[i]);
	}
	segtree st(a);
	int t, l, r;
	for(int i=0;i<M;++i) {
		read(t); read(l); read(r);
		--l;
		if(t == 1) { // replace
			st.replace(l, r);
		} else { // query
			cout << st.query(l, r) << "\n";
		}
	}

	return 0;
}