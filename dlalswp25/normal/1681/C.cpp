#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[105];
int B[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		vector<pii> ans;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		for(int i = 1; i < N; i++) {
			for(int j = N; j > i; j--) {
				if(A[j] <= A[j - 1] && B[j] <= B[j - 1]) {
					swap(A[j], A[j - 1]);
					swap(B[j], B[j - 1]);
					ans.emplace_back(j - 1, j);
				}
			}
		}
		bool ok = true;
		for(int i = 1; i < N; i++) {
			if(A[i] > A[i + 1] || B[i] > B[i + 1]) ok = false;
		}
		if(!ok) { puts("-1"); continue; }
		printf("%d\n", ans.size());
		for(pii i : ans) printf("%d %d\n", i.first, i.second);
	}
	return 0;
}