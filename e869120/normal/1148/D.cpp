#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 19], B[1 << 19];
vector<tuple<int, int, int>>V1, V2;

vector<int> solve(vector<tuple<int, int, int>> A) {
	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());

	vector<int>E;
	for (int i = 0; i < A.size(); i++) {
		E.push_back(get<2>(A[i]));
	}
	return E;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &A[i], &B[i]);
		if (A[i] < B[i]) V1.push_back(make_tuple(A[i], B[i], i));
		else V2.push_back(make_tuple(N + 1 - A[i], N + 1 - B[i], i));
	}
	vector<int> L1 = solve(V1);
	vector<int> L2 = solve(V2);

	vector<int> L3;
	if (L1.size() < L2.size()) L3 = L2;
	else L3 = L1;

	printf("%d\n", (int)L3.size());
	for (int i = 0; i < L3.size(); i++) { if (i) printf(" "); printf("%d", L3[i]); } printf("\n");
	return 0;
}