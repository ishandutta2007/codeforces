#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * 220E Little Elephant and Inversions
 * 
 * Sequence a, how many pairs l, r are there such that the sequence a1a2..alar...an has at most k inversions?
 *
 * SEGTREE answer:
 * 1. segtrees (or BITs) which have range queries, point updates
 * 2. Two segtrees, one for left and right section
 * 2.1 Count total inversions
 * 3. L & R sections ignore the middle section [l, r].
 * 4. L segtree stores values to the left, R segtree stores values to tbe right.
 * 5. Two pointers, to l and r,  Move r forward until reaching sufficiently low inversions
 * 6. Keep current # inversions as X
 * 7. Update to move right forward (say, move pt m into middle:
 *   a. X += left.query(am+1, inf)
 *   b. X += right.query(1, am-1)
 *   c. right.remove(am);
 * 8 updates to move left foward (say, move pt m into left)
 *  a. X -= left.query(am+1, inf)
 *  b. X -= right.query(1, am)
 *  c. left.add(am);
 */

struct segtree{
	vector<int> t;
	int h, n;
	segtree() {}
	segtree(int sz) {
		h = sizeof(int)*8-__builtin_clz(sz);
		n = 1<<h;
		t = vector<int>(n<<1, 0);
	}
	void add(int i, int v) {
		for(i+=n;i>0;i>>=1) t[i] += v;
	}
	int query(int l, int r) {
		int sm = 0;
		for(l+=n, r+=n; l < r; l>>=1, r>>=1) {
			if(l%2) sm += t[l++];
			if(r%2) sm += t[--r];
		}
		return sm;
	}
};

vector<int> a, b;
int N;
ll k;
ll invtot;
segtree lseg, rseg, iseg;

void setup() {
	cin >> N >> k;
	a = vector<int>(N), b = vector<int>(N);
	lseg = segtree(N), rseg=segtree(N), iseg=segtree(N);
	
	map<int, int> mp;
	for(int i=0;i<N;++i) {
		cin >> a[i];
		mp[a[i]] = 0;
	}
	int cnt = 0;
	for(auto & ii : mp) {
		ii.second = cnt;
		++cnt;
	}
	for(int i=0;i<N;++i) {
		b[i] = mp[a[i]];
	}

	invtot = 0;
	for(int i=0;i<N;++i) {
		invtot += iseg.query(b[i]+1, N);
		iseg.add(b[i], 1);
		rseg.add(b[i], 1);
	}
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	setup();
	if(invtot <= k) {
		ll ans = (ll) N*(N-1)/2;
		cout << ans << endl;
		return 0;
	}

	ll tot = 0;
	ll X = 0; // removals
	lseg.add(b[0], 1);
	rseg.add(b[0], -1);
	int lp = 1, rp = 1; // middle includes [lp, rp)
	for(;rp < N;++lp) {
		for(;rp < N && invtot - X > k;++rp) {
			//cerr << "rp " << rp << " to " << rp+1 << ": ";
			X+=lseg.query(b[rp]+1, N);
			//cerr << "+" << lseg.query(b[rp]+1, N) << " ";
			X+=rseg.query(0, b[rp]);
			//cerr << "+" << rseg.query(0, b[rp]) << endl;
			rseg.add(b[rp], -1);
		}
		//cerr << lp << " " << rp << ": X = " << X << endl;
		tot += N-rp;
		X -= lseg.query(b[lp]+1, N);
		X -= rseg.query(0, b[lp]);
		//cerr << "!! +" << N-rp << endl;
		lseg.add(b[lp], 1);
	}
	
	cout << tot << endl;

	return 0;
}