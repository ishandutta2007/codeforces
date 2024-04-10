#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll X[70];
ll Y[70];
ll ax, ay, bx, by;

ll sx, sy, t;

ll dist(ll px, ll py, ll qx, ll qy) {
	return abs(px - qx) + abs(py - qy);
}

int main() {
	scanf("%lld%lld%lld%lld%lld%lld", &X[0], &Y[0], &ax, &ay, &bx, &by);
	scanf("%lld%lld%lld", &sx, &sy, &t);

	int N = 1;
	for(; ; N++) {
		X[N] = X[N - 1] * ax + bx;
		Y[N] = Y[N - 1] * ay + by;
		if(X[N] > (1LL << 55) || Y[N] > (1LL << 55)) break;
	}

	int ans = 0;

	for(int i = 0; i < N; i++) {
		if(dist(X[i], Y[i], sx, sy) > t) continue;

		ll s = dist(X[i], Y[i], sx, sy);
		for(int j = i; j >= 0; j--) {
			ll sum = s;
			int tmp = 1;
			int now = i;
			while(now > j) {
				sum += dist(X[now - 1], Y[now - 1], X[now], Y[now]);
				now--; tmp++;
			}
			// printf("%d %d %lld\n", i, j, sum);
			if(sum > t) continue;
			ans = max(ans, tmp);
			sum += dist(X[now], Y[now], X[i], Y[i]);

			if(sum > t) continue;
			now = i;
			while(now < N - 1) {
				ans = max(ans, tmp);
				sum += dist(X[now], Y[now], X[now + 1], Y[now + 1]);
				now++; 
				if(sum > t) break;
				tmp++; ans = max(ans, tmp);
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}