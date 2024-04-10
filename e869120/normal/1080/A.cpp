#include <iostream>
using namespace std;

long long N, K, A, B, C, S;

int main() {
	cin >> N >> K;
	A = 2LL * N;
	B = 5LL * N;
	C = 8LL * N;
	S += (A + K - 1) / K;
	S += (B + K - 1) / K;
	S += (C + K - 1) / K;
	cout << S << endl;
	return 0;
}