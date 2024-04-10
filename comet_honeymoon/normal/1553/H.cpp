#include<bits/stdc++.h>
using namespace std;

int n, k;
const int maxn = 1 << 19;
const int inf = 0x3f3f3f3f;
int f[maxn], v0[maxn], v1[maxn];

int main() {
	scanf("%d%d", &n, &k);
	for (int x = 0; x < 1 << k; x++)
		f[x] = inf,
		v0[x] = inf, 
		v1[x] = -inf;
	while (n--) {
		int x; scanf("%d", &x);
		v0[x] = v1[x] = 0;
	}

	for (int i = 0; i < k; i++)
	for (int y = 0; y < 1 << k; y++) if ((y >> i) & 1) {
		int x = y ^ (1 << i);
		// printf("%d : %d %d\n", i, x, y);
		f[x] = f[y] = min(f[x], f[y]);
		f[x] = min(f[x], v0[y] - v1[x] + (1 << i));
		f[y] = min(f[y], v0[x] - v1[y] + (1 << i));
		int v0x = v0[x], v0y = v0[y], v1x = v1[x], v1y = v1[y];
		v0[x] = min(v0x, v0y + (1 << i));
		v0[y] = min(v0y, v0x + (1 << i));
		v1[x] = max(v1x, v1y + (1 << i));
		v1[y] = max(v1y, v1x + (1 << i));
	}

	for (int x = 0; x < 1 << k; x++) printf("%d ", f[x]);
}