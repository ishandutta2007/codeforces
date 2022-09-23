#include <bits/stdc++.h>

using namespace std;

int N, M;
int cnt[101010];
vector<int> V[101010];
int A[101010];
int ans[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= M; i++) V[i].clear();
		for(int i = 1; i <= M; i++) A[i] = i;
		for(int i = 1; i <= N; i++) cnt[i] = 0;
		for(int i = 1; i <= M; i++) {
			int k; scanf("%d", &k);
			for(int j = 0; j < k; j++) {
				int x; scanf("%d", &x);
				V[i].push_back(x);
			}
		}

		sort(A + 1, A + M + 1, [&](const int a, const int b) {
			return V[a].size() < V[b].size();
		});

		for(int i = 1; i <= M; i++) {
			int mn = 10101010, mni;
			for(int j : V[A[i]]) {
				if(mn > cnt[j]) { mn = cnt[j]; mni = j; }
			}
			ans[A[i]] = mni;
			cnt[mni]++;
		}

		bool ok = true;
		for(int i = 1; i <= N; i++) if(cnt[i] > (M + 1) / 2) ok = false;
		if(!ok) puts("NO");
		else {
			puts("YES");
			for(int i = 1; i <= M; i++) printf("%d ", ans[i]); puts("");
		}
	}
	return 0;
}