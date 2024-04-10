#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> ans;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		ans.clear();
		while(1) {
			ll l = N;
			for(; l * l >= N; l--);
			l++;
			for(int i = l + 1; i < N; i++) ans.emplace_back(i, N);
			ans.emplace_back(N, l);
			ans.emplace_back(N, l);
			N = l;
			if(N <= 2) break;
		}
		printf("%d\n", ans.size());
		for(pii i : ans) printf("%d %d\n", i.first, i.second);
	}
	return 0;
}