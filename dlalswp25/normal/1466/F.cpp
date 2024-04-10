#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N, M;
vector<int> A[505050];
bool chk[505050];
int p[505050];

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

bool unite(int a, int b) {
	a = par(a); b = par(b);
	if(a == b || chk[a] && chk[b]) return false;
	p[a] = b;
	chk[b] |= chk[a];
	return true;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		int k; scanf("%d", &k);
		for(int j = 0; j < k; j++) {
			int a; scanf("%d", &a);
			A[i].push_back(a);
		}
		sort(A[i].begin(), A[i].end());
	}

	for(int i = 1; i <= M; i++) p[i] = i;

	vector<int> ans;
	for(int i = 1; i <= N; i++) {
		if(A[i].size() == 1) {
			int x = A[i][0];
			x = par(x);
			if(chk[x]) continue;
			chk[x] = true;
			ans.push_back(i);
		}
		else {
			int x = A[i][0], y = A[i][1];
			if(unite(x, y)) ans.push_back(i);
		}
	}

	int t = ans.size();
	int b = 1;
	for(int i = 0; i < t; i++) b = b * 2 % MOD;
	printf("%d %d\n", b, t);
	for(int i : ans) printf("%d ", i); puts("");

	return 0;
}