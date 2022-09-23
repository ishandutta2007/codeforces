#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 998244353;

int N;

int A[1212121];
int B[1212121];

int p[1515];
int ed[1515];
int sz[1515];
ll D[1515][1515];

int par(int x) {
	if(p[x] == x) return x;
	return p[x] = par(p[x]);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			int x; scanf("%d", &x);
			if(i < j) {
				A[x] = i; B[x] = j;
			}
		}
	}

	for(int i = 1; i <= N; i++) { p[i] = i; ed[i] = 0; sz[i] = 1; D[i][1] = 1; }
	
	for(int i = 1; i <= N * (N - 1) / 2; i++) {
		int a = par(A[i]), b = par(B[i]);
		if(a == b) {
			ed[a]++;
			if(ed[a] == sz[a] * (sz[a] - 1) / 2) D[a][1] = 1;
		}
		else {
			ll tmp[1515] = {0, };
			for(int j = 0; j <= sz[a]; j++) {
				for(int k = 0; k <= sz[b]; k++) {
					tmp[j + k] = (tmp[j + k] + D[a][j] * D[b][k]) % MOD;
				}
			}
			for(int j = 0; j <= sz[a] + sz[b]; j++) D[a][j] = tmp[j];
			p[b] = a; sz[a] += sz[b]; ed[a] += ed[b] + 1;
			if(ed[a] == sz[a] * (sz[a] - 1) / 2) D[a][1] = 1;
			// printf("%d\n", a);
			// for(int j = 0; j <= sz[a]; j++) printf("%d ", D[a][j]); puts("");
		}
	}

	int x = par(1);
	for(int i = 1; i <= N; i++) printf("%lld ", D[x][i]); puts("");
	
	return 0;
}