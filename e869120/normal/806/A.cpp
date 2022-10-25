#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long T;

long long solve(long long A, long long B, long long C, long long D) {
	if (C == 0) {
		if (A == 0) return 0;
		return -1;
	}
	if (C == D) {
		if (A == B) return 0;
		return -1;
	}

	long long a = A, b = B - A, c = C, d = D - C;

	long long V1 = (a + c - 1LL) / c;
	long long V2 = (b + d - 1LL) / d;
	long long EA = max(V1, V2) * c;
	long long EB = max(V1, V2) * d;
	return EA + EB - a - b;
}

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		long long p1, p2, p3, p4; cin >> p1 >> p2 >> p3 >> p4;
		cout << solve(p1, p2, p3, p4) << endl;
	}
	return 0;
}