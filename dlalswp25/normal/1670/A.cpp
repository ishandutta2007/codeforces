#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int x = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			if(A[i] < 0) x++;
		}
		bool ok = true;
		for(int i = 1; i < x; i++) {
			if(abs(A[i]) < abs(A[i + 1])) ok = false;
		}
		for(int i = x + 1; i < N; i++) {
			if(abs(A[i]) > abs(A[i + 1])) ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}