#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18], ret = -1, maxn = -1;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for (int i = 1; i <= N; i++) {
		if (0 <= A[i] && A[i] <= maxn + 1) { maxn = max(maxn, A[i]); continue; }
		ret = i;
		break;
	}
	cout << ret << endl;
	return 0;
}