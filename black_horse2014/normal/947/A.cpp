#include <bits/stdc++.h>
using namespace std;

const int N = 1100000;

int val[N], pm[N];

int main() {	
	for (int i = 1; i < N; i++) val[i] = i;
	for (int i = 2; i * i < N; i++) 
		if (val[i] == i)
			for (int j = i * i; j < N; j += i) val[j] = i;
	for (int i = 2; i < N; i++) {
		pm[i] = max(val[i], pm[i / val[i]]);
	}
	for (int i = 2; i < N; i++) val[i] = pm[i];
	int X3;
	scanf("%d", &X3);
	int ans = X3;
	for (int p = 2; p < X3; p++) {
		if (X3 % p) continue;
		if (val[p] != p) continue;
		for (int X2 = X3; X2 >= X3 - p + 1; X2--) {
			int q = val[X2];
			if (q == 1 || q == X2) continue;
			if (X2 - q + 1 <= 2) continue;
			ans = min(ans, X2 - q + 1);	
		}
	}
	printf("%d\n", ans);
	return 0;
}