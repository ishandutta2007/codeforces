#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, C[1 << 19], maxn = 0;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &C[i]);
	for (int i = 1; i <= N; i++) { if (C[1] != C[i]) maxn = max(maxn, i - 1); }
	for (int i = 1; i <= N; i++) { if (C[i] != C[N]) maxn = max(maxn, N - i); }
	cout << maxn << endl;
	return 0;
}