#include <bits/stdc++.h>

using namespace std;

int N, M, K;

vector<pair<int, string> > ans;

void solve() {
	for(int i = 1; i < N; i++) {
		if(K <= M - 1) { ans.push_back({K, "R"}); return; }
		ans.push_back({M - 1, "R"});
		K -= M - 1;
		if(K <= 3 * (M - 1)) {
			if(K / 3 > 0) ans.push_back({K / 3, "DUL"});
			K %= 3;
			if(K == 1) ans.push_back({1, "D"});
			if(K == 2) ans.push_back({1, "DU"});
			return;
		}
		ans.push_back({M - 1, "DUL"});
		K -= 3 * (M - 1);
		ans.push_back({1, "D"});
		K--;
		if(!K) return;
	}
	if(K <= M - 1) { ans.push_back({K, "R"}); return; }
	ans.push_back({M - 1, "R"});
	K -= M - 1;
	if(K <= M - 1) { ans.push_back({K, "L"}); return; }
	ans.push_back({M - 1, "L"});
	K -= M - 1;
	ans.push_back({K, "U"});
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	if(4 * N * M - 2 * M - 2 * N < K) { puts("NO"); return 0; }
	puts("YES");

	solve();

	int cnt = 0;
	for(auto i : ans) if(i.first > 0) cnt++;
	printf("%d\n", cnt);
	for(auto i : ans) { if(i.first > 0) { cout << i.first << " " << i.second; puts(""); } }

	return 0;
}