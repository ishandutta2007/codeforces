#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18], B[1 << 18];
vector<int>X[1 << 18];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d", &A[i], &B[i]);
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}

	int pos1 = -1, pos2 = -1;
	for (int i = 1; i <= N; i++) {
		if (X[i].size() == 2) pos2 = i;
		if (X[i].size() >= 3) {
			if (pos1 == -1) { pos1 = i; }
			else {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	if (pos1 == -1) pos1 = pos2;
	if (pos1 == -1) pos1 = 1;

	vector<pair<int, int>>vec;
	for (int i = 1; i <= N; i++) {
		if (pos1 != i && X[i].size() == 1) vec.push_back(make_pair(pos1, i));
	}
	printf("Yes\n");
	printf("%d\n", (int)vec.size());
	for (int i = 0; i < vec.size(); i++) printf("%d %d\n", vec[i].first, vec[i].second);
	return 0;
}