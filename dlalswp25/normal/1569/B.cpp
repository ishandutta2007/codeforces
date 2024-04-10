#include <bits/stdc++.h>

using namespace std;

int N;
char A[55];
char ans[55][55];

void win(int a, int b) {
	ans[a][b] = '+';
	ans[b][a] = '-';
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		vector<int> v;
		for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) {
			ans[i][j] = (i == j ? 'X' : '=');
		}
		for(int i = 1; i <= N; i++) {
			if(A[i] == '2') v.push_back(i);
		}
		if(v.size() && v.size() <= 2) { puts("NO"); continue; }

		int sz = v.size();
		for(int i = 0; i < sz; i++) {
			win(v[i], v[(i + 1) % sz]);
		}

		puts("YES");
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) printf("%c", ans[i][j]); puts("");
		}
	}
	return 0;
}