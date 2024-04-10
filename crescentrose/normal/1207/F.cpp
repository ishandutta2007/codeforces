#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int S = 700;
long long g[S][S];
long long a[1000000];
int n;
int main(){
	scanf("%d", &n);
	while (n -- ){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (x == 1) {
			a[y] += z;
			for (int i = 1; i < S;  i ++)
			{
				g[i][y % i] += z;
			}
		} else {
			if (y >= S) {
				long long ans = 0;
				for (int i = 0; i * y + z <= 500000; i++) {
					if (i * y + z == 0) continue;
					ans += a[i * y + z];
				}
				printf("%lld\n", ans);
			} else {
				printf("%lld\n", g[y][z]);
			}
		}
	}
	return 0;
}