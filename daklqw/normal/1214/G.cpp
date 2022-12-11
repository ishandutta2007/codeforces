#include <bits/stdc++.h>

const int MAXN = 2000;
typedef long long LL;
int n, m, Q;
const int dig = 2048 / 64;
struct bitset {
	LL A[dig]; int ppc;
	bool contains(const bitset & b) const {
		for (int i = 0; i != dig; ++i)
			if ((A[i] & b.A[i]) != b.A[i])
				return false;
		return true;
	}
	void rev(int l, int r) {
		for (int i = (l >> 6); i <= (r >> 6); ++i)
			ppc -= __builtin_popcountll(A[i]);
		A[l >> 6] ^= ((1ll << (l & 63)) - 1) ^ -1;
		A[r >> 6] ^= (r & 63) == 63 ? -1 : (1ll << ((r & 63) + 1)) - 1;
		(l >> 6) == (r >> 6) ? (A[l >> 6] ^= -1) : 0;
		for (int i = (l >> 6) + 1; i < (r >> 6); ++i) A[i] ^= -1;
		for (int i = (l >> 6); i <= (r >> 6); ++i)
			ppc += __builtin_popcountll(A[i]);
	}
	int ctzofandinvb(const bitset & b) {
		for (int i = 0; i != dig; ++i) {
			LL now = A[i] & ~b.A[i];
			if (now) return i << 6 | __builtin_ctzll(now);
		}
		return -1;
	}
} mat[MAXN];
typedef std::pair<int, int> PII;
std::set<PII> S, diff;
int getsuc(std::set<PII>::iterator it) {
	return ++it != S.end() ? it -> second : -1;
}
int getpre(std::set<PII>::iterator it) {
	return it != S.begin() ? (--it) -> second : -1;
}
void ins(int a, int b) {
	if (a == -1 || b == -1) return ;
	if (!mat[b].contains(mat[a]))
		diff.insert(PII(a, b));
}
void del(int a, int b) {
	if (a == -1 || b == -1) return ;
	diff.erase(PII(a, b));
}
bitset t;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> Q;
	for (int i = 0; i < n; ++i) S.insert(PII(0, i));
	int t1, t2, t3;
	while (Q --> 0) {
		std::cin >> t1 >> t2 >> t3; --t1, --t2, --t3;
		auto t = S.find(PII(mat[t1].ppc, t1));
		int suc = getsuc(t), pre = getpre(t);
		del(pre, t1); del(t1, suc);
		S.erase(t); mat[t1].rev(t2, t3);
		auto at = S.insert(PII(mat[t1].ppc, t1)).first;
		int ts = getsuc(at), tp = getpre(at); 
		del(tp, ts);
		ins(tp, t1); ins(t1, ts);
		if (ts != suc && tp != pre) ins(pre, suc);
		if (diff.empty()) std::cout << "-1\n";
		else {
			PII t = *diff.begin();
			int x1 = t.first, x2 = t.second;
			int y1 = mat[x1].ctzofandinvb(mat[x2]);
			int y2 = mat[x2].ctzofandinvb(mat[x1]);
			if (x1 > x2) std::swap(x1, x2);
			if (y1 > y2) std::swap(y1, y2);
			++x1, ++x2, ++y1, ++y2;
			std::cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
		}
	}
	return 0;
}