#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, K;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	cin >> N >> M >> K;
	long long A = N * M, B = K;
	long long C = gcd(A, B);
	A /= C; B /= C;

	if (B >= 3) cout << "NO" << endl;
	else {
		long long V1 = K;
		long long V2 = gcd(V1, N); N /= V2; V1 /= V2;
		long long V3 = gcd(V1, M); M /= V3; V1 /= V3;
		if (B == 1) {
			if (V2 >= 2) N *= 2;
			else if (V3 >= 2) M *= 2;
		}
		cout << "YES" << endl;
		cout << "0 0 " << endl;
		cout << "0 " << M << endl;
		cout << N << " 0" << endl;
	}
	return 0;
}