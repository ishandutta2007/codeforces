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

const int qwq = 1 << 19;
int N, Q;
int a[qwq];

struct Query {
	int r1, c1, r2, c2, id;
	Query(int r1, int c1, int r2, int c2, int id): r1(r1), c1(c1), r2(r2), c2(c2), id(id) {}
	bool inline operator<(const Query &a) const {
		return r2 < a.r2;
	}
};

struct Segtree {
	int dt[qwq << 1];
	void inline init() {memset(dt, Inf, sizeof(dt));}
	void inline add(int a, int x) {
		a += qwq; dt[a] = x;
		while(a >>= 1) dt[a] = min(dt[a << 1], dt[a << 1 | 1]);
	}
	int inline get(int l, int r) {
		int res = Inf;
		for(l += qwq, r += qwq + 1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) res = min(res, dt[l++]);
			if(r & 1) res = min(res, dt[--r]);
		}
		return res;
	}
} sl, sr, qj;

vector<Query> q1, q2;
int ans[qwq];
vector<int> dd;

int inline mianx(int a, int l, int r) {
	return max(min(a, r), l);
}

// Find the smallest pos in dd that the a value is larger than val
int inline Ubval(int val) {
	int l = -1, r = SZ(dd);
	while(r - l > 1) {
		int m = (l + r) >> 1;
		if(a[dd[m]] > val) r = m;
		else l = m;
	}
	return r;
}

// Find the smallest pos in dd that the position is not smaller than val
int inline Lbpos(int val) {
	return lower_bound(all(dd), val) - dd.begin();
}
int inline FLbpos(int val) {
	return upper_bound(all(dd), val, greater<int>()) - dd.begin();
}

void inline solve() {
	int qid = 0; sl.init(); sr.init(); qj.init();
	cont(i, N) qj.add(i, a[i]);
	cont(i, N) {
		while(SZ(dd) && a[dd.back()] >= a[i]) dd.pob();
		sl.add(SZ(dd), a[i] - 2 * i);
		sr.add(SZ(dd), -a[i] - 2 * i);
		int rp = SZ(dd);
		dd.pub(i);
		while(qid < SZ(q1) && q1[qid].r2 == i) {
			int id = q1[qid].id;
			int r1 = q1[qid].r1, c1 = q1[qid].c1;
			int r2 = q1[qid].r2, c2 = q1[qid].c2;
			int lp = Lbpos(r1);
			// Situation 1
			ans[id] = min(ans[id], r2 - r1 + c2 + 1);
			// Situation 2
			ans[id] = min(ans[id], r2 - r1 + abs(min(c1, a[dd[lp]]) - c2));
			// Situation 3
			int rpos = Ubval(c2), lpos = rpos - 1, pos;
			rpos = mianx(rpos, lp, rp); lpos = mianx(lpos, lp, rp);
			if(abs(a[dd[lpos]] - c2) < abs(a[dd[rpos]] - c2)) pos = lpos;
			else pos = rpos;
			ans[id] = min(ans[id], r2 - r1 + abs(a[dd[pos]] - c2) + 1);
			// Situation 4
			rpos = Ubval(c2), lpos = rpos - 1;
			rpos = mianx(rpos, 0, lp); lpos = mianx(lpos, -1, lp - 1);
			ans[id] = min(ans[id], r2 + r1 + sr.get(0, lpos) + c2 + 1);
			ans[id] = min(ans[id], r2 + r1 + sl.get(rpos, lp - 1) - c2 + 1);
			// Situation 6
			int sp = min(Ubval(min(c1, a[dd[lp]])), lp);
			rpos = Ubval(c2), lpos = rpos - 1;
			rpos = mianx(rpos, 0, sp); lpos = mianx(lpos, -1, sp - 1);
			ans[id] = min(ans[id], r2 + r1 + sr.get(0, lpos) + c2);
			ans[id] = min(ans[id], r2 + r1 + sl.get(rpos, sp - 1) - c2);
			++qid;
		}
	}
	dd.clear(); sl.init(); sr.init(); --qid;
	range(i, N, 1, -1) {
		while(SZ(dd) && a[dd.back()] >= a[i]) dd.pob();
		sl.add(SZ(dd), a[i] + 2 * i);
		sr.add(SZ(dd), -a[i] + 2 * i);
		int rp = SZ(dd);
		dd.pub(i);
		while(~qid && q1[qid].r2 == i) {
			int id = q1[qid].id;
			int r1 = q1[qid].r1, c1 = q1[qid].c1;
			int r2 = q1[qid].r2, c2 = q1[qid].c2;
			// Situation 5
			int rpos = Ubval(c2), lpos = rpos - 1;
			rpos = mianx(rpos, 0, rp + 1); lpos = mianx(lpos, -1, rp);
			ans[id] = min(ans[id], sr.get(0, lpos) + c2 - r2 - r1 + 1);
			ans[id] = min(ans[id], sl.get(rpos, rp) - c2 - r2 - r1 + 1);
			// Situation 7
			int sp = min(Ubval(min(qj.get(r1, r2), c1)), rp);
			rpos = Ubval(c2), lpos = rpos - 1;
			rpos = mianx(rpos, 0, sp); lpos = mianx(lpos, -1, sp - 1);
			ans[id] = min(ans[id], sr.get(0, lpos) + c2 - r2 - r1);
			ans[id] = min(ans[id], sl.get(rpos, sp - 1) - c2 - r2 - r1);
			--qid;
		}
	}
}

int main() {
	scanf("%d", &N);
	cont(i, N) scanf("%d", a + i);
	scanf("%d", &Q); memset(ans, Inf, sizeof(ans));
	cont(i, Q) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		if(r1 <= r2) q1.pub(Query(r1, c1, r2, c2, i));
		else q2.pub(Query(N - r1 + 1, c1, N - r2 + 1, c2, i));
	}
	sort(all(q1)); solve();
	reverse(a + 1, a + N + 1);
	sort(all(q2)); q2.swap(q1); solve();
	cont(i, Q) printf("%d\n", ans[i]);
	return 0;
}

/**
 * 
 *   4 
 *   1.  HOME 1 
 *   2.  min(c1, min[i in [r1,r2]] A[i]) 
 *   3.  END END  A 
 *   4.  END 
 *   5.  END 
 *   6. 
 *   7. 
 *   r1 <= r2  r1 > r2  r2 
 *    1 r2 - r1 + c2 + 1
 *    2 r2 - r1 + abs(minA - c2) minA  r1 
 *    3 r2 - r1 + abs(A - c2) + 1 A  c2  A 
 *    4 r2 + r1 - 2r0 + abs(A - c2) + 1 r0 
 *    5 4 
 *    6 4  2  r2 - r1 + abs(minA - c2) 
 *    7 6 
 *   reverse
 */