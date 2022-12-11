#include <bits/stdc++.h>

const int MAXN = 200010;
const int INF = 0x3f3f3f3f;
void gmi(int & x, int y) { x > y ? x = y : 0; }
struct SA {
	int rk[MAXN], SA[MAXN];
	bool cmpeq(int * A, int l, int r, int L) {
		return A[l] == A[r] && A[l + L] == A[r + L];
	}
	void build(char * buf, int n) {
		static int buc[524289];
		int SZ = 256;
		for (int i = 1; i <= n; ++i) ++buc[buf[i]];
		for (int i = 1; i <= SZ; ++i) buc[i] += buc[i - 1];
		for (int i = n; i; --i) SA[buc[buf[i]]--] = i;
		memset(buc, 0, SZ + 1 << 2);
		for (int i = 1; i <= n; ++i) rk[i] = buf[i];
		for (int L = 1; L < n; L <<= 1) {
			static int A[MAXN], ork[MAXN]; int C = 0;
			for (int i = n - L + 1; i <= n; ++i) A[++C] = i;
			for (int i = 1; i <= n; ++i) if (SA[i] > L) A[++C] = SA[i] - L;
			for (int i = 1; i <= n; ++i) ++buc[rk[i]];
			for (int i = 1; i <= SZ; ++i) buc[i] += buc[i - 1];
			for (int i = n; i; --i) SA[buc[rk[A[i]]]--] = A[i];
			memset(buc, 0, SZ + 1 << 2);
			memcpy(ork, rk, n + 1 << 2);
			rk[SA[1]] = SZ = 1;
			for (int i = 2; i <= n; ++i)
				rk[SA[i]] = cmpeq(ork, SA[i], SA[i - 1], L) ? SZ : ++SZ;
		}
	}
	int hei[MAXN], ST[18][MAXN];
	void buildST(char * buf, int n) {
		int H = 0;
		for (int i = 1; i <= n; ++i) {
			H = std::max(0, H - 1);
			while (buf[i + H] == buf[SA[rk[i] - 1] + H]) ++H;
			ST[0][rk[i]] = hei[rk[i]] = H;
		}
		for (int i = 1; i != 18; ++i)
			for (int j = 1; j + (1 << i) - 1 <= n; ++j)
				ST[i][j] = std::min(ST[i - 1][j], ST[i - 1][j + (1 << i - 1)]);
	}
	int lcp(int l, int r) {
		if (l == r) return INF;
		if ((l = rk[l]) > (r = rk[r])) std::swap(l, r);
		const int L = std::__lg(r - l++);
		return std::min(ST[L][l], ST[L][r - (1 << L) + 1]);
	}
} pr, qr;
std::vector<int> fac[MAXN];
int n, Q;
bool solve1(int l, int r) {
	const int L = r - l + 1;
	const auto & V = fac[L];
	const int sz = V.size();
	for (int i = 0; i < sz; ++i) {
		int term = L / V[i];
		if (pr.lcp(l, l + term) >= L - term)
			return true;
	}
	return false;
}
typedef std::function<int(int, int)> func;
struct RMQ {
	int ST[18][MAXN];
	RMQ() { memset(ST, 0x3f, sizeof ST); }
	void set(int l, int r, int v) {
		if (l > r) return ;
		const int L = std::__lg(r - l + 1);
		gmi(ST[L][l], v);
		gmi(ST[L][r - (1 << L) + 1], v);
	}
	void init(func mdf, func gma) {
		for (int i = 17; i; --i)
			for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
				gmi(ST[i - 1][j], ST[i][j]);
				gmi(ST[i - 1][j + (1 << i - 1)], ST[i][j]);
			}
		for (int i = 1; i <= n; ++i) ST[0][i] = mdf(ST[0][i], i);
		for (int i = 1; i != 18; ++i)
			for (int j = 1; j + (1 << i) - 1 <= n; ++j)
				ST[i][j] = gma(ST[i - 1][j], ST[i - 1][j + (1 << i - 1)]);
	}
	int operator [] (int x) { return ST[0][x]; }
	int qry(int l, int r) {
		const int L = std::__lg(r - l + 1);
		return std::min(ST[L][l], ST[L][r - (1 << L) + 1]);
	}
} lma, rma;
int rev(int x) { return n - x + 1; }
void buildAA() {
	for (int L = 1; L <= n; ++L) {
		for (int l = L; l + L <= n; l += L) {
			int r = l + L;
			int A = qr.lcp(rev(r), rev(l));
			int B = r + 1 <= n ? pr.lcp(l + 1, r + 1) : 0;
			A = std::min(A, L), B = std::min(B, L);
			A = l - A + 1, B = r + B;
			lma.set(A, B - L * 2 + 1, L * 2);
			rma.set(A + L * 2 - 1, B, L * 2);
		}
	}
	lma.init([] (int x, int at) { return at + x - 1; },
			 [] (int x, int y) { return std::min(x, y); });
	rma.init([] (int x, int at) { return at - x + 1; },
			 [] (int x, int y) { return std::max(x, y); });
}
bool havaa(int l, int r) { return lma.qry(l, r) <= r; }
const int BLO = 256;
bool border(int l, int r) {
	const int L = r - l + 1;
	int up = std::min(BLO, L - 1);
	for (int i = 1; i <= up; ++i)
		if (pr.lcp(l, r - i + 1) >= i)
			return i * 2 <= L;
	if (up != BLO) return false;
	const int D = n / up + 1;
	int mi = INF, res = INF;
	const int * rk = pr.rk, * SA = pr.SA, * hei = pr.hei;
	int bd = std::max(1, rk[l] - D);
	for (int i = rk[l] - 1; i >= bd; --i) {
		gmi(mi, hei[i + 1]);
		if (l <= SA[i] && SA[i] <= r && r - SA[i] + 1 <= mi)
			gmi(res, r - SA[i] + 1);
	}
	mi = INF, bd = std::min(n, rk[l] + D);
	for (int i = rk[l] + 1; i <= bd; ++i) {
		gmi(mi, hei[i]);
		if (l <= SA[i] && SA[i] <= r && r - SA[i] + 1 <= mi)
			gmi(res, r - SA[i] + 1);
	}
	return res * 2 <= L;
}
bool solve2(int l, int r) {
	return lma[l] <= r || rma[r] >= l || border(l, r);
}
int pre[MAXN][26];
char buf[MAXN];
bool solve3(int l, int r) {
	int c = buf[l] - 'a';
	if (pre[r][c] - pre[l][c] >= 1) return true;
	c = buf[r] - 'a';
	if (pre[r][c] - pre[l - 1][c] >= 2) return true;
	return havaa(l, r);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> buf + 1 >> Q;
	pr.build(buf, n), pr.buildST(buf, n);
	std::reverse(buf + 1, buf + 1 + n);
	qr.build(buf, n), qr.buildST(buf, n);
	std::reverse(buf + 1, buf + 1 + n);
	buildAA();
	for (int i = 1; i <= n; ++i) {
		memcpy(pre[i], pre[i - 1], 104);
		++pre[i][buf[i] - 'a'];
	}
	for (int i = 2; i <= n; ++i) if (fac[i].empty())
		for (int j = i; j <= n; j += i)
			fac[j].push_back(i);
	while (Q --> 0) {
		int l, r; std::cin >> l >> r;
		bool can = false;
		for (int i = 0; i != 26; ++i)
			can |= pre[r][i] - pre[l - 1][i] > 1;
		if (!can) { std::cout << -1 << '\n'; continue; }
		if (solve1(l, r)) { std::cout << 1 << '\n'; continue; }
		if (solve2(l, r)) { std::cout << 2 << '\n'; continue; }
		if (solve3(l, r)) { std::cout << 3 << '\n'; continue; }
		std::cout << 4 << '\n';
	}
	return 0;
}