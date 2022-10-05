#include <bits/stdc++.h>

using namespace std;

int N;
char A[202020];
int nxt[202020];
int cnt[10];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		nxt[N] = N + 1;
		int mn = A[N], mni = N;
		for(int i = N - 1; i >= 1; i--) {
			nxt[i] = mni;
			if(mn >= A[i]) { mn = A[i]; mni = i; }
		}
		nxt[0] = mni;
		for(int i = 0; i < 10; i++) cnt[i] = 0;
		int p = 0;
		while(p <= N) {
			for(int i = p + 1; i < nxt[p]; i++) cnt[min(9, A[i] - '0' + 1)]++;
			p = nxt[p];
			if(p <= N) cnt[A[p] - '0']++;
		}
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < cnt[i]; j++) printf("%d", i);
		}
		puts("");
	}
	return 0;
}