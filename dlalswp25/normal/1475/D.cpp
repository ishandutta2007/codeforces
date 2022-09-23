#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
pii A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i].second);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i].first);
		sort(A + 1, A + N + 1);
		int p = 1;
		while(p <= N && A[p].first == 1) p++;
		p--;
		if(p == N || p < 1) {
			int ans = 0;
			for(int i = N; i >= 1; i--) {
				M -= A[i].second; ans += A[i].first;
				if(M <= 0) break;
			}
			if(M > 0) puts("-1");
			else printf("%d\n", ans);
			continue;
		}
		int q = N;
		int ans = 0;
		while(M > 0) {
			if(!p && A[q].first == 1) break;
			if(p >= 1 && M <= A[p].second) {
				ans++; M -= A[p].second; break;
			}
			if(p <= 1) {
				if(A[q].first == 2) { ans += 2; M -= A[q].second; q--; }
				else { ans++; M -= A[p].second; p--; }
			}
			else if(A[q].first == 1) {
				ans++; M -= A[p].second; p--;
			}
			else if(A[q].second < A[p].second + A[p - 1].second) {
				ans++; M -= A[p].second; p--;
			}
			else {
				ans += 2; M -= A[q].second; q--;
			}
		}
		if(M > 0) puts("-1");
		else printf("%d\n", ans);
	}
	return 0;
}