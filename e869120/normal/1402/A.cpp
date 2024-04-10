#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, D;
long long A[1 << 18];
vector<long long> V1, V2;
vector<long long> W1, W2;

long long solve(long long d) {
	long long c = N - (1LL * (d - 1LL) * (D + 1LL) + 1LL);
	if (d == 0) c = N;
	if (c < 0) return -(1LL << 60);
	return W1[min((long long)W1.size() - 1, c)];
}

int main() {
	scanf("%lld%lld%lld", &N, &D, &M);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= N; i++) {
		if (A[i] <= M) V1.push_back(A[i]);
		if (A[i] > M) V2.push_back(A[i]);
	}
	sort(V1.begin(), V1.end()); reverse(V1.begin(), V1.end());
	sort(V2.begin(), V2.end()); reverse(V2.begin(), V2.end());
	W1.resize(V1.size() + 1, 0); for (int i = 1; i <= V1.size(); i++) W1[i] = W1[i - 1] + V1[i - 1];
	W2.resize(V2.size() + 1, 0); for (int i = 1; i <= V2.size(); i++) W2[i] = W2[i - 1] + V2[i - 1];
	
	long long Answer = 0;
	for (int i = 0; i <= V2.size(); i++) {
		long long val = solve(i);
		Answer = max(Answer, W2[i] + val);
	}
	cout << Answer << endl;
	return 0;
}