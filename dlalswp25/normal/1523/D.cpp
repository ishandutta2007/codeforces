#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int N, M, P;
char A[202020][65];
vector<int> V[202020];
int cnt[35353];
char ans[65];
int mx;

int rd() {
	return rng() % N + 1;
}

int main() {
	scanf("%d%d%d", &N, &M, &P);
	for(int i = 1; i <= N; i++) {
		scanf("%s", A[i] + 1);
		for(int j = 1; j <= M; j++) {
			if(A[i][j] == '1') V[i].push_back(j);
		}
	}

	int Z = (1 << P) - 1;

	for(int i = 1; i <= M; i++) ans[i] = '0';

	for(int z = 0; z < 30; z++) {
		int x = rd();
		if(V[x].size() == 0) continue;
		for(int i = 0; i < 1 << P; i++) cnt[i] = 0;
		for(int i = 1; i <= N; i++) {
			int b = 0;
			for(int j = 0; j < V[x].size(); j++) {
				if(A[i][V[x][j]] == '1') b ^= (1 << j);
			}
			cnt[b ^ Z]++;
		}

		for(int i = 0; i < P; i++) {
			for(int j = 0; j < 1 << P; j++) {
				if(j & 1 << i) cnt[j] += cnt[j ^ 1 << i];
			}
		}

		for(int i = 0; i < 1 << P; i++) {
			if(cnt[i] < (N + 1) / 2) continue;

			int bit = 0;

			for(int j = 0; j < V[x].size(); j++) {
				if(~i & 1 << j) bit++;
			}

			if(bit > mx) {
				int t = i ^ Z;
				for(int j = 1; j <= M; j++) ans[j] = '0';
				for(int j = 0; j < V[x].size(); j++) {
					if(t & 1 << j) ans[V[x][j]] = '1';
				}
				mx = bit;
			}
		}
	}

	printf("%s\n", ans + 1);
	return 0;
}