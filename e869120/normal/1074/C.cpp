#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, X[1 << 19], Y[1 << 19];
long long minx = (1LL << 60), maxx = -(1LL << 60), miny = (1LL << 60), maxy = -(1LL << 60);

long long dist(int c1, int c2) {
	return abs(X[c1] - X[c2]) + abs(Y[c1] - Y[c2]);
}

long long solve3() {
	long long id1 = 0, minv = (1LL << 60);
	for (int i = 1; i <= N; i++) { if (minv > X[i]) { minv = X[i]; id1 = i; } }
	long long id2 = 0, minw = (1LL << 60);
	for (int i = 1; i <= N; i++) { if (minw > Y[i]) { minw = Y[i]; id2 = i; } }

	long long res = -(1LL << 60);
	for (int i = 1; i <= N; i++) {
		if (i == id1 || i == id2) continue;
		res = max(res, dist(id1, id2) + dist(id2, i) + dist(i, id1));
	}
	return res;
}

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld%lld", &X[i], &Y[i]);
		minx = min(minx, X[i]);
		maxx = max(maxx, X[i]);
		miny = min(miny, Y[i]);
		maxy = max(maxy, Y[i]);
	}

	long long ret = -(1LL << 60);
	for (int i = 1; i <= 8; i++) {
		ret = max(ret, solve3());
		for (int j = 1; j <= N; j++) X[j] *= -1;
		if (i % 2 == 0) {
			for (int j = 1; j <= N; j++) {
				long long px = Y[j], py = -X[j];
				X[j] = px; Y[j] = py;
			}
		}
	}
	printf("%lld", ret);
	for (int i = 4; i <= N; i++) printf(" %lld", 2LL * (maxx - minx + maxy - miny));
	printf("\n");
	return 0;
}