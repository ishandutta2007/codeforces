#include <iostream>
#include <algorithm>
using namespace std;

long long N, K, A, B, sum, maxn = (1LL << 60);

int main() {
	cin >> N >> K >> A >> B;
	if (K == 1) {
		cout << (N - 1)*A << endl;
		return 0;
	}
	while (N >= 1) {
		maxn = min(maxn, sum + (N - 1)*A);
		sum += (N%K)*A;
		N /= K; sum += B;
	}
	cout << maxn << endl;
	return 0;
}