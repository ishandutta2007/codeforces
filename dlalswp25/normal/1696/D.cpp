#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[252525];
int D[252525];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);	
		for(int i = 1; i <= N; i++) D[i] = 0;
		vector<pii> L, U;
		L.emplace_back(0, N + 1);
		L.emplace_back(A[N], N);
		U.emplace_back(N + 1, N + 1);
		U.emplace_back(A[N], N);
		for(int i = N - 1; i >= 1; i--) {
			while(L.size() && L.back().first > A[i]) L.pop_back();
			while(U.size() && U.back().first < A[i]) U.pop_back();
			if(A[i] < A[i + 1]) {
				int t = L.back().second - 1;
				int l = 1, r = (int)U.size() - 1;
				while(l <= r) {
					int m = l + r >> 1;
					if(U[m].second > t) l = m + 1;
					else r = m - 1;
				}
				// l
				D[i] = D[U[l].second] + 1;
			}
			else {
				int t = U.back().second - 1;
				int l = 1, r = (int)L.size() - 1;
				while(l <= r) {
					int m = l + r >> 1;
					if(L[m].second > t) l = m + 1;
					else r = m - 1;
				}
				// l
				D[i] = D[L[l].second] + 1;
			}
			L.emplace_back(A[i], i);
			U.emplace_back(A[i], i);
		}
		printf("%d\n", D[1]);
	}
	return 0;
}