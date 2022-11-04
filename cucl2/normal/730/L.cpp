#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int jt = 1000000007, maxn = 1 << 19;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = (ll)a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return (ll)a * b % jt; }

struct NumberGetter {
	int val[maxn], mii[maxn];
	void inline init(char s[], int n) {
		val[0] = 0; mii[0] = 1;
		cont(i, n) {
			val[i] = Add(Mul(val[i - 1], 10), isdigit(s[i]) ? s[i] - '0' : 0);
			mii[i] = Mul(mii[i - 1], 10);
		}
	}
	int inline query(int l, int r) {
		return Sub(val[r], Mul(val[l - 1], mii[r - l + 1]));
	}
} Ng;

struct Segtree {
	vector<int> dt;
	int N;
	void init(vector<int> s) {
		N = 1;
		while (N <= SZ(s)) N <<= 1;
		dt.resize(N << 1);
		loop(i, SZ(s)) dt[i + N] = s[i];
		range(i, N - 1, 0, -1) dt[i] = Mul(dt[i << 1], dt[i << 1 | 1]);
	}
	int query(int l, int r) {
		int res = 1;
		for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) mul(res, dt[l++]);
			if (r & 1) mul(res, dt[--r]);
		}
		return res;
	}
};

struct Multiply {
	int l, r;
	vector<int> brs, bgs;
	vector<int> pre, suf;
	Segtree seg;
	int getpre(int);
	int getsuf(int);
	int getval(int, int);
} Ms[maxn];

struct Bracket {
	int l, r;
	bool single;
	vector<int> mls, bgs;
	vector<int> pre;
	int getpre(int);
	int getsuf(int);
	int getval(int, int);
	Bracket(int l = 0, int r = 0, int single = 0): l(l), r(r), single(single) {}
} Bs[maxn];

int inline Bracket::getpre(int len) {
	if (len < 0) return 1;
	if (single) return Ng.query(l, l + len - 1);
	if (len == r - l + 1) return pre.back();
	return 1;
}

int inline Bracket::getsuf(int len) {
	if (len < 0) return 1;
	if (single) return Ng.query(r - len + 1, r);
	if (len == r - l + 1) return pre.back();
	return 1;
}

int inline Multiply::getpre(int len) {
	if (len < 0) return 0;
	int id = upper_bound(all(bgs), l + len - 1) - bgs.begin() - 1;
	if (Bs[brs[id]].r == l + len - 1) return pre[id + 1];
	return Mul(pre[id], Bs[brs[id]].getpre(l + len - 1 - Bs[brs[id]].l + 1));
}

int inline Multiply::getsuf(int len) {
	if (len < 0) return 0;
	int id = upper_bound(all(bgs), r - len + 1) - bgs.begin() - 1;
	if (Bs[brs[id]].l == r - len + 1) return suf[id];
	return Mul(suf[id + 1], Bs[brs[id]].getsuf(Bs[brs[id]].r - (r - len + 1) + 1));
}

int inline Bracket::getval(int l, int r) {
	if (single) return Ng.query(l, r);
	if (l < bgs[0]) ++l;
	if (r == this->r) --r;
	int id1 = lower_bound(all(bgs), l) - bgs.begin();
	int id2 = upper_bound(all(bgs), r) - bgs.begin() - 1;
	if (id1 > id2) return Ms[mls[id2]].getval(l, r);
	return Add(Ms[mls[id1]].l == l ? 0 : Ms[mls[id1 - 1]].getsuf(Ms[mls[id1 - 1]].r - l + 1), Add(Sub(pre[id2], pre[id1]), id2 < SZ(mls) ? Ms[mls[id2]].getpre(r - Ms[mls[id2]].l + 1) : 0));
}

int inline Multiply::getval(int l, int r) {
	int id1 = lower_bound(all(bgs), l) - bgs.begin();
	int id2 = upper_bound(all(bgs), r) - bgs.begin() - 1;
	if (id1 > id2) return Bs[brs[id2]].getval(l, r);
	return Mul(Bs[brs[id1]].l == l ? 1 : Bs[brs[id1 - 1]].getsuf(Bs[brs[id1 - 1]].r - l + 1), Mul(seg.query(id1, id2 - 1), id2 < SZ(brs) ? Bs[brs[id2]].getpre(r - Bs[brs[id2]].l + 1) : 1));
}

