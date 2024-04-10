#include <bits/stdc++.h>

const int MAXN = 6e5 + 10;

typedef std::pair<int, int> pi;
int A[6], bak;
pi li[MAXN];
int hav[100010], all;
void add(int x) {
	if ((++hav[x]) == 1) ++all;
}
void dec(int x) {
	if ((--hav[x]) == 0) --all;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	for (int i = 0; i < 6; ++i)
		std::cin >> A[i];
	int n ; std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		int t;
		std::cin >> t;
		for (int j = 0; j < 6; ++j)
			li[bak++] = pi(t - A[j], i);
	}
	std::sort(li, li + bak);
	int cur = 0;
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < bak; ++i) {
		while (cur < bak && all < n)
			add(li[cur++].second);
		assert(i < cur);
		if (all == n) {
			ans = std::min(ans, li[cur - 1].first - li[i].first);
		}
		dec(li[i].second);
	}
	std::cout << ans << std::endl;
	return 0;
}