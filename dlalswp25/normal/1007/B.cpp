#include <stdio.h>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int div(int x) {
	int ret = 0, sq = 0;
	for(int i = 1; i * i <= x; i++) {
		if(x % i == 0) ret++;
		if(i * i == x) sq = 1;
	}
	ret = ret * 2 - sq;
	return ret;
}
int d[8];

int calc(int x, int y, int z) {
	bool possible = false;
	if((x & 1) && (y & 2) && (z & 4)) possible = true;
	if((x & 1) && (z & 2) && (y & 4)) possible = true;
	if((y & 1) && (z & 2) && (x & 4)) possible = true;
	if((y & 1) && (x & 2) && (z & 4)) possible = true;
	if((z & 1) && (x & 2) && (y & 4)) possible = true;
	if((z & 1) && (y & 2) && (x & 4)) possible = true;

	if(!possible) return 0;
	if(x == y && y == z) return (d[x] + 2) * (d[x] + 1) * d[x] / 6;
	if(x == y) return d[z] * (d[x] + 1) * d[x] / 2;
	if(y == z) return d[x] * (d[y] + 1) * d[y] / 2;
	if(z == x) return d[y] * (d[z] + 1) * d[z] / 2;
	return d[x] * d[y] * d[z];
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int A, B, C; scanf("%d%d%d", &A, &B, &C);
		d[7] = div(gcd(gcd(A, B), C));
		d[3] = div(gcd(A, B)) - d[7];
		d[5] = div(gcd(C, A)) - d[7];
		d[6] = div(gcd(B, C)) - d[7];
		d[1] = div(A) - d[3] - d[5] - d[7];
		d[2] = div(B) - d[3] - d[6] - d[7];
		d[4] = div(C) - d[5] - d[6] - d[7];

		long long ans = 0;
		//for(int i = 1; i <= 7; i++) printf("%d ", d[i]); puts("");

		for(int i = 1; i <= 7; i++) {
			for(int j = i; j <= 7; j++) {
				for(int k = j; k <= 7; k++) {
					ans += calc(i, j, k);
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}