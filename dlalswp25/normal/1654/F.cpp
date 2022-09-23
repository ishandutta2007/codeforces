#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
char A[262626];
vector<int> V[262626];
vector<pii> tmp[262626];

int main() {
	scanf("%d", &N); M = 1 << N;
	scanf("%s", A);
	for(int i = 0; i < M; i++) {
		V[i].push_back(A[i] - 'a');
	}

	for(int i = 1; i <= N; i++) {
		vector<pii> ps;
		for(int j = 0; j < M; j += 1 << i) {
			tmp[j].clear();
			for(int k = 0; k < 1 << i - 1; k++) {
				int x = V[j][k], y = V[j | 1 << i - 1][k];
				tmp[j].emplace_back(x, y);
				ps.emplace_back(x, y);
			}
			for(int k = 0; k < 1 << i - 1; k++) {
				int x = V[j | 1 << i - 1][k], y = V[j][k];
				tmp[j].emplace_back(x, y);
				ps.emplace_back(x, y);
			}
		}
		sort(ps.begin(), ps.end());
		ps.erase(unique(ps.begin(), ps.end()), ps.end());
		for(int j = 0; j < M; j += 1 << i) {
			V[j].clear();
			for(int k = 0; k < 1 << i; k++) {
				V[j].push_back(lower_bound(ps.begin(), ps.end(), tmp[j][k]) - ps.begin());
			}
		}
	}

	int x = 0;
	for(int i = 0; i < M; i++) {
		if(V[0][i] < V[0][x]) x = i;
	}
	for(int i = 0; i < M; i++) printf("%c", A[i ^ x]); puts("");
	return 0;
}