#include <bits/stdc++.h>

using namespace std;

int X[105];
int Y[105];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &X[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &Y[i]);
		sort(X + 1, X + N + 1);
		sort(Y + 1, Y + N + 1);
		for(int i = 1; i <= N; i++) printf("%d ", X[i]); puts("");
		for(int i = 1; i <= N; i++) printf("%d ", Y[i]); puts("");
	}
	return 0;
}