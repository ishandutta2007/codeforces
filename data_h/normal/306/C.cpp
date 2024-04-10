#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 4005;
const long long mod = 1000000009;

int n, w, b;

long long f[MAXN][MAXN], C[MAXN][MAXN];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d %d", &n, &w, &b);
	f[0][0] = 1;
	for(int i = 0; i <= 4000; i++)
		C[i][0] = 1;
	for(int i = 1; i <= 4000; i++)	
		for(int j = 1; j <= 4000; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	long long ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i + 2; j <= n; j++)
			if (i + (1 + n - j) <= w && j - i - 1 <= b)
			{
				int x = i + n - j + 1, y = n - x;
				ans += C[w - 1][x - 1] * C[b - 1][y - 1] % mod;
				ans %= mod;
			}
	for(int i = 1; i <= w; i++)
		ans = ans * i % mod;
	for(int i = 1; i <= b; i++)
		ans = ans * i % mod;
	printf("%I64d\n", ans);
	return 0;
}