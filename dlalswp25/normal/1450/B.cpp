#include <bits/stdc++.h>

using namespace std;

int N, K;
int X[105];
int Y[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d%d", &X[i], &Y[i]);
		bool ok = false;
		for(int i = 1; i <= N; i++) {
			bool fg = true;
			for(int j = 1; j <= N; j++) {
				if(i == j) continue;
				if(abs(X[i] - X[j]) + abs(Y[i] - Y[j]) > K) fg = false;
			}
			if(fg) ok = true;
		}
		puts(ok ? "1" : "-1");
	}
	return 0;
}