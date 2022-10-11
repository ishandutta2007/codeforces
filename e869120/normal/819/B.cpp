#include<iostream>
#include<algorithm>
using namespace std;
#pragma warning(disable: 4996)
long long r[2000005], n, p[1000005];
int main() {
	cin >> n; int m = n;
	for (int i = 0; i < m; i++) {
		scanf("%lld", &p[i]); p[i]--;
		r[p[i] + (n - i) + 1] += 1; r[n + (n - i)] -= (n - p[i]); r[n + (n - i) + 1] += (n - p[i] - 1);
		r[p[i] + (n - i) + 1] += 1; r[(n - i) + 1] -= (p[i] + 1); r[(n - i)] += (p[i]);
	}
	for (int i = 1; i <= 2 * n; i++)r[i] += r[i - 1];
	for (int i = 1; i <= 2 * n; i++)r[i] += r[i - 1];
	long long minx = (1LL << 60), minid = 0;
	for (int i = 0; i < n; i++) {
		long long s = r[i] + r[n + i];
		if (minx > s) { minx = s; minid = i; }
	}
	cout << minx << ' ' << minid << endl;
	return 0;
}