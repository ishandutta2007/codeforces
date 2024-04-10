#include <bits/stdc++.h>

using namespace std;

int a[2];

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		a[x & 1]++;
	}
	printf("%d\n", min(a[0], a[1]));
	return 0;
}