#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int B[202020];
int cnt[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) cnt[i] = 0;
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		int p = N;
		bool ok = true;
		for(int i = N; i >= 1; i--) {
			if(A[p] == B[i]) { p--; continue; }
			if(i < N && B[i] == B[i + 1]) {
				cnt[B[i]]++;
			}
			else if(cnt[A[p]]) {
				cnt[A[p]]--;
				p--; i++;
			}
			else { ok = false; break; }
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}