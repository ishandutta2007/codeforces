#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

int N;
int A[202020];
int D[202020];
vector<int> divs[202020];

int main() {
	for(int i = 1; i <= MX; i++) {
		for(int j = i; j <= MX; j += i) divs[j].push_back(i);
	}
	int tc; scanf("%d", &tc);
	while(tc--) {
		for(int i = 1; i <= MX; i++) D[i] = 0;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			int mx = 0;
			for(int j : divs[A[i]]) {
				mx = max(mx, D[j]);
			}
			D[A[i]] = mx + 1;
			ans = max(ans, D[A[i]]);
		}
		printf("%d\n", N - ans);
	}
	return 0;
}