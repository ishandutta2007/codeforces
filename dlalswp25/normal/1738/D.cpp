#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int B[101010];
int A[101010];
vector<int> V[101010];
int cnt[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		int K = N;
		for(int i = 1; i <= N; i++) {
			if(B[i] < i) { K = i - 1; break; }
		}
		for(int i = 0; i <= N + 1; i++) { V[i].clear(); cnt[i] = 0; }
		for(int i = 1; i <= N; i++) {
			V[B[i]].push_back(i);
			cnt[B[i]]++;
		}
		for(int i = 0; i <= N + 1; i++) {
			sort(V[i].begin(), V[i].end(), [&](int a, int b) {
				return cnt[a] < cnt[b];
			});
		}
		queue<int> q;
		q.push(0);
		q.push(N + 1);
		vector<int> ans;
		while(q.size()) {
			int x = q.front(); q.pop();
			if(1 <= x && x <= N) ans.push_back(x);
			for(int i : V[x]) q.push(i);
		}
		printf("%d\n", K);
		for(int i : ans) printf("%d ", i); puts("");
	}
	return 0;
}