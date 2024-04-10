#include <bits/stdc++.h>

using namespace std;

int A[1010];
vector<int> ans;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		ans.clear();
		for(int i = 1; i <= N; i += 2) {
			if(A[i] == A[i + 1]) {
				ans.push_back(A[i]);
				ans.push_back(A[i + 1]);
			}
			else ans.push_back(0);
		}

		printf("%d\n", ans.size());
		for(int i : ans) printf("%d ", i); puts("");
	}
	return 0;
}