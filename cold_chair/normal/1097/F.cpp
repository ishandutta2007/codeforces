#include<bitset>
#include<cstdio>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

int n, q, op, x, y, z;
bitset<7001> b[7001], a[100001], c[7001];
int bz[7001], p[7001], mu[7001];

void sieve(int n) {
	fo(i, 2, n) {
		if(!bz[i]) p[++ p[0]] = i, mu[i] = -1;
		for(int j = 1; i * p[j] <= n; j ++) {
			int k = i * p[j]; bz[k] = 1;
			if(i % p[j] == 0) {mu[k] = 0; break;}
			mu[k] = -mu[i];
		}
	}
}

int main() {
	sieve(7000);
	mu[1] = 1;
	fo(i, 1, 7000) fo(j, 1, 7000 / i) b[i * j][i] = 1;
	fo(i, 1, 7000) fo(j, 1, 7000 / i) c[i][i * j] = mu[j] != 0;
	scanf("%d %d" , &n, &q);
	fo(i, 1, q) {
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d %d", &x, &y);
			a[x] = b[y];
		} else
		if(op == 2) {
			scanf("%d %d %d", &x, &y, &z);
			a[x] = a[y] ^ a[z];
		} else
		if(op == 3) {
			scanf("%d %d %d", &x, &y, &z);
			a[x] = a[y] & a[z];
		} else {
			scanf("%d %d", &x, &y);
			printf("%d", (a[x] & c[y]).count() & 1);
		}
	}
}