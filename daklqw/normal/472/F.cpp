#include <bits/stdc++.h>

const int MAXN = 1e4 + 10;
void bye() {
	std::cout << -1 << std::endl;
	exit(0);
}
int obs[30];
int bse[30], src[30];
bool ins(int x, int at) {
	int s = 0;
	for (int i = 29; ~i; --i)
		if (x >> i & 1) {
			if (bse[i]) {
				x ^= bse[i];
				s ^= src[i];
			} else {
				bse[i] = x;
				src[i] = s ^ (1 << i);
				obs[i] = at;
				return true;
			}
		}
	return false;
}
int get(int x) {
	int res = 0;
	for (int i = 29; ~i; --i)
		if (x >> i & 1)
			res ^= src[i], x ^= bse[i];
	if (x) bye();
	return res;
}
int n;
int A[MAXN], B[MAXN];
const int MAXM = 1e6 + 10;
int xs[MAXM], ys[MAXM], bak;
int isb[MAXN];
int OA[MAXN], OB[MAXN];
void addq(int x, int y) {
	if (!x || !y) return ;
	OA[x] ^= OA[y];
	xs[++bak] = x, ys[bak] = y;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> A[i], isb[i] = ins(A[i], i);
	for (int i = 1; i <= n; ++i)
		OA[i] = A[i], A[i] = get(A[i]);
	for (int i = 1; i <= n; ++i)
		std::cin >> B[i], OB[i] = B[i], B[i] = get(B[i]);
	for (int i = 1; i <= n; ++i) if (!isb[i]) {
		for (int j = 0; j != 30; ++j)
			if ((A[i] ^ B[i]) >> j & 1)
				addq(i, obs[j]);
	}
	typedef std::pair<int, int> pi;
	std::vector<pi> opts;
	static int mat[30];
	for (int i = 0; i < 30; ++i)
		mat[i] = B[obs[i]];
	for (int i = 0; i < 30; ++i) {
		int t = -1;
		for (int j = i; j < 30; ++j)
			if (mat[j] >> i & 1) {
				t = j; break;
			}
		if (t == -1) continue;
		if (t != i) {
			std::swap(mat[i], mat[t]);
			opts.emplace_back(i, t);
			opts.emplace_back(t, i);
			opts.emplace_back(i, t);
		}
		for (int j = 0; j < 30; ++j)
			if (j != i && (mat[j] >> i & 1)) {
				mat[j] ^= mat[i];
				opts.emplace_back(j, i);
			}
	}
	for (int i = 29; ~i; --i)
		if (!(mat[i] >> i & 1)) {
			opts.emplace_back(i, i);
			for (int j = 0; j < 30; ++j)
				if (mat[j] >> i & 1)
					opts.emplace_back(j, i);
		}
	std::reverse(opts.begin(), opts.end());
	for (auto t : opts)
		addq(obs[t.first], obs[t.second]);
	std::cout << bak << '\n';
	for (int i = 1; i <= bak; ++i)
		std::cout << xs[i] << ' ' << ys[i] << '\n';
//	std::cout << "FINAL: \n";
//	for (int i = 1; i <= n; ++i)
//		std::cout << OA[i] << ' ';
//	std::cout << '\n';
//	for (int i = 1; i <= n; ++i)
//		std::cout << OB[i] << ' ';
//	std::cout << '\n';
	for (int i = 1; i <= n; ++i) assert(OA[i] == OB[i]);
	return 0;
}