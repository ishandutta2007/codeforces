#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
char A[15][10101];
int X[15];
int P[10101];
int ans;
int ansP[10101];
pii Q[10101];

int calc() {
	int ret = 0;
	for(int i = 0; i < N; i++) {
		int score = 0;
		for(int j = 1; j <= M; j++) {
			if(A[i][j] == '1') score += P[j];
		}
		ret += abs(score - X[i]);
	}
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ans = -1;
		scanf("%d%d", &N, &M);
		for(int i = 0; i < N; i++) scanf("%d", &X[i]);
		for(int i = 0; i < N; i++) scanf("%s", A[i] + 1);
		for(int i = 0; i < 1 << N; i++) {
			for(int j = 1; j <= M; j++) Q[j] = {0, j};
			for(int j = 0; j < N; j++) {
				for(int k = 1; k <= M; k++) {
					if(A[j][k] != '1') continue;
					if(~i & 1 << j) Q[k].first--;
					else Q[k].first++;
				}
			}
			sort(Q + 1, Q + M + 1);
			for(int j = 1; j <= M; j++) P[Q[j].second] = j;
			int t = calc();
			if(ans < t) {
				ans = t;
				for(int j = 1; j <= M; j++) ansP[j] = P[j];
			}
		}
		for(int i = 1; i <= M; i++) printf("%d ", ansP[i]); puts("");
	}
	return 0;
}