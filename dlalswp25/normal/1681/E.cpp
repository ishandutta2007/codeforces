#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
int X[101010][2];
int Y[101010][2];
int BX[101010][2];
int BY[101010][2];
ll S[20][101010][2][2];

int move(int l, int x1, int y1, int x2, int y2) {
	if(x1 == l && x2 == l) return abs(y1 - y2);
	if(y1 == l && y2 == l) return abs(x1 - x2);
	if(x1 != l) { swap(x1, x2); swap(y1, y2); }
	return (l - y1) + (l - x2);
}

void f(int b, int s, int e) {
	if(s == e) return;
	int m = s + e >> 1;
	for(int k = m; k <= m + 1; k++) {
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				S[b][k][i][j] = move(k, BX[k][i], BY[k][i], X[k][j], Y[k][j]);
			}
		}
	}

	for(int k = m - 1; k >= s; k--) {
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				S[b][k][i][j] = min(
					move(k, BX[k][i], BY[k][i], X[k][0], Y[k][0]) + 1 + S[b][k + 1][0][j],
					move(k, BX[k][i], BY[k][i], X[k][1], Y[k][1]) + 1 + S[b][k + 1][1][j]
				);
			}
		}
	}

	for(int k = m + 2; k <= e; k++) {
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				S[b][k][i][j] = min(
					S[b][k - 1][i][0] + 1 + move(k, BX[k][0], BY[k][0], X[k][j], Y[k][j]),
					S[b][k - 1][i][1] + 1 + move(k, BX[k][1], BY[k][1], X[k][j], Y[k][j])
				);
			}
		}
	}

	f(b + 1, s, m);
	f(b + 1, m + 1, e);
}

ll get(int b, int s, int e, int p, int q, int i, int j) {
	if(s == e) {
		return move(s, BX[s][i], BY[s][i], X[s][j], Y[s][j]);
	}
	int m = s + e >> 1;
	if(m < p) return get(b + 1, m + 1, e, p, q, i, j);
	if(q <= m) return get(b + 1, s, m, p, q, i, j);
	return min(
		S[b][p][i][0] + 1 + S[b][q][0][j],
		S[b][p][i][1] + 1 + S[b][q][1][j]
	);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) scanf("%d%d%d%d", &X[i][0], &Y[i][0], &X[i][1], &Y[i][1]);
	BX[1][0] = BX[1][1] = BY[1][0] = BY[1][1] = 1;
	for(int i = 2; i <= N; i++) {
		BX[i][0] = X[i - 1][0] + 1;
		BY[i][0] = Y[i - 1][0];
		BX[i][1] = X[i - 1][1];
		BY[i][1] = Y[i - 1][1] + 1;
	}
	f(1, 1, N - 1);
	scanf("%d", &Q);
	while(Q--) {
		int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int l1 = max(x1, y1), l2 = max(x2, y2);
		if(l1 > l2) { swap(x1, x2); swap(y1, y2); swap(l1, l2); }
		if(l1 == l2) printf("%d\n", move(l1, x1, y1, x2, y2));
		else if(l1 + 1 == l2) {
			printf("%d\n", min(
				1 + move(l1, x1, y1, X[l1][0], Y[l1][0]) + move(l2, x2, y2, BX[l2][0], BY[l2][0]),
				1 + move(l1, x1, y1, X[l1][1], Y[l1][1]) + move(l2, x2, y2, BX[l2][1], BY[l2][1])
			));
		}
		else {
			ll ans = 1LL << 60;
			for(int i = 0; i < 2; i++) {
				for(int j = 0; j < 2; j++) {
					ll t = 1 + move(l1, x1, y1, X[l1][i], Y[l1][i]);
					t += 1 + move(l2, x2, y2, BX[l2][j], BY[l2][j]);
					t += get(1, 1, N - 1, l1 + 1, l2 - 1, i, j);
					ans = min(ans, t);
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}