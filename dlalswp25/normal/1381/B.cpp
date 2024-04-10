#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int N;
int A[4040];
int pos[4040];
bool ok[4040];
bool D[2020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		v.clear();
		scanf("%d", &N);
		for(int i = 1; i <= 2 * N; i++) ok[i] = false;
		for(int i = 1; i <= 2 * N; i++) {
			scanf("%d", &A[i]);
			pos[A[i]] = i;
		}

		for(int i = 2 * N; i >= 1; i--) {
			if(ok[i]) continue;
			int cnt = 0;
			for(int j = pos[i]; j <= 2 * N; j++) {
				if(ok[A[j]]) break;
				ok[A[j]] = true;
				cnt++;
			}
			v.push_back(cnt);
		}

		// for(int i : v) printf("%d ", i); puts("");

		for(int i = 1; i <= N; i++) D[i] = false;
		D[0] = true;
		for(int i : v) {
			for(int j = N; j >= i; j--) {
				D[j] |= D[j - i];
			}
		}
		puts(D[N] ? "YES" : "NO");
	}
	return 0;
}