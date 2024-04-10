#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		set<int> S;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			S.insert(A[i]);
		}
		bool ok = false;
		for(int i = 1; i <= N; i++) {
			if(S.find(A[i] + K) != S.end()) ok = true;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}