#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
const long double eps = 1e-20;

struct PT {
	int x, y;
} P[N];

long double ang[N];
int id[N];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &P[i].x, &P[i].y);
	for (int i = 0; i < n; i++) id[i] = i;
	for (int i = 0; i < n; i++) ang[i] = atan2(P[i].y, P[i].x);
	sort(id, id + n, [](int u, int v) {
		return ang[u] < ang[v];
	});
	const long double pi = acos(-1);
	long double ans = 2 * pi;
	int a = -1, b = -1;
	for (int i = 0; i < n; i++) {
		int u = id[i], v = id[(i + 1) % n];
		long double g = fabs(ang[u] - ang[v]);
//		if (g > 2 * pi + eps) g -= 2 * pi;
//		if (g < -eps) g += 2 * pi;
		long double h = min(g, 2 * pi - g);
		if (h < ans) ans = h, a = u, b = v;
	}
	printf("%d %d\n", a + 1, b + 1);
	return 0;
}