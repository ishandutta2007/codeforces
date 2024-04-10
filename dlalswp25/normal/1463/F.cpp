#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int mx[5050505];
vector<int> adj[50];
int N, X, Y;
int K, T;

int adjb[55];
int adjc[55];
int t, k;
int ans;

void f(int n, int bit, int cnt, int kc) {
	if(n == X) {
		// printf("%d\n", bit);
		mx[bit] = cnt * T + kc;
		return;
	}
	f(n + 1, bit, cnt, kc);
	if(bit & adjb[n]) return;
	f(n + 1, bit | (1 << n), cnt + 1, kc + (n < K));
}

void g(int n, int bit, int bitX, int cnt, int kc) {
	// printf("%d %d\n", n, bitX);
	if(n == Y) {
		int b = ((1 << X) - 1) ^ bitX;
		// printf("g %d %d\n", b, bitX);
		// printf("%d %d\n", cnt, kc);
		// if(N < X + Y) t = max(t, kc + mxk[b]);
		// else {
		// 	pii tmp = {mx[b].first + cnt, mx[b].second + kc};
		// 	tmp = max(tmp, pii(t, k));
		// 	tie(t, k) = tmp;
		// }
		ans = max(ans, mx[b] + cnt * T + kc);
		return;
	}
	g(n + 1, bit, bitX, cnt, kc);
	if(bit & adjb[n]) return;
	g(n + 1, bit | (1 << n), bitX | adjc[n + X], cnt + 1, kc + (n + X < K));
}

int main() {
	scanf("%d%d%d", &N, &X, &Y);
	T = N / (X + Y);
	if(X < Y) swap(X, Y);
	K = N % (X + Y);
	for(int i = 0; i < X + Y; i++) {
		if(i < Y) {
			adj[i].push_back(i + X);
			adj[i + X].push_back(i);
		}
		if(i < X) {
			adj[i].push_back(i + Y);
			adj[i + Y].push_back(i);
		}
	}

	for(int i = 0; i < X; i++) {
		for(int j : adj[i]) {
			if(j < X) adjb[i] |= (1 << j);
		}
	}
	for(int i = X; i < X + Y; i++) {
		for(int j : adj[i]) {
			if(j >= X) adjb[i] |= (1 << (j - X));
			else adjc[i] |= (1 << j);
		}
	}

	f(0, 0, 0, 0);
	for(int i = 1; i < X; i++) {
		for(int j = 1; j < (1 << X); j++) {
			if(j & (1 << i)) {
				mx[j] = max(mx[j], mx[j ^ (1 << i)]);
				//mxk[j] = max(mxk[j], mxk[j ^ (1 << i)]);
			}
		}
	}

	g(0, 0, 0, 0, 0);
	// printf("%d %d\n", t, k);
	// if(N < X + Y) printf("%d\n", t);
	// else printf("%d\n", t * (N / (X + Y)) + k);
	printf("%d\n", ans);

	// for(int i = 1; i <= X + Y; i++) {
	// 	if(!A[i]) {
	// 		A[i] = 1;
	// 		A[i + X] = -1;
	// 		A[i + Y] = -1;
	// 	}
	// 	S[i] = S[i - 1] + (A[i] == 1);
	// }

	// for(int i = 1; i <= X + Y; i++) printf(A[i] == 1 ? "O" : "X"); puts("");

	// printf("%d\n", S[X + Y] * t + S[N % (X + Y)]);

	return 0;
}