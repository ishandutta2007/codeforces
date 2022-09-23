#include <bits/stdc++.h>

using namespace std;

int N;
int A[2020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		bool ok = false;
		for(int i = 1; i < N; i++) {
			int x = 0;
			for(int j = 1; j <= i; j++) x ^= A[j];
			int t = 0;
			int l = i + 1;
			for(int j = i + 1; j <= N; j++) {
				t ^= A[j];
				if(t == x) { l = j + 1; t = 0; }
			}
			t = 0;
			for(int j = l; j <= N; j++) t ^= A[j];
			if(l > i + 1 && !t) { ok = true; break; }
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}