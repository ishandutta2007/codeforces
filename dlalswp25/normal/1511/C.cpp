#include <bits/stdc++.h>

using namespace std;

int N, Q;
int A[303030];
int pos[55];

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) if(!pos[A[i]]) pos[A[i]] = i;
	while(Q--) {
		int x; scanf("%d", &x);
		printf("%d ", pos[x]);
		for(int i = 1; i <= 50; i++) {
			if(i == x) continue;
			if(pos[i] && pos[i] < pos[x]) pos[i]++;
		}
		pos[x] = 1;
	}
	puts("");
	return 0;
}