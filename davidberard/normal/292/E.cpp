#include <bits/stdc++.h>
#define nl "\n"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * 292E - Copying Data: SEGTREE
 * 
 * Two arrays a and b, of length n.
 * Two types of queries:
 *   1. Starting from position x in array a, copy k elements and paste&replace
 *      into array b, starting from position y, so b[y+i] = a[x+i] now.
 *   2. Query the value at position x in array b
 *
 * SOLUTION - Segtree storing where to look, when this was updated
 *   1. Segtree stores pairs <offset, timestamp>.
 *   2. Range updates, point queries.
 *   3. Offset = where to look in array a.  For example, offset of -3 in
 *      range [4,7) means that b[4] = a[4-3=1], b[5] = a[2], etc.
 *   4. Last timestamp = most recent, the one to keep
 *   5. segtree of type d, so update those and queries take lg time to
 *      add up.
 */

inline char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T = (S=buf) + fread(buf, 1, 100000, stdin);
		if(S == T) return EOF;
	}
	return *S++;
}
inline void read(int& x) {
	static char c; x=0; int sgn = 1;
	for(c=get();c<'0' || c>'9';c=get()) if(c=='-') sgn = -1;
	for(;c >='0' && c <='9';c=get()) x=x*10+c-'0';
	x*=sgn;
	//cerr << " r " << x << endl;
}

struct segtree{
	vector<pii> d;
	int n, h, ti;
	const static int START = 1e7+5;
	segtree(int sz) {
		h = sizeof(int)*8 - __builtin_clz(sz);
		n = 1<<h; ti = 0;
		d = vector<pii>(n<<1, pii(START, -1));
	}
	int query(int i, const vector<int>& a, const vector<int>& b) {
		int icp = i;
		pii ans(START, -1);
		for(i+=n;i>0;i/=2)
			ans = (d[i].second > ans.second)?d[i]:ans;
		if(ans.first == START) return b[icp];
		return a[icp+ans.first];
	}
	void set(int l, int r, int val) {
		for(l+=n,r+=n;l<r;l/=2,r/=2) {
			if(l%2) d[l++] = pii(val, ti);
			if(r%2) d[--r] = pii(val, ti);
		}
		++ti;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int N, Q;
	read(N); read(Q);
	vector<int> a(N), b(N);
	segtree st(N);
	for(auto &ii: a) read(ii);
	for(auto &ii: b) read(ii);

	int type, x,y,k;
	for(int q=0;q<Q;++q) {
		read(type);
		if(type == 1) {
			read(x);read(y);read(k);
			st.set(y-1, y+k-1, x-y);
		} else {
			read(x);
			cout << st.query(x-1, a, b) << nl;
		}
	}

	return 0;
}