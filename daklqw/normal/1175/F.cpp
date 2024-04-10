#include <bits/stdc++.h>

const int MAXN = 300010;
int A[MAXN], n, L[MAXN];
int vis[MAXN], st[MAXN], top;
std::vector<int> hav[MAXN << 1];
int arr[MAXN], cnt, glo;
void _add(int x, int v) {
	arr[x] += v; if (glo >= x) cnt += v;
}
int gl2;
void add(int x, int v) {
	int at = st[x] + vis[st[x - 1]];
	if (v == 1) hav[at].push_back(st[x]);
	else hav[at].pop_back();
	if (gl2 >= at) _add(st[x], v);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	int cur = n;
	for (int i = n; i; --i) {
		while (cur && !vis[A[cur]]) vis[A[cur--]] = 1;
		vis[A[i]] = 0, L[i] = cur;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		while (top && st[top] <= A[i]) add(top--, -1);
		vis[A[i]] = i;
		cur = std::min(cur, top);
		st[++top] = A[i], add(top, 1);
		for (auto t : hav[++gl2]) _add(t, 1);
		while (glo < i - L[i]) cnt += arr[++glo];
		while (glo > i - L[i]) cnt -= arr[glo--];
		ans += cnt;
	}
	std::cout << ans << std::endl;
	return 0;
}