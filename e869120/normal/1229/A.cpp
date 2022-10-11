#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 18], B[1 << 18];
bool used[1 << 18];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];

	long long maxn = 0; queue<int> Q;
	for (int i = 1; i <= N; i++) {
		long long sum = 0, sum2 = 0;
		for (int j = 1; j <= N; j++) {
			if (A[j] == A[i]) sum2++;
		}
		if (sum2 >= 2) { used[i] = true; Q.push(i); }
	}

	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (int i = 1; i <= N; i++) {
			if ((A[pos] | A[i]) == A[pos] && used[i] == false) { used[i] = true; Q.push(i); }
		}
	}

	long long sum = 0;
	for (int i = 1; i <= N; i++) { if (used[i] == true) sum += B[i]; }
	cout << sum << endl;
	return 0;
}