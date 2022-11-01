#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1111;
const int LIMIT = 10000;
const int MOD = 1000000007;

using namespace std;


int n, ans, f[N][LIMIT * 2 + 10];

int main() {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		for (int j = -LIMIT; j <= LIMIT; j++) {
			if (j - x >= -LIMIT)
				(f[i][j + LIMIT] += f[i - 1][j - x + LIMIT]) %= MOD;
			if (j + x <= LIMIT)
				(f[i][j + LIMIT] += f[i - 1][j + x + LIMIT]) %= MOD;
		}
		
		(++f[i][LIMIT - x]) %= MOD;
		(++f[i][LIMIT + x]) %= MOD;
		
		(ans += f[i][LIMIT]) %= MOD;
	}
	
	printf("%d\n", ans);
	return 0;
}