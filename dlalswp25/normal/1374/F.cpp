#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> A[505];
int B[505];
int pos[505];
vector<int> ans;

void rot(int x) {
	ans.push_back(x);
	int a = B[x], b = B[x + 1], c = B[x + 2];
	int t = pos[a]; pos[a] = pos[b]; pos[b] = pos[c]; pos[c] = t;
	t = B[x]; B[x] = B[x + 2]; B[x + 2] = B[x + 1]; B[x + 1] = t;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i].first);
			A[i].second = i;
		}

		int inv = 0;
		bool sm = false;
		int x, y;

		for(int i = 1; i <= N; i++) {
			for(int j = i + 1; j <= N; j++) {
				if(A[i].first > A[j].first) inv++;
				if(A[i].first == A[j].first) {
					sm = true;
					x = i; y = j;
				}
			}
		}
		if((inv & 1) && !sm) { puts("-1"); continue; }

		sort(A + 1, A + N + 1);
		for(int i = 1; i <= N; i++) B[A[i].second] = i;
		if(inv & 1) swap(B[x], B[y]);

		// for(int i = 1; i <= N; i++) printf("%d ", B[i]); puts("");

		for(int i = 1; i <= N; i++) pos[B[i]] = i;
		ans.clear();

		for(int i = 1; i <= N; i++) {
			while(pos[i] - i >= 2) {
				rot(pos[i] - 2);
			}
			if(pos[i] == i) continue;
			rot(i);
			rot(i);
		}

		printf("%d\n", ans.size());
		for(int i : ans) printf("%d ", i); puts("");
	}
	return 0;
}