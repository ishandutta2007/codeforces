#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

const int N = 1e5 + 7;

int n;

int main() {
	scanf("%d", &n);
	printf("YES\n");
	for (int i = 1; i <= n; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int ans = 0;
		if (a & 1) {
			ans ^= 1;
		}
		if (b & 1) {
			ans ^= 2;
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}