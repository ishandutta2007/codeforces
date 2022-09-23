#include <bits/stdc++.h>

using namespace std;

int N, T;
int A[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		int dig = N / 2;
		for(int i = 1; i <= dig; i++) {
			for(int j = 9; j >= 0; j--) {
				if(N < A[j]) continue;
				if((N - A[j]) / 2 >= (dig - i)) {
					N -= A[j];
					printf("%d", j);
					break;
				}
			}
		}
		puts("");
	}
	return 0;
}