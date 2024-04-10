#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[101010];
int C[101010];
int cnt[101010];
vector<pii> v;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		v.clear();
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) C[i] = 0;
		int mx = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			C[A[i]]++;
			mx = max(mx, C[A[i]]);
		}
		if(mx > (N - 1) / 2 + 1) { puts("-1"); continue; }

		for(int i = 1; i <= N; i++) cnt[i] = 0;
		int l = 1;

		int M = 0;
		for(int i = 2; i <= N; i++) {
			if(A[i] == A[i - 1]) {
				int c1 = A[l], c2 = A[i - 1];
				l = i;
				M++;
				if(c1 == c2) cnt[c1]++;
				else v.emplace_back(c1, c2);
			}
		}
		if(A[l] == A[N]) cnt[A[l]]++;
		else v.emplace_back(A[l], A[N]);

		mx = 0; int mxi = 1;
		int sm = 0;
		for(int i = 1; i <= N; i++) {
			if(cnt[i] > mx) { mx = cnt[i]; mxi = i; }
			sm += cnt[i];
		}
		sm -= mx;

		if(mx <= sm + 1) { printf("%d\n", M); continue; }
		int d1 = 0, d2 = 0;
		for(pii i : v) {
			if(i.first == mxi || i.second == mxi) d1++;
			else d2++;
		}

		if(mx <= sm + d2 + 1) { printf("%d\n", M); continue; }
		mx -= (sm + d2 + 1);
		printf("%d\n", M + mx);
	}
	return 0;
}