struct Segtree3 {
	pair<int, int> dt[maxn << 1];
	void init() {
		loop(i, maxn << 1) dt[i].first = Inf;
	}
	void set(int a, pair<int, int> x) {
		a += maxn; dt[a] = x;
		while (a >>= 1) dt[a] = min(dt[a << 1], dt[a << 1 | 1]);
	}
	pair<int, int> query(int l, int r) {
		pair<int, int> res(Inf, 0);
		for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = min(res, dt[l++]);
			if (r & 1) res = min(res, dt[--r]);
		}
		return res;
	}
} sgg;

int N, Q;
char s[maxn];
int mcs, bcs;

int parseBracket(int&, int);

int parseMulti(int &ptr, int dep, int uid) {
	int id = ++mcs;
	Ms[id].l = ptr;
	Ms[id].pre.pub(1);
	vector<int> val;
	while (1) {
		Ms[id].bgs.pub(ptr);
		sgg.set(ptr, mak(dep, uid));
		int nid = parseBracket(ptr, dep + 1);
		Ms[id].brs.pub(nid);
		Ms[id].pre.pub(Mul(Ms[id].pre.back(), Bs[nid].pre.back()));
		val.pub(Bs[nid].pre.back());
		if (s[ptr] != '*') break;
		sgg.set(ptr, mak(dep, uid));
		++ptr;
	}
	Ms[id].suf.resize(SZ(Ms[id].pre));
	Ms[id].suf.back() = 1;
	range(i, SZ(Ms[id].brs) - 1, 0, -1) Ms[id].suf[i] = Mul(Ms[id].suf[i + 1], Bs[Ms[id].brs[i]].pre.back());
	Ms[id].seg.init(val);
	Ms[id].r = ptr - 1;
	return id;
}

int parseBracket(int &ptr, int dep) {
	if (s[ptr] != '(') {
		Bs[++bcs].single = 1;
		Bs[bcs].l = ptr;
		while (isdigit(s[ptr])) sgg.set(ptr, mak(dep, bcs)), ++ptr;
		Bs[bcs].r = ptr - 1;
		Bs[bcs].pre.pub(Ng.query(Bs[bcs].l, Bs[bcs].r));
		return bcs;
	}
	int id = ++bcs;
	Bs[id].l = ptr;
	++ptr;
	Bs[id].pre.pub(0);
	while (1) {
		Bs[id].bgs.pub(ptr);
		int nid = parseMulti(ptr, dep, id);
		Bs[id].mls.pub(nid);
		Bs[id].pre.pub(Add(Bs[id].pre.back(), Ms[nid].pre.back()));
		if (s[ptr] == ')') break;
		sgg.set(ptr, mak(dep, id));
		++ptr;
	}
	Bs[id].r = ptr++;
	return id;
}

struct Segtree2 {
	pair<int, int> dt[maxn << 1];
	pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
		return mak(a.first + b.first, min(a.second, a.first + b.second));
	}
	void set(int a, pair<int, int> x) {
		a += maxn; dt[a] = x;
		while (a >>= 1) dt[a] = merge(dt[a << 1], dt[a << 1 | 1]);
	}
	pair<int, int> query(int l, int r) {
		pair<int, int> lres(0, 0), rres(0, 0);
		for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lres = merge(lres, dt[l++]);
			if (r & 1) rres = merge(dt[--r], rres);
		}
		return merge(lres, rres);
	}
} seg;

int rt;

int main() {
	scanf("%s", s + 1); N = strlen(s + 1) + 2;
	scanf("%d", &Q);
	s[0] = '('; s[N - 1] = ')';
	Ng.init(s, N - 2);
	int ptr = 0;
	sgg.init();
	rt = parseBracket(ptr, 0);
	cont(i, N) {
		if (s[i] == '(') seg.set(i, mak(1, 0));
		if (s[i] == ')') seg.set(i, mak(-1, -1));
	}
	int tms = 0;
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (s[l] == '+' || s[l] == '*') { puts("-1"); continue; }
		if (s[r] == '+' || s[r] == '*') { puts("-1"); continue; }
		auto bbr = seg.query(l, r);
		if (bbr.second < 0 || bbr.first > 0) { puts("-1"); continue; }
		int khid = sgg.query(l, r).second;
		tms -= clock();
		printf("%d\n", Bs[khid].getval(l, r));
		tms += clock();
	}
	return 0;
}
/*

20 8
(1+(2+3)*4+5*6)+78*9
2 8
10 12
2 12
4 14
17 18
18 20
15 20
1 2

*/