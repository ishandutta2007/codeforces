#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define RD(x) scanf("%d", &x)
#define RDD(x, y) scanf("%d%d", &x, &y)
#define SZ(a) sizeof(a)

int f(int a, int b, int c, int d) {
	if(a > b) swap(a, b);
	if(c > d) swap(c, d);
	if(b > c && b < d && a < c) return 1;
	if(d > a && d < b && c < a) return 1;
	return 0;
}

const int maxn = 1010;
int a[maxn];
int main() {
	int n, ans = 0; RD(n);
	FOR(i, n) RD(a[i]);
	FOR(i, n - 1) {
		FOR(j, n-1) {
			if(i == j) continue;
			if(f(a[i], a[i+1], a[j], a[j+1])) {
				//printf("inter %d %d, %d %d %d %d\n", i, j, a[i], a[i+1], a[j], a[j+1]);
				ans = 1;
			}
		}
	}
	puts(ans ? "yes" : "no");
	return 0;
}