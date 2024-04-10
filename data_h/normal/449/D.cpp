#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = (1 << 20) + 10;
const int MOD = 1000000007;
int f[N];
int p[N];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		f[a]++;
	}
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < (1 << 20); j++) {
			if (j & (1 << i)) {
				f[j ^ (1 << i)] += f[j];
			}
		}
	p[0] = 1;
	for(int i = 1; i <= (1 << 20); i++) {
		p[i] = p[i - 1] * 2 % MOD;
	}
	for(int i = 0; i < (1 << 20); i++) {
		f[i] = p[f[i]];
	}
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < (1 << 20); j++) {
			if (j & (1 << i)) {
				(f[j ^ (1 << i)] += MOD - f[j]) %= MOD;
			}
		}
	}
	printf("%d\n", f[0]);
	return 0;
}