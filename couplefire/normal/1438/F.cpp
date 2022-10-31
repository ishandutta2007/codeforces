#include <algorithm>
#include <stdio.h>
#include <random>
#include <chrono>
struct node { int i, v; } ns[300005];
int h, n;
std::mt19937 rnd;
int main() {
	rnd.seed(std::chrono::steady_clock::now().time_since_epoch().count());
	scanf("%d", &h);
	n = (1 << h) - 1;
	std::uniform_int_distribution<> dis(1, n);
	for (int i = 1; i <= n; ++i) ns[i].i = i, ns[i].v = 0;
	for (int i = 0; i < 420; ++i) {
		int u = dis(rnd), v = dis(rnd), w = dis(rnd);
		while (u == v || u == w || v == w) v = dis(rnd), w = dis(rnd);
		printf("? %d %d %d\n", u, v, w);
		fflush(stdout);
		scanf("%d", &u);
		++ns[u].v;
	}
	std::sort(ns + 1, ns + n + 1, [] (const node &a, const node &b) { return a.v > b.v; });
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (i == ns[1].i || i == ns[2].i) continue;
		printf("? %d %d %d\n", ns[1].i, ns[2].i, i);
		fflush(stdout);
		int x; scanf("%d", &x);
		if (i == x) ans = i;
	}
	printf("! %d", ans);
	fflush(stdout);
	return 0;
}