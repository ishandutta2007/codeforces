#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = 1000000;
long long n, a[MAX_N + 9], sum; vector<long long>x[MAX_N + 9];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]); x[a[i]].push_back(i);
	}
	for (int i = 1; i <= MAX_N; i++) {
		x[i].push_back(0); x[i].push_back(n + 1);
		sort(x[i].begin(), x[i].end());
		long long E = n * (n + 1) / 2;
		for (int j = 0; j < x[i].size() - 1; j++) E -= (x[i][j + 1] - x[i][j]) * (x[i][j + 1] - x[i][j] - 1) / 2;
		sum += E;
	}
	sum *= 2; sum -= n;
	printf("%.12Lf\n", 1.0L * sum / (n * n));
	return 0;
}