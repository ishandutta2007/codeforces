#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int A[105];
int B[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &K, &N, &M);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= M; i++) scanf("%d", &B[i]);
		int pa = 1, pb = 1;
		vector<int> ans;
		while(1) {
			if(pa <= N && A[pa] <= K) {
				if(!A[pa]) K++;
				ans.push_back(A[pa]);
				pa++;
				continue;
			}
			else if(pb <= M && B[pb] <= K) {
				if(!B[pb]) K++;
				ans.push_back(B[pb]);
				pb++;
				continue;
			}
			else break;
		}
		if(ans.size() < N + M) puts("-1");
		else {
			for(int i : ans) printf("%d ", i); puts("");
		}
	}
	return 0;
}