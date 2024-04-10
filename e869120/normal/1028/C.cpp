#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, px[1 << 18], py[1 << 18], qx[1 << 18], qy[1 << 18];
long long lx[1 << 18], ly[1 << 18], rx[1 << 18], ry[1 << 18];
long long ax[1 << 18], ay[1 << 18], bx[1 << 18], by[1 << 18];

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld%lld%lld%lld", &px[i], &py[i], &qx[i], &qy[i]);
	ax[0] = -(1LL << 60); ay[0] = -(1LL << 60); bx[0] = (1LL << 60); by[0] = (1LL << 60);
	for (int i = 1; i <= N; i++) {
		ax[i] = max(ax[i - 1], px[i]);
		ay[i] = max(ay[i - 1], py[i]);
		bx[i] = min(bx[i - 1], qx[i]);
		by[i] = min(by[i - 1], qy[i]);
	}
	lx[N + 1] = -(1LL << 60); ly[N + 1] = -(1LL << 60); rx[N + 1] = (1LL << 60); ry[N + 1] = (1LL << 60);
	for (int i = N; i >= 1; i--) {
		lx[i] = max(lx[i + 1], px[i]);
		ly[i] = max(ly[i + 1], py[i]);
		rx[i] = min(rx[i + 1], qx[i]);
		ry[i] = min(ry[i + 1], qy[i]);
	}
	for (int i = 1; i <= N; i++) {
		long long ex = max(ax[i - 1], lx[i + 1]);
		long long ey = max(ay[i - 1], ly[i + 1]);
		long long fx = min(bx[i - 1], rx[i + 1]);
		long long fy = min(by[i - 1], ry[i + 1]);
		if (ex <= fx && ey <= fy) {
			cout << ex << " " << ey << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}