#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
pii A[2020];
pii B[2020];
vector<pii> V;

vector<int> evt[1010101];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d", &A[i].first, &A[i].second);
	}

	for(int i = 1; i <= M; i++) {
		scanf("%d%d", &B[i].first, &B[i].second);
	}
	sort(B + 1, B + M + 1);
	for(int i = 1; i <= M; i++) {
		while(V.size() && V.back().second <= B[i].second) V.pop_back();
		V.push_back(B[i]);
	}

	M = V.size();
	for(int i = 1; i <= M; i++) B[i] = V[i - 1];
	for(int i = 1; i <= N; i++) {
		int j = M;
		for(j = M; j >= 1; j--) {
			if(B[j].second >= A[i].second) break;
		}
		if(!j || B[j].first < A[i].first) continue;
		evt[0].push_back(B[j].first + 1 - A[i].first);
		for(; j >= 1; j--) {
			evt[B[j].second + 1 - A[i].second].push_back(-(B[j].first + 1 - A[i].first));
			if(B[j - 1].first < A[i].first) break;
			evt[B[j].second + 1 - A[i].second].push_back(B[j - 1].first + 1 - A[i].first);
		}
	}

	multiset<int> S;
	int ans = 1010101010;
	for(int i = 0; i <= 1000001; i++) {
		for(int j : evt[i]) {
			// printf("%d %d\n", i, j);
			if(j > 0) S.insert(j);
			else S.erase(S.find(-j));
		}
		if(S.size()) ans = min(ans, i + *S.rbegin());
		else ans = min(ans, i);
	}
	printf("%d\n", ans);

	return 0;
}