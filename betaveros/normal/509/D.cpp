// @betaveros :: generated with cpp2.hs
#include <algorithm>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long _mod(long long x, long long m) { long long r = x % m; return r < 0 ? r + m : r; }
long long gcd(long long a, long b) { return b == 0 ? a : gcd(b, a % b); }
int n, m;
long long modv = 0, maxv = 0;
long long a[108][108];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			scanf("%" PRId64 "", &a[i][j]);
			maxv = max(maxv, a[i][j]);
		}
	}
	for (int i = 0; i < n - 1; ++i){
		for (int j = 0; j < m; ++j){
			for (int jj = j + 1; jj < m; ++jj){
				modv = gcd(modv, abs(a[i][j] - a[i+1][j] - a[i][jj] + a[i+1][jj]));
			}
		}
	}
	if (modv && maxv >= modv) {
		printf("NO\n");
	} else {
		printf("YES\n");
		if (!modv) modv = maxv + 1;
		printf("%" PRId64 "\n", modv);
		for (int i = 0; i < n; ++i){
			if (i) printf(" ");
			printf("%" PRId64 "", a[i][0]);
		}
		printf("\n");
		for (int j = 0; j < m; ++j){
			if (j) printf(" ");
			long long r = (_mod(a[0][j] - a[0][0], modv));
			printf("%" PRId64 "", r);
		}
		printf("\n");
	}
}