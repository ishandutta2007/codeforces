#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>

#define foreach(e, x) for(__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)

using namespace std;


const int MOD = 1e9 + 7;
const int N = 5555;

#define left LEFT
#define right RIGHT

int n, a, b, k;
int f[N][N], sum[N];
int answer;

int main() {
	scanf("%d %d %d %d", &n, &a, &b, &k);
	f[0][a] = 1;
	for(int i = 1; i <= k; i++) {
		
		for(int j = 1; j <= n; j++) {
			sum[j] = (sum[j - 1] + f[i - 1][j]) % MOD;
		}
		int left, right;
		if (a > b) {
			right = n;
			for(int j = b + 1; j <= n; j++) {
				left = j - (j - b + 1) / 2 + 1;
				f[i][j] = sum[right] - sum[left - 1] - f[i - 1][j];
				f[i][j] = (f[i][j] % MOD + MOD) % MOD;
			}
		} else {
			left = 1;
			for(int j = b - 1; j >= 1; j--) {
				right = j + (b - j + 1) / 2 - 1;
				f[i][j] = sum[right] - sum[left - 1] - f[i - 1][j];
				f[i][j] = (f[i][j] % MOD + MOD) % MOD;
			}
		}
	}
	
	answer = 0;
	for(int i = 1; i <= n; i++) {
		(answer += f[k][i]) %= MOD;
	}
	
	printf("%d\n", answer);
	return 0;
}