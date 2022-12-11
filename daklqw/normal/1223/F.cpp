#include <bits/stdc++.h>

const int MAXN = 300010;
typedef long long LL;
std::mt19937_64 rd(time(0));
LL f[MAXN], g[MAXN];
int n, A[MAXN];
LL sm;
int st[MAXN], top;
void push(int x) {
	if (top && x == st[top]) {
		sm -= f[st[top]] ^ g[top];
		--top;
	} else {
		st[++top] = x;
		sm += f[x] ^ g[top];
	}
}
LL ans;
void solve(int l, int r) {
	if (l >= r) return ;
	int mid = l + r >> 1;
	solve(l, mid), solve(mid + 1, r);
	static LL li[MAXN]; int bak = 0;
	sm = top = 0;
	for (int i = mid; i >= l; --i)
		push(A[i]), li[++bak] = sm;
	std::sort(li + 1, li + 1 + bak);
	sm = top = 0;
	for (int i = mid + 1; i <= r; ++i) {
		push(A[i]);
		ans += std::upper_bound(li + 1, li + 1 + bak, sm) -
			   std::lower_bound(li + 1, li + 1 + bak, sm);
	}
}
int main() {
	for (int i = 0; i != MAXN; ++i)
		f[i] = rd(), g[i] = rd();
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T;
	while (T --> 0) {
		std::cin >> n;
		for (int i = 1; i <= n; ++i) std::cin >> A[i];
		ans = 0, solve(1, n);
		std::cout << ans << '\n';
	}
	return 0;
}