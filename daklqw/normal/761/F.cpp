#include <bits/stdc++.h>

typedef long long LL;
const int MAXN = 1010;
const int MAXK = 300010;
char mat[MAXN][MAXN];
int n, m, K;
int hav[27][MAXN][MAXN];
struct rect {
	int x1, y1, x2, y2, c;
} ms[MAXK];
void add(int A[MAXN][MAXN], rect x, int v) {
	A[x.x1][x.y1] += v;
	A[x.x2][x.y1] -= v;
	A[x.x1][x.y2] -= v;
	A[x.x2][x.y2] += v;
}
LL nu[27][MAXN][MAXN];
LL qry(LL A[MAXN][MAXN], rect x) {
	LL res = 0;
	res += A[x.x1][x.y1];
	res -= A[x.x2][x.y1];
	res -= A[x.x1][x.y2];
	res += A[x.x2][x.y2];
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> K;
	for (int i = 1; i <= n; ++i) {
		std::cin >> mat[i] + 1;
		for (int j = 1; j <= m; ++j) mat[i][j] -= 'a';
	}
	hav[26][1][1] += K;
	static char buf[10];
	for (int i = 1; i <= K; ++i) {
		std::cin >> ms[i].x1 >> ms[i].y1 >> ms[i].x2 >> ms[i].y2 >> buf;
		++ms[i].x2, ++ms[i].y2;
		ms[i].c = *buf - 'a';
		add(hav[26], ms[i], -1);
		add(hav[ms[i].c], ms[i], 1);
	}
	for (int i = 0; i <= 26; ++i) {
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= m; ++k)
				hav[i][j][k] += hav[i][j - 1][k];
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= m; ++k)
				hav[i][j][k] += hav[i][j][k - 1];
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			for (int k = 0; k < 26; ++k)
				nu[26][i][j] += std::abs(k - mat[i][j]) * hav[k][i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			static int li[26];
			static int pre[26], suc[26];
			static int pc[26], sc[26];
			for (int k = 0; k < 26; ++k)
				li[k] = hav[k][i][j];
			li[mat[i][j]] += hav[26][i][j];
			for (int k = 0; k < 26; ++k) pre[k] = suc[k] = li[k] * k;
			for (int k = 0; k < 26; ++k) pc[k] = sc[k] = li[k];
			for (int k = 1; k < 26; ++k) pre[k] += pre[k - 1];
			for (int k = 1; k < 26; ++k) pc[k] += pc[k - 1];
			for (int k = 24; ~k; --k) suc[k] += suc[k + 1];
			for (int k = 24; ~k; --k) sc[k] += sc[k + 1];
			for (int k = 0; k < 26; ++k) {
				LL & ans = nu[k][i][j];
				if (k != 25)
					ans += suc[k + 1] - sc[k + 1] * k;
				ans += pc[k] * k - pre[k];
			}
		}
	for (int k = 0; k <= 26; ++k) {
		for (int i = n; i; --i)
			for (int j = m; j; --j)
				nu[k][i][j] += nu[k][i + 1][j];
		for (int i = n; i; --i)
			for (int j = m; j; --j)
				nu[k][i][j] += nu[k][i][j + 1];
	}
	LL ans = std::numeric_limits<LL>::max();
	for (int i = 1; i <= K; ++i) {
		LL t = qry(nu[ms[i].c], ms[i]) - qry(nu[26], ms[i]);
		ans = std::min(ans, t);
	}
	std::cout << ans + nu[26][1][1] << std::endl;
	return 0;
}