#include <bits/stdc++.h>

using namespace std;

int N;
int A[303030];
int ans[303030];
vector<int> v[303030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) v[i].clear();
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			v[A[i]].push_back(i);
		}
		for(int i = 1; i <= N; i++) ans[i] = 0;

		ans[1] = 1;
		for(int i = 1; i <= N; i++) if(v[i].size() != 1) ans[1] = 0;

		int l = 0, r = N + 1;
		for(int i = 1; i < N; i++) {
			if(l + (N - r + 1) == i - 1 && v[i].size()) ans[N - i + 1] = 1;
			if(v[i].size() != 1) break;
			if(v[i][0] == l + 1) l++;
			else if(v[i][0] == r - 1) r--;
			else break;
		}

		for(int i = 1; i <= N; i++) printf("%d", ans[i]); puts("");
	}
	return 0;
}