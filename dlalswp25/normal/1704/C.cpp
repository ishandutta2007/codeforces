#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		vector<int> V;
		for(int i = 1; i <= M; i++) scanf("%d", &A[i]);
		sort(A + 1, A + M + 1);
		for(int i = 1; i < M; i++) V.push_back(A[i + 1] - A[i] - 1);
		V.push_back(A[1] + N - A[M] - 1);
		sort(V.begin(), V.end());
		reverse(V.begin(), V.end());
		int day = 0, ans = 0;
		for(int i : V) {
			int rem = i - 2 * day;
			if(rem <= 0) break;
			if(rem >= 3) {
				ans += rem - 1; day += 2;
			}
			else {
				ans++; day++;
			}
		}
		printf("%d\n", N - ans);
	}
	return 0;
}