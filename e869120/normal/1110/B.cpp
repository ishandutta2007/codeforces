#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, L, K, B[1 << 18], J; vector<long long>X;

int main() {
	scanf("%lld%lld%lld", &N, &L, &K);
	for (int i = 0; i < N; i++) scanf("%lld", &B[i]);

	for (int i = 0; i < N - 1; i++) X.push_back(B[i + 1] - B[i] - 1);
	sort(X.begin(), X.end());

	J = N;
	for (int i = 0; i < N - K; i++) J += X[i];
	cout << J << endl;
	return 0;
}