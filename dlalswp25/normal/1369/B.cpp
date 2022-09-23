#include <bits/stdc++.h>

using namespace std;

char A[101010];
int N;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		int i = 1;
		for(; i <= N; i++) {
			if(A[i] != '0') break;
			printf("%c", A[i]);
		}
		int j = N;
		int cnt = 0;
		for(; j >= 1; j--) {
			if(A[j] != '1') break;
			cnt++;
		}
		if(j > i) printf("0");
		for(int k = 0; k < cnt; k++) printf("1"); puts("");
	}
	return 0;
}