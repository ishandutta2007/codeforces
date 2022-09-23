#include <bits/stdc++.h>

using namespace std;

int N;
int A[1010101];
int B[1010101];

map<int, int> mp[2];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	int ans = 0;
	for(int i = 19; i >= 0; i--) {
		int s = 0;
		mp[0].clear(); mp[1].clear();
		for(int j = 1; j <= N; j++) {
			int t = A[j] >> i & 1;
			s ^= t;
			B[j] = B[j] << 1 | s;
		}

		mp[0][0] = 0;

		for(int j = 1; j <= N; j++) {
			if(A[j] >> i & 1) {
				auto it = mp[j & 1].find(B[j]);
				if(it != mp[j & 1].end()) ans = max(ans, j - it -> second);
				else mp[j & 1][B[j]] = j;
			}
			else {
				mp[0].clear(); mp[1].clear();
				mp[j & 1][B[j]] = j;
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}