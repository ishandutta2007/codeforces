#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int a[N], t[N];

int main() {
	int n, T; scanf("%d%d", &n, &T);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
	long long zsum = 0;
	long long psum = 0;
	long long nsum = 0;
	for (int i = 1; i <= n; i++) {
		if (t[i] == T) zsum += a[i];
		if (t[i] > T) {
			psum += (t[i] - T) * 1LL * a[i];
		} else {
			nsum += (T - t[i]) * 1LL * a[i];
		}
	}
	long long sum = min(psum, nsum);
	long double ans = zsum;
	{
		vector<int> V;
		for (int i = 1; i <= n; i++) {
			if (t[i] > T) V.push_back(i);
		}
		sort(V.begin(), V.end(), [](int i, int j) {
			return t[i] < t[j];
		});
		long long tsum = 0;
		for (int u : V) {
			tsum += a[u] * 1LL * (t[u] - T);
			if (tsum <= sum) ans += a[u];
			else {
				ans += a[u] - (long double)(tsum - sum) / (t[u] - T);
				break;
			}
		}
	}
	{
		vector<int> V;
		for (int i = 1; i <= n; i++) {
			if (t[i] < T) V.push_back(i);
		}
		sort(V.begin(), V.end(), [](int i, int j) {
			return t[i] > t[j];
		});
		long long tsum = 0;
		for (int u : V) {
			tsum += a[u] * 1LL * (T - t[u]);
			if (tsum <= sum) ans += a[u];
			else {
				ans += a[u] - (long double)(tsum - sum) / (T - t[u]);
				break;
			}
		}
	}
	printf("%.10lf\n", (double)ans);
	return 0;
}