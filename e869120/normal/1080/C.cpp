#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long T, H, W, x[4], y[4];

long long solve() {
	vector<long long>X, Y;
	X.push_back(1); X.push_back(H + 1); for (int i = 0; i < 4; i++) X.push_back(x[i]);
	Y.push_back(1); Y.push_back(W + 1); for (int i = 0; i < 4; i++) Y.push_back(y[i]);
	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	sort(Y.begin(), Y.end()); Y.erase(unique(Y.begin(), Y.end()), Y.end());

	for (int i = 0; i < 4; i++) x[i] = lower_bound(X.begin(), X.end(), x[i]) - X.begin();
	for (int i = 0; i < 4; i++) y[i] = lower_bound(Y.begin(), Y.end(), y[i]) - Y.begin();
	long long sum = 0;
	for (int i = 0; i < X.size() - 1; i++) {
		for (int j = 0; j < Y.size() - 1; j++) {
			long long B = -1;
			if (x[2] <= i && y[2] <= j && i < x[3] && j < y[3]) B = (X[i + 1] - X[i]) * (Y[j + 1] - Y[j]);
			else if (x[0] <= i && y[0] <= j && i < x[1] && j < y[1]) B = 0;
			else {
				long long V = (X[i + 1] - X[i]) * (Y[j + 1] - Y[j]);
				if ((X[i] + Y[j]) % 2 == 1) V++;
				B = V / 2;
			}
			sum += B;
		}
	}
	return sum;
}

int main() {
	scanf("%lld", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%lld%lld", &W, &H);
		scanf("%lld%lld%lld%lld", &x[0], &y[0], &x[1], &y[1]); x[1]++; y[1]++;
		scanf("%lld%lld%lld%lld", &x[2], &y[2], &x[3], &y[3]); x[3]++; y[3]++;

		long long V = solve();
		printf("%lld %lld\n", H * W - V, V);
	}
	return 0;
}