#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

int N[4];
int A[4][151515];

multiset<int> S[4];
multiset<ll> D;
ll X[151515];
ll Y[151515];

vector<int> L[4][151515];
vector<int> R[4][151515];

int main() {
	for(int i = 0; i < 4; i++) scanf("%d", &N[i]);
	for(int i = 0; i < 4; i++) {
		for(int j = 1; j <= N[i]; j++) {
			scanf("%d", &A[i][j]);
			S[i].insert(A[i][j]);
		}
	}

	for(int i = 0; i < 3; i++) {
		int m; scanf("%d", &m);
		for(int j = 0; j < m; j++) {
			int a, b; scanf("%d%d", &a, &b);
			R[i][a].push_back(b);
			L[i + 1][b].push_back(a);
		}
	}

	for(int i = 1; i <= N[1]; i++) {
		for(int j : L[1][i]) {
			S[0].erase(S[0].find(A[0][j]));
		}
		if(S[0].size()) X[i] = *S[0].begin() + A[1][i];
		else X[i] = INF;
		for(int j : L[1][i]) {
			S[0].insert(A[0][j]);
		}
	}

	for(int i = 1; i <= N[2]; i++) {
		for(int j : R[2][i]) {
			S[3].erase(S[3].find(A[3][j]));
		}
		if(S[3].size()) Y[i] = *S[3].begin() + A[2][i];
		else Y[i] = INF;
		for(int j : R[2][i]) {
			S[3].insert(A[3][j]);
		}
	}

	for(int i = 1; i <= N[1]; i++) D.insert(X[i]);

	ll ans = INF;
	for(int i = 1; i <= N[2]; i++) {
		for(int j : L[2][i]) {
			D.erase(D.find(X[j]));
		}
		if(D.size()) ans = min(ans, *D.begin() + Y[i]);
		for(int j : L[2][i]) {
			D.insert(X[j]);
		}
	}	

	if(ans == INF) puts("-1");
	else printf("%lld\n", ans);

	return 0;
}