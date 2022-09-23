#include <bits/stdc++.h>

using namespace std;

int N;
int A[50505][10];

bool win(int i, int j) {
	int cnt = 0;
	for(int k = 1; k <= 5; k++) cnt += A[i][k] < A[j][k];
	return cnt >= 3;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) for(int j = 1; j <= 5; j++) scanf("%d", &A[i][j]);
		int x = 1;
		for(int i = 2; i <= N; i++) {
			if(win(x, i)) continue;
			x = i;
		}
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(x == i) continue;
			if(!win(x, i)) ok = false;
		}
		if(!ok) puts("-1");
		else printf("%d\n", x);
	}
	return 0;
}