#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		if(N & 1) { puts("-1"); continue; }
		vector<pii> ans;
		if(A[1] != A[2]) {
			ans.emplace_back(1, 1);
			ans.emplace_back(2, 2);
		}
		else {
			ans.emplace_back(1, 2);
		}
		for(int i = 4; i <= N; i += 2) {
			if(A[i - 1] == A[i]) {
				ans.back().second += 2;
			}
			else {
				ans.emplace_back(i - 1, i - 1);
				ans.emplace_back(i, i);
			}
		}
		printf("%d\n", ans.size());
		for(pii i : ans) printf("%d %d\n", i.first, i.second);
	}
	return 0;
}