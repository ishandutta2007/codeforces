#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		set<int> S;
		set<int>::iterator it;

		bool ok = true;
		for(int i = 1; i <= N; i++) {
			S.insert(A[i]);
			if(i > 1) {
				int cnt = 0;
				while(*it < A[i]) { it++; cnt++; }
				while(*it > A[i]) { it--; cnt++; }
				if(cnt >= 2) { ok = false; break; }
			}
			else it = S.begin();
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}