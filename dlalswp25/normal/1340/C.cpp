#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

queue<pii> q;
queue<pii> tmp;

int N, M;
int G, R;
int A[10101];
int D[10101][1010];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) scanf("%d", &A[i]);
	scanf("%d%d", &G, &R);
	sort(A + 1, A + M + 1);

	D[1][G] = 1;
	q.push({1, G});

	while(q.size() || tmp.size()) {
		if(!q.size()) {
			while(tmp.size()) {
				q.push(tmp.front());
				tmp.pop();
			}
			continue;
		}

		pii now = q.front(); q.pop();
		int x = now.first, t = now.second;
		// printf("%d %d %d\n", x, t, D[x][t]);

		if(t == 0) {
			if(!D[x][G]) {
				D[x][G] = D[x][t] + 1;
				tmp.push({x, G});
			}
		}
		else {
			if(x > 1 && t >= A[x] - A[x - 1]) {
				int nt = t - (A[x] - A[x - 1]);
				if(!D[x - 1][nt] || D[x - 1][nt] > D[x][t]) {
					D[x - 1][nt] = D[x][t];
					q.push({x - 1, nt});
				}
			}
			if(x < M && t >= A[x + 1] - A[x]) {
				int nt = t - (A[x + 1] - A[x]);
				if(!D[x + 1][nt] || D[x + 1][nt] > D[x][t]) {
					D[x + 1][nt] = D[x][t];
					q.push({x + 1, nt});
				}
			}
		}
	}

	int ans = 20202020;
	for(int i = 0; i <= G; i++) {
		if(D[M][i]) {
			ans = min(ans, (D[M][i] - 1) * (R + G) + (G - i));
		}
	}
	if(ans == 20202020) puts("-1");
	else printf("%d\n", ans);
	return 0;
}