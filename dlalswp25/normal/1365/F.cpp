#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

vector<pii> va, vb;
int A[505];
int B[505];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		va.clear(); vb.clear();
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);

		if(N & 1) {
			if(A[(N + 1) / 2] != B[(N + 1) / 2]) {
				puts("No");
				continue;
			}
		}

		for(int i = 1; i <= N / 2; i++) {
			int a = A[i], b = A[N - i + 1];
			if(a > b) swap(a, b);
			va.push_back({a, b});

			a = B[i]; b = B[N - i + 1];
			if(a > b) swap(a, b);
			vb.push_back({a, b});
		}

		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());

		bool ok = true;
		for(int i = 0; i < va.size(); i++) {
			if(va[i] != vb[i]) ok = false;
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}