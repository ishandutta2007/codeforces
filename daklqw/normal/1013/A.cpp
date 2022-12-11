#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1000010
int n, a[MAXN], b[MAXN], x, y;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]),x += a[i];
	for (int i = 1; i <= n; ++i) scanf("%d", &b[i]), y += b[i];
	puts(x >= y ? "Yes" : "No");
	return 0;
}