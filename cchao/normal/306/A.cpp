#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		printf("%d%c", n / m + (i < n % m), " \n"[i == m - 1]);
	}
	return 0;
}