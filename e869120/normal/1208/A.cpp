#include <iostream>
using namespace std;

int main() {
	int T, A, B, N;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> A >> B >> N; int sum = 0;
		for (int j = 0; j < 30; j++) {
			int p1 = (A / (1 << j)) % 2;
			int p2 = (B / (1 << j)) % 2;
			if (p1 == 1 && p2 == 1 && N % 3 != 2) sum += (1 << j);
			if (p1 == 0 && p2 == 1 && N % 3 != 0) sum += (1 << j);
			if (p1 == 1 && p2 == 0 && N % 3 != 1) sum += (1 << j);
		}
		cout << sum << endl;
	}
	return 0;
}