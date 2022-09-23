#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N[3];
int A[3][303030];
ll S[3];
ll tot;

int main() {
	scanf("%d%d%d", &N[0], &N[1], &N[2]);
	for(int i = 0; i < 3; i++) {
		for(int j = 1; j <= N[i]; j++) {
			scanf("%d", &A[i][j]);
			S[i] += A[i][j];
			tot += A[i][j];
		}
		sort(A[i] + 1, A[i] + N[i] + 1);
	}

	ll mn = min(S[0], min(S[1], S[2]));
	mn = min(mn, (ll)A[0][1] + A[1][1]);
	mn = min(mn, (ll)A[1][1] + A[2][1]);
	mn = min(mn, (ll)A[2][1] + A[0][1]);

	printf("%lld\n", tot - 2 * mn);

	return 0;
}