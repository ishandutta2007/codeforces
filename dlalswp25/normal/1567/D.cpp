#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int S, N; scanf("%d%d", &S, &N);
		vector<int> ans;

		int x = 1000000000;
		for(; x >= 1; x /= 10) {
			if(N == 1) { ans.push_back(S); break; }
			if(S < x) continue;
			if(S - x < N - 1) continue;
			S -= x; ans.push_back(x);
			N--; x *= 10;
		}

		for(int i : ans) printf("%d ", i); puts("");
	}
	return 0;
}