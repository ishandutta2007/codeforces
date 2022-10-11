#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, K, A[100009], p1, p2, maxn;

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (A[i] == 1) p1++; if (A[i] == -1) p2++;
	}
	for (int i = 1; i <= K; i++) {
		int v1 = p1, v2 = p2;
		for (int j = i; j <= N; j += K) {
			if (A[j] == 1) v1--; if (A[j] == -1) v2--;
		}
		maxn = max(maxn, abs(v1 - v2));
	}
	cout << maxn << endl;
	return 0;
}