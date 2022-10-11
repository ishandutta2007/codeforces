#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N, M, C[10009]; bool used[59][10009];

int main() {
	scanf("%d%d", &M, &N);
	for (int i = 0; i < M; i++) {
		int ss; scanf("%d", &ss); for (int j = 0; j < ss; j++) { int t; scanf("%d", &t); used[i][t - 1] = true; }
	}
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			for (int k = 0; k < N; k++) C[k] = 0;
			for (int k = 0; k < N; k++) { if (used[i][k] == true) C[k]++; }
			for (int k = 0; k < N; k++) { if (used[j][k] == true) C[k]++; }
			
			bool flag = true;
			for (int k = 0; k < N; k++) { if (C[k] == 2) flag = false; }

			if (flag == true) {
				cout << "impossible" << endl;
				return 0;
			}
		}
	}
	cout << "possible" << endl;
	return 0;
}