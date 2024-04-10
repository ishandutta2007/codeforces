#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll X[101010];
ll Y[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int x = 0, y = 0;
		for(int i = 1; i <= 2 * N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			if(!a) Y[++y] = abs(b);
			else X[++x] = abs(a);
		}

		sort(X + 1, X + N + 1);
		sort(Y + 1, Y + N + 1);
		double ans = 0;
		for(int i = 1; i <= N; i++) ans += sqrt(X[i] * X[i] + Y[i] * Y[i]);
		printf("%.12f\n", ans);
	}
	return 0;
}