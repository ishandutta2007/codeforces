#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int bit[500009];

void add(int pos, int x) {
	pos++;
	while (pos <= 500008) { bit[pos] += x; pos += (pos&-pos); }
}
int sum(int pos) {
	int s = 0; pos++;
	while (pos >= 1) { s += bit[pos]; pos -= (pos&-pos); }
	return s;
}

int N, K, D, A[500009], dp[500009];

int main() {
	cin >> N >> K >> D;
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	sort(A + 1, A + N + 1);

	dp[0] = 1; add(0, 1);
	for (int i = 1; i <= N; i++) {
		int pos1 = lower_bound(A + 1, A + N + 1, A[i] - D) - A; pos1--;
		int G = sum(i - K) - sum(pos1 - 1);
		if (G >= 1) {
			dp[i] = 1; add(i, 1);
		}
	}
	if (dp[N] == 1) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}