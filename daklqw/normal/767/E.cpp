#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;
int n, m;
int C[MAXN], W[MAXN], V[MAXN];
int ax[MAXN], ay[MAXN];
typedef std::pair<int, int> pi;
std::priority_queue<pi> q;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		std::cin >> C[i], ax[i] = C[i] / 100, C[i] %= 100;
	for (int i = 1; i <= n; ++i)
		std::cin >> W[i], V[i] = (100 - C[i]) % 100 * W[i];
	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (C[i]) q.emplace(-V[i], i);
		if ((m -= C[i]) < 0) {
			int id = q.top().second;
			ans -= q.top().first; q.pop();
			ay[id] = 1, m += 100;
		}
	}
	std::cout << ans << std::endl;
	for (int i = 1; i <= n; ++i) {
		if (ay[i]) std::cout << ax[i] + 1<< ' ' << 0 << '\n';
		else std::cout << ax[i] << ' ' << C[i] << '\n';
	}
	return 0;
}