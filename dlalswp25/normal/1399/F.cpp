#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
int L[3030];
int R[3030];

int C[3030];
pii A[3030];
int D[6060];

vector<int> v;
vector<int> seg[6060];

int get(int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		v.clear();
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d%d", &L[i], &R[i]);
			v.push_back(L[i]);
			v.push_back(R[i]);
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		M = v.size();

		for(int i = 1; i <= M; i++) seg[i].clear();

		bool ok = false;
		for(int i = 1; i <= N; i++) {
			L[i] = get(L[i]);
			R[i] = get(R[i]);
			A[i] = {L[i], R[i]};
			if(L[i] == 1 && R[i] == M) ok = true;
		}

		if(!ok) { N++; A[N] = {1, M}; L[N] = 1; R[N] = M; }

		sort(A + 1, A + N + 1, [&](const pii& a, const pii& b) {
			return a.second - a.first < b.second - b.first;
		});

		for(int i = 1; i <= N; i++) {
			L[i] = A[i].first;
			R[i] = A[i].second;
			seg[R[i]].push_back(i);
		}

		// for(int i = 1; i <= N; i++) printf("%d %d\n", L[i], R[i]);

		for(int i = 1; i <= N; i++) C[i] = 0;
		for(int i = 1; i <= N; i++) {
			for(int j = L[i] - 1; j <= R[i]; j++) D[j] = 0;
			for(int j = L[i]; j <= R[i]; j++) {
				D[j] = D[j - 1];
				for(int k : seg[j]) {
					if(k == i || L[k] < L[i]) continue;
					D[j] = max(D[j], C[k] + D[L[k] - 1]);
				}
			}
			C[i] = D[R[i]] + 1;
			// printf("%d : %d\n", i, C[i]);
		}

		printf("%d\n", C[N] - (!ok));
	}
	return 0;
}