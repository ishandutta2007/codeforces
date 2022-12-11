#include <bits/stdc++.h>

const int MAXN = 2e5 + 10;
const int LEFT = 0, RIGHT = 1;
typedef std::pair<int, int> pi;
pi li[MAXN];
int A[MAXN], at[MAXN], n, Q;
int go(int x, int L, int dire) {
	int l = 1, r = n, ans = x;
	(dire ? l : r) = x;
	while (l <= r) {
		int mid = l + r >> 1;
		if (std::abs(A[mid] - A[x]) <= L)
			ans = mid, dire ? (l = mid + 1) : (r = mid - 1);
		else dire ? (r = mid - 1) : (l = mid + 1);
	}
	return ans;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q;
	for (int i = 1; i <= n; ++i)
		std::cin >> A[i], li[i] = pi(A[i], i);
	std::sort(li + 1, li + 1 + n);
	for (int i = 1; i <= n; ++i) {
		A[i] = li[i].first;
		at[li[i].second] = i;
	}
	while (Q --> 0) {
		int lst = -1, u, L, dire = RIGHT;
		std::cin >> u >> L; u = at[u];
		while (true) {
			int to = go(u, L, dire);
			if (to == lst) {
				int d = std::abs(A[to] - A[u]);
				if (d == 0) break;
				int c = L / d;
				dire ^= c & 1;
				if (c & 1) std::swap(u, lst);
				L -= c * d;
			} else {
				dire ^= 1;
				L -= std::abs(A[to] - A[u]);
				lst = u, u = to;
			}
		}
		std::cout << li[u].second << '\n';
	}
	return 0;
}