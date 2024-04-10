#include <bits/stdc++.h>

using namespace std;

int N;
int A[15];
set<int> S;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		S.clear();
		scanf("%d", &N);
		for(int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
			A[i] = abs(A[i]);
		}
		bool ok = false;

		for(int i = 0; i < 1 << N; i++) {
			int sum = 0;
			for(int j = 0; j < N; j++) {
				if(i & 1 << j) sum += A[j];
			}
			if(S.find(sum) != S.end()) ok = true;
			S.insert(sum);
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}