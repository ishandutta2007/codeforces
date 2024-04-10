#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 100 + 5;
const int INF = 1111111;

int f[N][1 << 17], pre[N][1 << 17];
int domain[N], n, m, a[N];

vector<int> primes;

int isPrime(int x) {
	for(int i = 2; i < x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

void print(int n, int k) {
	if (n == 0) {
		return ;
	}
	int d = pre[n][k];
	print(n - 1, k ^ domain[d]);
	printf("%d ", d);
}

int main() {
	for(int i = 2; i < 59; i++) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}
	m = (int)primes.size();
	for(int i = 1; i < 59; i++) {
		for(int j = 0; j < m; j++) {
			if (i % primes[j] == 0) {
				domain[i] |= (1 << j);
			}
		}
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i <= n; i++)
		for(int j = 0; j < (1 << m); j++) {
			f[i][j] = INF;
		}
	f[0][0] = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < (1 << m); j++) 
			if (f[i][j] < INF) {
				for(int k = 1; k <= 2 * a[i + 1] - 1 && k < 59; k++) {
					if (domain[k] & j) {
						continue;
					}
					if (f[i + 1][j | domain[k]] > f[i][j] + abs(a[i + 1] - k)) {
						f[i + 1][j | domain[k]] = f[i][j] + abs(a[i + 1] - k);
						pre[i + 1][j | domain[k]] = k;
					}
				}
			}
	int ans = INF, pos;
	for(int j = 0; j < (1 << m); j++) {
		if (f[n][j] < ans) {
			ans = f[n][j];
			pos = j;
		}
	}
	print(n, pos);
	puts("");
	return 0;
}