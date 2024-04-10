#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N, K, L[1 << 18], R[1 << 18];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> L[i] >> R[i];
	}
	cin >> K;
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (K <= R[i]) sum++;
	}
	cout << sum << endl;
	return 0;
}