#include <bits/stdc++.h>

const int MAXN = 500010;
typedef long long LL;
typedef std::vector<int> VI;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
int n, m;
LL C[MAXN];
int hav[MAXN];
VI out[MAXN], in[MAXN];
const int mod1 = 1004535809;
bool ispri(int x) {
	for (int i = 2; i * i <= x; ++i) if (x % i == 0)
		return false;
	return true;
}
std::mt19937 rd(time(0));
int fnd() {
	int t = rd() % 1000 + 1000000000;
	while (!ispri(t)) ++t;
	return t;
}
const int mod2 = fnd();
const int a1 = rd() % 1000 + 10, a2 = rd() % 1000 + 10;
std::map<LL, LL> tl;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T;
	for (int TT = 1; TT <= T; ++TT) {
		std::cin >> n >> m;
		for (int i = 1; i <= n; ++i) std::cin >> C[i];
		memset(hav, 0, n + 1 << 2);
		LL G = 0;
		for (int i = 1, u, v; i <= m; ++i) {
			std::cin >> u >> v;
			out[u].push_back(v); hav[v] = true;
			in[v].push_back(u);
		}
		for (int i = 1; i <= n; ++i) if (hav[i]) {
			std::sort(in[i].begin(), in[i].end());
			int v1 = 0, v2 = 0;
			for (auto t : in[i]) {
				v1 = ((LL) v1 * a1 + t + 517) % mod1;
				v2 = ((LL) v2 * a2 + t + 233) % mod2;
			}
			tl[(LL) v1 * mod2 + v2] += C[i];
			// std::cout << "NOW " << i << ' ' << (LL) v1 * mod2 + v2 << '\n';
		}
		for (auto t : tl) G = gcd(G, t.second);
		tl.clear();
		LL sm = 0;
		for (int i = 1; i <= n; ++i) {
			LL t = 0; for (auto j : out[i]) t += C[j];
			G = gcd(G, t);
		}
		for (int i = 1; i <= n; ++i) if (hav[i]) sm += C[i];
		G = gcd(G, sm);
		std::cout << G << '\n';
		for (int i = 1; i <= n; ++i) out[i].clear(), in[i].clear();;
	}
	return 0;
}