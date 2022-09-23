#include <bits/stdc++.h>

using namespace std;

int N, K;
char A[101010];
vector<int> v;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		scanf("%s", A + 1);
		int l = 0;
		int ans = 0;
		v.clear();
		for(int i = 1; i <= N; i++) l += (A[i] == 'L');

		for(int i = 1; i <= N; i++) {
			if(A[i] == 'W') {
				ans++;
				if(A[i - 1] == 'W') ans++;
			}
		}

		K = min(K, l);
		int c = 0;

		if(l == N) {
			printf("%d\n", max(0, 2 * K - 1));
			continue;
		}

		bool chk = false;
		for(int i = 1; i <= N; i++) {
			if(A[i] == 'W') {
				if(c && chk) v.push_back(c);
				c = 0; chk = true;
			}
			else c++;
		}

		sort(v.begin(), v.end());
		// for(int i : v) printf("%d ", i); puts("");
		ans += 2 * K;
		int t = 0;
		for(int i : v) {
			if(t + i > K) break;
			ans++; t += i;
		}
		printf("%d\n", ans);
	}
	return 0;
}