#include <bits/stdc++.h>
#define nl "\n"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * 19D Points - SEGTREE
 * 
 * PROBLEM: 2d grid, given queries:
 *   add, remove, find (x,y)
 *   add, remove are obvious
 *   find: find the leftmost point which is above and to the right of x,y.
 *         if multiple points exist, lowest of these.
 *   x,y up to 1e9, up to 2e5 queries.
 * 
 * SOLUTION - Segtree and 2e5 sets
 *   1. Compress to 2e5 (x,y compression) -> read beforehand
 *   2. Segtree: along x axis, length = max(x) (after compression)
 *               Stores tallest y value encountered along stretch
 *               Point updates
 *   2.1 Segtree Queries on range l, r, threshold t
 *     a. Find the leftmost seg with max.height > threshold
 *     b. Go down the segment to find leftmost point > threshold
 *     c. Return index of point
 *   3. Sets: keep set for each x column to query the lowest possible in the set
 */

char iic = 0;
inline char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T = (S=buf) + fread(buf, 1, 100000, stdin);
		if(S==T) return EOF;
	}
	return *S++;
}
inline void read(int& x) {
	x=0; int sgn = 1;
	for(;iic<'0' || iic>'9';iic=get()) if(iic=='-') sgn = -1;
	for(;iic>='0' && iic<='9';iic=get()) x=x*10+iic-'0';
	x*=sgn;
}
inline bool riwsp(const char& c) {
	return (c==' ' || c=='\n' || c==EOF || c=='\r');
}
inline void read(string& s) {
	static char buf[100]; int pos=0;
	for(;riwsp(iic);iic=get());
	for(;!riwsp(iic);iic=get(),++pos) buf[pos] = iic;
	buf[pos] = 0;
	s=string(buf);
}


struct segtree{
	vector<int> t;
	int n,h;
	segtree(int sz) {
		h = sizeof(int)*8 - __builtin_clz(sz-1);
		n = 1<<h;
		t= vector<int>(n<<1, 0);
	}
	void set(int i, int v) {
		t[i+n]=v;
		for(i=(i+n)/2;i>0;i/=2) t[i] = max(t[i<<1],t[i<<1|1]);
	}
	int query(int l, int r, int threshold) {
		int e = 2*n;
		r = n;
		for(int lcpy=l+n, rcpy=r+n; lcpy<rcpy; lcpy/=2,rcpy/=2) {
			if(lcpy%2) { if(t[lcpy++] >= threshold) {e=lcpy-1; break;} }
			if(rcpy%2) { if(t[--rcpy] >= threshold) e=rcpy; }
		}
		
		while(e < n) {
			e <<= 1;
			if(t[e] < threshold) ++e;
		}
		return e-n;
	}
};

struct qry {
	string s;
	int x, y;
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	read(N);
	string s;
	vector<qry> q(N);
	map<int, int> xmp;
	for(int i=0;i<N;++i) {
		read(q[i].s);read(q[i].x);read(q[i].y);
		xmp[q[i].x] = 0;
	}
	vector<int> revx;
	int cnt = 0, xmax;
	for(auto& ii:xmp) {ii.second=cnt++;revx.push_back(ii.first);}
	xmax = cnt;

	segtree st(xmax);
	vector<set<int>> vs(xmax);

	for(int i=0;i<N;++i) {
		int mv = xmp[q[i].x];
		switch(q[i].s[0]) {
			case 'a':
				vs[mv].insert(q[i].y);
				st.set(mv, *(vs[mv].rbegin()));
				break;
			case 'r':
				vs[mv].erase(q[i].y);
				if(vs[mv].size() > 0)
					st.set(mv, *(vs[mv].rbegin()));
				else
					st.set(mv, 0);
				break;
			case 'f':
				int xv = st.query(mv+1, xmax, q[i].y+1);
				if(xv >= xmax) {
					cout << -1 << nl;
					break;
				}
				int best = *(vs[xv].lower_bound(q[i].y+1));
				cout << revx[xv] << " " << best << nl;
				break;
		}
	}
	
	return 0;
}