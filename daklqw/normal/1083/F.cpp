#include <bits/stdc++.h>

const int MAXN = 200010;
int A[MAXN], B[MAXN], C[MAXN], n, K, Q;
typedef std::vector<int> VI;
int c0, d0;
const int BLO = 512;
int pool[MAXN / BLO + 2][1 << 14], poolb;
struct blk {
	VI A; int tag;
	int * hav;
	int get(int x) { return A[x] ^ tag; }
	void init() {
		if (A.size() < BLO) hav = NULL;
		else hav = pool[poolb++];
	}
	void reduliu() { if (hav != NULL) for (auto t : A) --hav[t]; }
	void rebuild() { if (hav != NULL) for (auto t : A) ++hav[t]; }
	int qry(int v) {
		if (hav == NULL) {
			v ^= tag; int res = 0;
			for (auto t : A) res += v == t;
			return res;
		}
		return hav[v ^ tag];
	}
} ;
struct blo {
	int delta;
	int siz, havs;
	VI arr, L, R;
	int pos(int x) { return (x - delta) / K; }
	inline int bel(int x) { return x / BLO; }
	int get(int x) {
		return bs[bel(x)].get(x - L[x]);
	}
	std::vector<blk> bs;
	void init() {
		siz = arr.size();
		L.resize(siz);
		R.resize(siz);
		for (int i = 0; i < siz; ++i)
			L[i] = !i || bel(i) != bel(i - 1) ? i : L[i - 1];
		for (int i = siz - 1; ~i; --i)
			R[i] = i == siz - 1 || bel(i) != bel(i + 1) ? i : R[i + 1];
		for (int i = 0; i < siz; ++i) {
			if (bs.size() == bel(i)) bs.resize(bs.size() + 1);
			bs[bel(i)].A.push_back(arr[i]);
			bs[bel(i)].tag = 0;
		}
		for (auto & t : bs) t.init(), t.rebuild(), d0 += t.qry(0);
		if (havs) c0 += get(siz - 1) == 0;
	}
	void addsuc(int x, int v) {
		if (havs) c0 -= get(siz - 1) == 0;
		int bb = bel(x);
		for (int i = (int) bs.size() - 1; i >= bb; --i) d0 -= bs[i].qry(0);
		bs[bb].reduliu();
		while (x < siz && bel(x) == bb)
			bs[bb].A[x - L[x]] ^= v, ++x;
		bs[bb].rebuild();
		for (int i = (int) bs.size() - 1; i > bb; --i) bs[i].tag ^= v;
		for (int i = (int) bs.size() - 1; i >= bb; --i) d0 += bs[i].qry(0);
		if (havs) c0 += get(siz - 1) == 0;
	}
} bs[MAXN];

inline int globel(int x) {
	int at = x % K; if (at == 0) at = K;
	return at;
}
void mdf(int x, int y) {
	if (x > n) return ;
	int at = globel(x);
	bs[at].addsuc(bs[at].pos(x), y);
}
int qry() {
	if (c0 != K - 1) return -1;
	return n - d0;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K >> Q;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 1; i <= n; ++i) std::cin >> B[i];
	for (int i = 1; i <= n; ++i) C[i] = A[i] ^ B[i];
	for (int i = 1; i + K <= n; ++i) C[i + K] ^= C[i];
	for (int i = n; i; --i) C[i] ^= C[i - 1];
	for (int i = 1; i <= K; ++i) {
		bs[i].delta = i;
		for (int j = i; j <= n; j += K)
			bs[i].arr.push_back(C[j]);
	}
	for (int i = n - K + 2; i <= n; ++i)
		bs[globel(i)].havs = true;
	for (int i = 1; i <= K; ++i) bs[i].init();
	std::cout << qry() << '\n';
	while (Q --> 0) {
		static char buf[10];
		int x, y; std::cin >> buf >> x >> y;
		int * T = *buf == 'a' ? A : B;
		mdf(x, T[x] ^ y);
		mdf(x + 1, T[x] ^ y);
		T[x] = y;
		std::cout << qry() << '\n';
	}
	return 0;
}