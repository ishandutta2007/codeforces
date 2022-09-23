#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[101010][10];
ll D[101010][131];

struct STR {
	int a;
	vector<int> s;

	bool operator< (const STR& o) const {
		return a < o.a;
	}
}B[101010];

int N, P, K;

int main() {
	scanf("%d%d%d", &N, &P, &K);
	for(int i = 1; i <= N; i++) scanf("%d", &B[i].a);
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < P; j++) {
			int x; scanf("%d", &x);
			B[i].s.push_back(x);
		}
	}

	sort(B + 1, B + N + 1);
	reverse(B + 1, B + N + 1);

	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < P; j++) A[i][j] = B[i].s[j];
		A[i][P] = B[i].a;
	}

	for(int i = 1; i < (1 << P); i++) D[0][i] = -(1LL << 60);

	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < (1 << P); j++) {
			int b = 0;
			for(int k = 0; k < P; k++) if(j & (1 << k)) b++;

			if(i - b <= K) D[i][j] = D[i - 1][j] + A[i][P];
			else D[i][j] = D[i - 1][j];

			for(int k = 0; k < P; k++) {
				if(!(j & (1 << k))) continue;
				D[i][j] = max(D[i][j], D[i - 1][j ^ (1 << k)] + A[i][k]);
			}
		}
	}

	// for(int i = 1; i <= N; i++) {
	// 	for(int j = 0; j < (1 << P); j++) {
	// 		printf("%lld ", D[i][j]);
	// 	}
	// 	puts("");
	// }

	printf("%lld\n", D[N][(1 << P) - 1]);

	return 0;
}