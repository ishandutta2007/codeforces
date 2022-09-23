#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[101010];
ll D[505][8];
ll E[8];
bool ans[512];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	D[0][0] = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < 8; j++) E[j] = 0;
		for(int j = 0; j < A[i]; j++) {
			for(int k = 0; k < 8; k++) E[k] |= D[j][k];
		}
		for(int j = 0; j < 512; j++) {
			int k = j >> 6;
			int r = j & 63;
			if(E[k] >> r & 1) {
				int t = j ^ A[i];
				E[t >> 6] |= (1LL << (t & 63));
			}
		}
		for(int j = 0; j < 8; j++) D[A[i]][j] |= E[j];
	}

	int cnt = 0;
	for(int i = 0; i < 512; i++) {
		int k = i >> 6;
		int r = i & 63;
		for(int j = 0; j <= 500; j++) ans[i] |= (D[j][k] >> r & 1);
		if(ans[i]) cnt++;
	}

	printf("%d\n", cnt);
	for(int i = 0; i < 512; i++) if(ans[i]) printf("%d ", i); puts("");

	return 0;
}