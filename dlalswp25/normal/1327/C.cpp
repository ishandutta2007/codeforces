#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<char> ans;

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i < M; i++) ans.push_back('L');
	for(int i = 1; i < N; i++) ans.push_back('U');
	for(int i = 1; i <= N; i++) {
		if(i & 1) {
			for(int j = 1; j < M; j++) ans.push_back('R');
			if(i < N) ans.push_back('D');
		}
		else {
			for(int j = 1; j < M; j++) ans.push_back('L');
			if(i < N) ans.push_back('D');
		}
	}
	printf("%d\n", ans.size());
	for(auto i : ans) printf("%c", i); puts("");
	return 0;
}