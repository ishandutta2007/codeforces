#include <bits/stdc++.h>

using namespace std;

int N;
char A[505050];
int cnt[1010101];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		for(int i = 0; i <= 2 * N; i++) cnt[i] = 0;

		int t = N;
		for(int i = 1; i <= N; i++) {
			if(A[i] == '0') {
				cnt[t]++; t++;
			}
			else {
				t--; cnt[t]++;
			}
		}

		t = N;
		for(int i = 1; i <= N; i++) {
			if(!cnt[t] || (cnt[t] == 1 && cnt[t - 1])) {
				printf("1"); t--; cnt[t]--;
			}
			else {
				printf("0"); cnt[t]--; t++;
			}
		}
		puts("");
	}
	return 0;
}