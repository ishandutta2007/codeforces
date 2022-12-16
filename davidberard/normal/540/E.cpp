#include <bits/stdc++.h>
#define nl "\n"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * 540E Infinite Inversions (SEGTREE)
 *
 * Okay, this one is gonna suck to code.
 * Given a bunch of swap operations (10^5 operations), now determine # of inversions
 * Your initial array is 1 to 10^9...
 *
 * SOLUTION:
 *
 * Obviously 10^9 is too large, so we only consider elements which have been swapped.
 * Simulate all the swaps.  Elements that have been moved can be considered "removed"
 *   and also consider elements that are "added".
 * Consider an added element.  For demonstration, imagine that we've swapped 9, 4, 
 *   and we're considering 9 being placed at the position of the 4.  This introduces
 *   three considerations:
 *     a) Expected inversions with numbers 5-8
 *     b) Expected inversions that DO NOT occur due to removed elements
 *     c) Unexpected inversions that occur with added elements
 * So, do this.  For each added element, add a+c and then subtract b.
 *   If we consider the 4 in the 9 position, we can ignore "expected inversions"
 *     and "expected inversion that do not occur" and simply add unexpected invs.
 * ALSO I FORGOT SOMETHING READ (4) BELOW
 *
 * IMPLEMENTATION
 * 1. Simulation
 *    - Map position -> number and number -> position.
 *    - If you ever move something back to its location, remove from map for simplicity
 *
 * 2. Expected inversions that do not occur, i.e. removals
 *    - Put the removed *positions* in a vector and sort. 
 *    - When we get a number, (ex 4,9 swap), get upper_bound(9-1) and lower_bound(4+1)
 *      and subtract the indices to get # of removals in this range
 *
 * 3. Unexpected inversions - THE SEGTREE
 *    - t type, i.e. point updates and range queries, add.
 *    - Compress range.
 *    - Add from left to right and query from [1, mapping)
 *    - Basically a normal compressed inversion segtree...
 * 
 * 4. ALSO you gotta consider inversions where an unchanged element 
 *    inverts with a small insertion ahead of it.  Do the same as #2...
 */

inline char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T=(S=buf) + fread(buf, 1, 100000, stdin);
		if(S==T) return EOF;
	}
	return *S++;
}

inline void read(int& x) {
	static char c; x = 0; int sgn = 1;
	for(c=get();c <'0' || c > '9';c=get()) if(c == '-') sgn = -1;
	for(;c>='0' && c <='9';c=get()) x = x*10+c-'0';
	x *= sgn;
}

struct segtree{
	vector<int> t;
	int h, n;
	segtree(int sz) {
		h = sizeof(int)*8 - __builtin_clz(sz-1);
		n = 1 << h;
		t = vector<int>(n<<1, 0);
	}
	void add(int pos, int v) {
		t[pos+n] += v;
		for(pos=(pos+n)/2;pos>0;pos/=2) {t[pos] = t[pos*2]+t[pos*2+1]; }
	}
	int query(int l, int r) {
		int amt = 0;
		for(l+=n,r+=n;l<r;l/=2,r/=2) {
			if(l%2) amt += t[l++];
			if(r%2) amt += t[--r];
		}
		return amt;
	}
};

inline void removeDuplicate(map<int, int>& m, int v) {
	if(m[v] == v)
		m.erase(v);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, a, b, va, vb;
	read(N);

	// simulate...
	map<int, int> posToNum;
	for(int i=0;i<N;++i) {
		read(a); read(b);
		va = (posToNum.count(a) ? posToNum[a] : a );
		vb = (posToNum.count(b) ? posToNum[b] : b );
		posToNum[b] = va;
		posToNum[a] = vb;
	}

	vector<int> pos;
	map<int, int> compress = posToNum;
	int cnt = 0;
	for(auto& pp : posToNum) {
		//cerr << "    AT " << pp.first << " WE HAVE " << pp.second << nl;
		pos.push_back(pp.first);
		compress[pp.first] = cnt++;
	}
	sort(pos.begin(), pos.end());
	segtree st(cnt);

	ll total = 0;
	int tt = 0;

	for(auto it = posToNum.rbegin(); it != posToNum.rend(); ++it) {
		const int &tpos = it->first;
		int &tval = it->second;
		tt = 0;
		if(tval > tpos) {
			tt += tval-tpos;
			//cerr << ".. " << tval-tpos << nl;
			tt -= upper_bound(pos.begin(), pos.end(), tval-1) - lower_bound(pos.begin(), pos.end(), tpos+1) + 1;
			//cerr << ".. " << tt << nl;
		} else {
			//cerr << ".. " << tpos-tval << nl;
			tt += tpos-tval;
			tt -= upper_bound(pos.begin(), pos.end(), tpos-1) - lower_bound(pos.begin(), pos.end(), tval+1) +1;
			//cerr << ".. " << tt << nl;
		}
		tt += st.query(0, compress[tval]);
		//cerr << "  :: val " << tval << " at " << tpos << ": " << tt << " " << "QUERY " << st.query(0, compress[tval]) << nl;
		total += tt;
		st.add(compress[tval], 1);
	}

	//cerr << st.t[1] << nl;

	cout << total << nl;
	
	return 0;
}