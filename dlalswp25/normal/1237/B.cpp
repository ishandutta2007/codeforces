#include <bits/stdc++.h>

using namespace std;

int A[101010];
int B[101010];
bool no[101010];

int N;
int ans;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) scanf("%d", &B[i]);

	int p = 1;
	for(int i = 1; i <= N; i++) {
		if(no[A[i]]) continue;
		while(p <= N) {
			if(B[p] == A[i]) break;
			no[B[p]] = true;
			ans++;
			p++;
		}
		p++;
	}
	printf("%d\n", ans);

	return 0;
}