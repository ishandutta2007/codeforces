#include <bits/stdc++.h>

using namespace std;

int a[3], b[3];

int main() {
	int N; scanf("%d", &N);
	for(int i = 0; i < 3; i++) scanf("%d", &a[i]);
	for(int i = 0; i < 3; i++) scanf("%d", &b[i]);
	int mx = 0;
	for(int i = 0; i < 3; i++) mx += min(b[i], a[(i + 2) % 3]);
	int mn = 0;
	for(int i = 0; i < 3; i++) {
		if(a[i] > b[i] + b[(i + 2) % 3]) {
			mn = a[i] - b[i] - b[(i + 2) % 3];
		}
	}
	printf("%d %d\n", mn, mx);
	return 0;
}