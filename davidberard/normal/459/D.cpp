#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * D. Pashmak and Parmida's solution SEGTREE and FASTIO
 *   1. try coding fastio cause I've never done it
 *   2. more segtrees
 * 
 * PROBLEM
 *   List a, |a| = 1e6. a[i] < 1e9
 *   f(i, j, k) = # of indices k in [i, j] where a[k] == x
 *   How many pairs i <= j exist such that f(1, i, a[i]) > f(j, n, a[j])?
 *
 * FASTIO is explained inline
 *
 * SOLUTION:
 *   1. a[i] < 1e9 -> sparse so compress this.
 *   2. For each value of a[i] collect the set i which produce this a[i], in order of i
 *   3. Iterate through each set, and lv[i] = index in the set of this index
 *     a. for example if a = {1,2,1,2,1}
 *             1 -> indices (0, 2, 4)
 *             2 -> indices (1, 3)
 *        therefore lv[0] = 0, rv[0] = 2, lv[2] = 1, rv[2] = 1, etc.
 *   [ Make segtree that counts inversions ]
 *   4. Make segtree of rv values, keep empty.  Summing, Range queries, point updates
 *   5. Segtree stores rv values, and we insert rv values from right to left
 *   6. i goes from N-1 to 0. 
 *     a. inversions += Query(0, lv[i]+1)
 *     b. add(rv[i], +1)
 *     c. This works because we query "how many values below lv[i] exist in the segtree"
 *        and the segtree currently only contains values for the right elements of the array.
 */

inline char get() {
	// static so it only gets defined initially
	// S points to start, T points to end
	static char buf[100000], *S=buf, *T=buf;
	// only do this step if S == T, which means that we haven't 
	// read anything yet (static defs still hold)
	if(S == T) {
		//      fread(ptr, size of element in ptr, number of elements to read, stream) = # elements
		T = (S = buf) + fread(buf, 1, 100000, stdin);
		// if nothing read
		if(S == T) return EOF;
	}
	// this element, then increment
	return *S++;
}

inline void read(int& x) {
	static char c; x=0; int sgn = 1;
	// clear the nonzero chars and check for '-'
	for(c = get(); c < '0' || c > '9'; c=get()) if(c == '-') sgn = -1;
	for(; c >= '0' && c <= '9'; c=get()) x = x*10+c-'0';
	x = sgn*x;
}

struct segtree {
	vector<int> t;
	int h, n;
	segtree(int sz) {
		h = sizeof(int)*8 - __builtin_clz(sz-1);
		n = 1<<h; t = vector<int>(n<<1, 0);
	}
	int query(int l, int r) {
		int a = 0;
		for(l +=n , r+=n; l<r;l>>=1, r>>=1) {
			if(l%2) a += t[l++];
			if(r%2) a += t[--r];
		}
		return a;
	}
	void add(int p, int v) {
		for(p+=n;p>0;p>>=1) t[p] += v;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N;
	read(N);
	vector<int> a(N), lv(N), rv(N);
	map<int, vector<int>> mp;
	int iv=0;
	for(int &ii : a) {
		read(ii);
		if(mp.count(ii) == 0) mp[ii] = vector<int>();
		mp[ii].push_back(iv);
		++iv;
	}
	for(auto& ii : mp) {
		for(int j=0;j<ii.second.size();++j) {
			lv[ii.second[j]] = j;
			rv[ii.second[j]] = ii.second.size() - j- 1;
		}
	}
	segtree st(N);
	ll tot = 0;
	for(int i=N-1;i>=0;--i) {
		tot += st.query(0, lv[i]);
		st.add(rv[i], 1);
	}

	cout << tot << endl;

	return 0;
}