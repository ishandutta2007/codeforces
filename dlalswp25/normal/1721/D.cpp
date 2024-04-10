#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
int B[101010];
int tA[101010];
int tB[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		int ans = 0;
		vector<int> V;
		V.push_back(N);
		for(int i = 29; i >= 0; i--) {
			bool ok = true;
			int bef = 0;
			for(int j : V) {
				int cA[2] = {0, 0};
				int cB[2] = {0, 0};
				for(int k = bef + 1; k <= j; k++) {
					cA[A[k] >> i & 1]++;
				}
				for(int k = bef + 1; k <= j; k++) {
					cB[B[k] >> i & 1]++;
				}
				if(cA[0] != cB[1]) ok = false;
				bef = j;
			}
			if(ok) {
				ans |= 1 << i;
				vector<int> U;
				bef = 0;
				for(int j : V) {
					int p = bef;
					for(int k = bef + 1; k <= j; k++) {
						if(~A[k] >> i & 1) tA[++p] = A[k];
					}
					if(!U.size() || U.back() != p) U.push_back(p);
					for(int k = bef + 1; k <= j; k++) {
						if(A[k] >> i & 1) tA[++p] = A[k];
					}
					if(!U.size() || U.back() != p) U.push_back(p);

					p = bef;
					for(int k = bef + 1; k <= j; k++) {
						if(B[k] >> i & 1) tB[++p] = B[k];
					}
					for(int k = bef + 1; k <= j; k++) {
						if(~B[k] >> i & 1) tB[++p] = B[k];
					}
					bef = j;
				}
				swap(V, U);
				for(int j = 1; j <= N; j++) {
					A[j] = tA[j];
					B[j] = tB[j];
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}