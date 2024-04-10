#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18]; bool dp[1 << 18];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	vector<pair<int, int>>D; for (int i = 0; i < N; i++) D.push_back(make_pair(A[i], i));
	sort(D.begin(), D.end());
	reverse(D.begin(), D.end());

	// true : 
	for (int i = 0; i < N; i++) {
		dp[D[i].second] = true;
		int pos = D[i].second;
		for (int j = pos - A[pos]; j >= 0; j -= A[pos]) { if (dp[j] == true) dp[pos] = false; }
		for (int j = pos + A[pos]; j < N; j += A[pos]) { if (dp[j] == true) dp[pos] = false; }
	}
	for (int i = 0; i < N; i++) {
		if (dp[i] == true) printf("B");
		else printf("A");
	}
	printf("\n");
	return 0;
}