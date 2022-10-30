// @betaveros :: generated with cpp2.hs
#include <cstdio>
using namespace std;
long long _mod(long long x, long long m) { long long r = x % m; return r < 0 ? r + m : r; }
long long _mod1(long long a) { return _mod(a, 1000000007); }
long long _mtimes(long long a, long long b) { return _mod1(a * b); }
int n;
int b[508];
long long idp[508][508];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){ scanf("%d", &b[i]); }
	if (b[0] != 1){
		printf("0\n");
		return 0;
	}
	for (int i = 0; i <= n; ++i){ idp[i][i] = 1; }
	for (int len = 1; len < n; ++len){
		for (int i = 1; i <= n - len; ++i){
			long long x = idp[i+1][i+len];
			for (int j = i + 1; j < i + len; ++j){
				if (b[j] > b[i]) x = _mod1(x + (idp[i+1][j] * idp[j][i+len]));
			}
			idp[i][i + len] = x;
		}
	}
	printf("%I64d\n", idp[1][n]);
}