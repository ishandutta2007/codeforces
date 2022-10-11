#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, A[1 << 19], B[1 << 19], S;

int main() {
	scanf("%lld%lld", &N, &K);
	for (int i = 0; i < N; i++) { scanf("%lld", &A[i]); S += A[i]; }
	for (int i = N - 1; i >= 0; i--) B[i] = B[i + 1] + A[i];

	vector<long long>E;
	for (int i = 1; i < N; i++) E.push_back(B[i]);
	sort(E.begin(), E.end());
	reverse(E.begin(), E.end());
	for (int i = 0; i < K - 1; i++) S += E[i];

	cout << S << endl;
	return 0;
}