#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 19], B[1 << 19]; vector<int>L1, L2;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) scanf("%d", &B[i]);

	for (int i = 0; i < N - 1; i++) L1.push_back(A[i + 1] - A[i]);
	for (int i = 0; i < N - 1; i++) L2.push_back(B[i + 1] - B[i]);
	sort(L1.begin(), L1.end());
	sort(L2.begin(), L2.end());

	if (L1 == L2 && A[0] == B[0] && A[N - 1] == B[N - 1]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}