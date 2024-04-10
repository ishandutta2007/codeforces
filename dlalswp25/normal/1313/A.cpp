#include <bits/stdc++.h>

using namespace std;

int a[3];
int x[8][3];
int ans;

void f(int n, int k) {
	if(n > 7) { ans = max(ans, k); return; }
	f(n + 1, k);
	for(int i = n; i <= 7; i++) {
		bool ok = true;
		for(int j = 0; j < 3; j++) { a[j] -= x[i][j]; if(a[j] < 0) ok = false; }
		if(ok) f(i + 1, k + 1);
		for(int j = 0; j < 3; j++) a[j] += x[i][j];
	}
}

int main() {
	for(int i = 1; i <= 7; i++) {
		for(int j = 0; j < 3; j++) if((1 << j) & i) x[i][j] = 1;
	}
	int T; scanf("%d", &T);
	while(T--) {
		ans = 0;
		for(int i = 0; i < 3; i++) scanf("%d", &a[i]);
		f(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}