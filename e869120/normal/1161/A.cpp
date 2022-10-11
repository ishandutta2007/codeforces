#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, K, A[1 << 19], sum; vector<int>vec[1 << 17];

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &A[i]);
		vec[A[i]].push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		if (vec[i].size() == 0) sum++;
	}
	for (int i = 1; i <= N - 1; i++) {
		if (vec[i].size() == 0 || vec[i + 1].size() == 0 || vec[i][0] > vec[i + 1][vec[i + 1].size() - 1]) sum++;
	}
	for (int i = 1; i <= N - 1; i++) {
		if (vec[i + 1].size() == 0 || vec[i].size() == 0 || vec[i + 1][0] > vec[i][vec[i].size() - 1]) sum++;
	}
	cout << sum << endl;
	return 0;
}