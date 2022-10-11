#include <bits/stdc++.h>
using namespace std;

int N, A[1 << 18];
map<int, int> Map;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		Map[A[i]]++;
	}
	int maxn = 0;
	for (int i = 1; i <= N; i++) maxn = max(maxn, Map[A[i]]);
	cout << N - maxn << endl;
	return 0;
}