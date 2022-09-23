#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

char A[2020];
char B[2020];
int N, K, T;
vector<pii> ans;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &K);
		scanf("%s", A + 1);
		for(int i = 1; i < K; i++) {
			B[2 * i - 1] = '(';
			B[2 * i] = ')';
		}
		for(int l = 2 * K - 1, r = N; l < r; l++, r--) {
			B[l] = '('; B[r] = ')';
		}

		for(int i = 1; i <= N; i++) {
			int j = i;
			while(A[j] != B[i]) j++;
			if(i == j) continue;
			ans.push_back({i, j});
			for(int l = i, r = j; l < r; l++, r--) swap(A[l], A[r]);
		}

		printf("%d\n", ans.size());
		for(pii i : ans) printf("%d %d\n", i.first, i.second);

		ans.clear();
	}
	return 0;
}