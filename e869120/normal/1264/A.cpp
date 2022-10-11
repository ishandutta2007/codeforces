#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int T, N, A[1 << 19];

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		for (int j = 1; j <= N; j++) scanf("%d", &A[j]);

		vector<int> vec; int sb = -1;
		for (int j = 1; j <= N / 2; j++) {
			if (j == N || A[j] != A[j + 1]) {
				if (sb == -1) { vec.push_back(j); sb = j; }
				else if (sb * 2 < j) vec.push_back(j);
			}
		}

		if (vec.size() <= 2) printf("0 0 0\n");
		else if (vec[vec.size() - 1] - vec[1] <= vec[0]) printf("0 0 0\n");
		else {
			printf("%d %d %d\n", vec[0], vec[1] - vec[0], vec[vec.size() - 1] - vec[1]);
		}
	}
	return 0;
}