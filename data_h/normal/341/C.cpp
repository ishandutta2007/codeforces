#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <string>

using namespace std;

const int MAXN = 3100;
const long long mod = 1000000007;
long long nn[MAXN], f[MAXN], C[MAXN][MAXN];
int a[MAXN], n, hash[MAXN];

int main() {
	scanf("%d", &n);
	for(int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
	nn[0] = 1;
	for(int i = 1; i <= n; i++)
		nn[i] = nn[i - 1] * i % mod;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			hash[j] = 0;
		for(int j = 1; j <= n; j++)
			if (a[j] != -1)
				hash[a[j]] = 1;
		int cnt = 0, cnt2 = 0;
		for(int j = 1; j <= n; j++) {
			if (hash[j] == 0 && a[j] == -1)
				cnt++;
			if (a[j] == -1)
				cnt2++;
		}
		if (cnt < i)
			continue;
		f[i] = C[cnt][i] * nn[cnt2 - i] % mod;
	}
	for(int i = n; i >= 0; i--)
		for(int j = n; j > i; j--) {
			f[i] -= C[j][i] * f[j];
			f[i] = (f[i] % mod + mod) % mod;
		}
	printf("%I64d\n", f[0]);
	return 0;
}