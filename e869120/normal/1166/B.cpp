#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int K; char c[6] = "aeiou";

int main() {
	cin >> K;
	for (int i = 1; i <= K; i++) {
		if (K%i != 0) continue;

		int a1 = i, a2 = K / i;
		if (a1 < 5 || a2 < 5) continue;

		for (int j = 0; j < a1; j++) {
			for (int k = 0; k < a2; k++) {
				cout << c[(j + k) % 5];
			}
		}
		cout << endl;
		return 0;
	}
	cout << "-1" << endl;
	return 0;
}