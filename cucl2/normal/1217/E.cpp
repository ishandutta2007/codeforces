/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

const int qwq = 1 << 18;
int N, M;
int a[qwq];

struct State {
	ll mn[9][2];
	State() {
		loop(i, 9) mn[i][0] = mn[i][1] = INF;
	}
	State(int x) {
		loop(i, 9) mn[i][1] = INF;
		int nx = x;
		loop(i, 9) {
			if(nx % 10) mn[i][0] = x;
			else mn[i][0] = INF;
			nx /= 10;
		}
	}
	State operator+(const State &st) const {
		State res;
		loop(i, 9) {
			res.mn[i][0] = min(mn[i][0], st.mn[i][0]);
			res.mn[i][1] = min(mn[i][1], st.mn[i][1]);
			if(mn[i][0] == res.mn[i][0]) {
				res.mn[i][1] = min(st.mn[i][0], res.mn[i][1]);
			} else {
				res.mn[i][1] = min(mn[i][0], res.mn[i][1]);
			}
		}
		return res;
	}
	ll inline get() {
		ll res = INF;
		loop(i, 9) res = min(res, mn[i][0] + mn[i][1]);
		return res;
	}
};

struct Segtree {
	State dt[qwq << 1];
	void inline add(int a, int x) {
		a += qwq; dt[a] = State(x);
		while(a >>= 1) dt[a] = dt[a << 1] + dt[a << 1 | 1];
	}
	State inline query(int l, int r) {
		State res;
		for(l += qwq, r += qwq + 1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) res = res + dt[l++];
			if(r & 1) res = res + dt[--r];
		}
		return res;
	}
} seg;

int main() {
	scanf("%d%d", &N, &M);
	cont(i, N) scanf("%d", a + i), seg.add(i, a[i]);
	while(M--) {
		int mode; scanf("%d", &mode);
		if(mode == 1) {
			int i, x; scanf("%d%d", &i, &x);
			seg.add(i, x);
		} else {
			int l, r; scanf("%d%d", &l, &r);
			ll res = seg.query(l, r).get();
			if(res == INF) puts("-1");
			else printf("%d\n", res);
		}
	}
	return 0;
}

/**
 * 
 *  
 *   Inf
 *    zkw 
 */