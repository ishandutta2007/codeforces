#include <stdio.h>
#include <queue>
#define int long long 
int n, m, ans = 0x3f3f3f3f3f3f3f3f, p[3050], c[3050], cnt[3050];
std::priority_queue<int, std::vector<int>, std::greater<int> > q[3050], Q;
void solve(int x) {
	for (int i = 1; i <= m; i++) {
		while (q[i].size()) q[i].pop();
		cnt[i] = 0;
	}
	for (int i = 1; i <= n; i++) q[p[i]].push(c[i]), cnt[p[i]]++;
	int p = 0;
	for (int i = 2; i <= m; i++) {
		while (q[i].size() > x) p += q[i].top(), q[i].pop(), cnt[1]++;
	}
	if (cnt[1] < x + 1) {
		while (Q.size()) Q.pop();
		for (int i = 2; i <= m; i++) 
			while (q[i].size()) Q.push(q[i].top()), q[i].pop();
		int now = cnt[1];
		for (int i = 1; i <= x + 1 - cnt[1] && Q.size(); i++) 
			p += Q.top(), Q.pop(), now++;
		if (now < x + 1) return;
	}
	if (p < ans) ans = p;
}
signed main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &p[i], &c[i]);
	for (int i = 0; i <= n; i++) solve(i);
	printf("%I64d\n", ans);
	return 0;
}