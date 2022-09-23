#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[2020];
int cnt[1010101];
vector<pii> ans;
vector<int> tmp;

void f(int i, int j) {
	ans.emplace_back(i, j);
	tmp.push_back(i); tmp.push_back(j);
	cnt[i]--; cnt[j]--;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= 2 * N; i++) {
			scanf("%d", &A[i]);
			cnt[A[i]]++;
		}
		sort(A + 1, A + 2 * N + 1);

		int x = -1;
		for(int i = 2 * N - 1; i >= 1; i--) {
			ans.clear(); tmp.clear();
			f(A[i], A[2 * N]);

			int y = A[2 * N];
			for(int j = 2 * N - 1; j >= 1; j--) {
				if(!cnt[A[j]]) continue;

				if(y < A[j] || !cnt[y - A[j]] || (y == A[j] + A[j] && cnt[A[j]] < 2)) {
					y = -1; break;
				}
				f(A[j], y - A[j]);
				y = A[j];
			}
			for(int j : tmp) cnt[j]++;
			tmp.clear();
			if(y < 0 || ans.size() < N) continue;
			x = ans[0].first + ans[0].second; break;
		}
		if(x > 0) {
			puts("YES");
			printf("%d\n", x);
			for(pii i : ans) printf("%d %d\n", i.first, i.second);
		}
		else puts("NO");

		for(int i = 1; i <= 2 * N; i++) cnt[A[i]] = 0;
	}
	return 0;
}