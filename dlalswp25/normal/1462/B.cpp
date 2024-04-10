#include <bits/stdc++.h>

using namespace std;

char A[205];
int N;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A);
		int l = 0, r = 0;
		for(int i = 0; i < 4; i++) {
			if(A[i] - '0' == !(i % 2) * 2) l++;
			else break;
		}
		for(int i = N - 1; i >= N - 4; i--) {
			if(A[i] - '0' == !((N - i) % 2) * 2) r++;
			else break;
		}
		puts(l + r >= 4 ? "YES" : "NO");
	}
	return 0;
}