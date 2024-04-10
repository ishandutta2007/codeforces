#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;

int N, M, K;
int A[50505];
int B[50505];

vector<pil> f(int n, int* A) {
	vector<pil> ret;
	for(int i = 1; i <= n; i++) {
		int t = A[i];
		ll c = 1;
		while(t % M == 0) {
			c *= M;
			t /= M;
		}
		if(ret.size() && ret.back().first == t) {
			ret.back().second += c;
		}
		else ret.emplace_back(t, c);
	}
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		scanf("%d", &K);
		for(int i = 1; i <= K; i++) scanf("%d", &B[i]);
		vector<pil> VA = f(N, A);
		vector<pil> VB = f(K, B);
		if(VA.size() != VB.size()) { puts("No"); continue; }
		bool ok = true;
		for(int i = 0; i < VA.size(); i++) if(VA[i] != VB[i]) ok = false;
		puts(ok ? "Yes" : "No");
	}
	return 0;
}