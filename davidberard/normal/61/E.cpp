#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

/**
 * 61E - Enemy is weak - SEGTREE BOOTCAMP
 *
 * 5s 256mb
 * - Weakness of army = # of tuples (i,j,k) where i<j<k and ai>aj>ak.
 * - values of a: 1<a[i]<1e9.  up to 1e6 army members
 * - Find army's weakness : i.e., how many tuples i,j,k exist with this property
 *
 * Approach: 1. a[i]-> b[i] where b[i] < 1e6.
 *           2. make 2 BITs or segtrees, left and right
 *           3. Query the value b[i] in the left, b[n-i-1] in the right BITs
 *              this is to check how many things we have to the right and left
 *              of this element
 *           4. Add, to the left BIT, range 1 to b[i]:
 *                Later queries in "left" will return +1 if they are smaller than this value.
 *              To right BIT add b[i] to n.
 *           5. At the end, treat soldier i as the middle soldier; we want larger
 *              ppl to the left, smaller ppl to the right, so just multiply the
 *              queries from part 3 together.
 */

inline char get() {
    static char buf[100000], *S = buf, *T = buf;
    if(S == T) {
        T = (S = buf) + fread(buf, 1, 100000, stdin);
        if(S == T) return EOF;
    }
    return *S++;
}

inline void read(int& x) {
    static char c; x=0; int sgn = 1;
    for(c=get();c < '0' || c > '9';c=get()) if(c == '-') sgn = -1;
    for(; c>='0' && c <='9';c=get()) x = x*10+c-'0';
    x*=sgn;
}

struct segtree{
	vector<int> d;
	vector<int*> addto;
	int h, n;
	segtree(int sz) {
		for(sz=sz-1,h=0;sz>0;sz/=2,++h);
		n = 1<<h;
		d = vector<int>(n<<1, 0);
	}
	int query(int v) {
		int ans = 0;
		for(v+=n;v>0;v>>=1) ans += d[v];
		return ans;
	}
	void add(int l, int r, int val) {
		for(l += n, r += n; l<r; l>>=1, r>>=1) {
			if(l%2) addto.push_back(&d[l++]);
			if(r%2) addto.push_back(&d[--r]);
		}
		while(!addto.empty()) {
			*(addto.back()) += val;
			addto.pop_back();
		}
	}

};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int N;
	read(N);
	vector<int> a(N);
	map<int, int> mp;
	for(int i=0;i<N;++i) {
		read(a[i]);
		mp[a[i]] = 0;
	}
	int cnt = 0;
	for( auto& mm : mp ) { // map values to 0 - n
		mm.second = cnt;
		++cnt;
	}
	segtree lseg(cnt), rseg(cnt);
	
	// how many choices we have to the left and right of this soldier
	vector<int> lcount(N), rcount(N);
	
	int c1, c2;
	for(int i=0;i<N;++i) {
		lcount[i] = lseg.query((c1 = mp[a[i]]));
		rcount[N-i-1] = rseg.query((c2 = mp[a[N-i-1]]));
		lseg.add(0, c1, 1);
		rseg.add(c2, cnt, 1);
	}

	ll ans = 0;
	for(int i=0;i<N;++i) {
		ans += (ll)rcount[i]*lcount[i];
	}

	cout << ans << endl;
	

	return 0;
}